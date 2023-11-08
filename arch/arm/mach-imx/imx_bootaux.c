// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2016 Freescale Semiconductor, Inc.
 */

#include <common.h>
#include <log.h>
#include <asm/io.h>
#include <asm/mach-imx/sys_proto.h>
#include <command.h>
#include <elf.h>
#include <imx_sip.h>
#include <linux/arm-smccc.h>
#include <linux/compiler.h>
#include <cpu_func.h>

#ifndef CONFIG_IMX8
#ifndef CONFIG_IMX8M
const __weak struct rproc_att hostmap[] = { };

static const struct rproc_att *get_host_mapping(unsigned long auxcore)
{
	const struct rproc_att *mmap = hostmap;

	while (mmap && mmap->size) {
		if (mmap->da <= auxcore &&
		    mmap->da + mmap->size > auxcore)
			return mmap;
		mmap++;
	}

	return NULL;
}

/*
 * A very simple elf loader for the auxilary core, assumes the image
 * is valid, returns the entry point address.
 * Translates load addresses in the elf file to the U-Boot address space.
 */
static unsigned long load_elf_image_m_core_phdr(unsigned long addr)
{
	Elf32_Ehdr *ehdr; /* ELF header structure pointer */
	Elf32_Phdr *phdr; /* Program header structure pointer */
	int i;

	ehdr = (Elf32_Ehdr *)addr;
	phdr = (Elf32_Phdr *)(addr + ehdr->e_phoff);

	/* Load each program header */
	for (i = 0; i < ehdr->e_phnum; ++i, ++phdr) {
		const struct rproc_att *mmap = get_host_mapping(phdr->p_paddr);
		void *dst, *src;

		if (phdr->p_type != PT_LOAD)
			continue;

		if (!mmap) {
			printf("Invalid aux core address: %08x",
			       phdr->p_paddr);
			return 0;
		}

		dst = (void *)(phdr->p_paddr - mmap->da) + mmap->sa;
		src = (void *)addr + phdr->p_offset;

		debug("Loading phdr %i to 0x%p (%i bytes)\n",
		      i, dst, phdr->p_filesz);

		if (phdr->p_filesz)
			memcpy(dst, src, phdr->p_filesz);
		if (phdr->p_filesz != phdr->p_memsz)
			memset(dst + phdr->p_filesz, 0x00,
			       phdr->p_memsz - phdr->p_filesz);
		flush_cache((unsigned long)dst &
			    ~(CONFIG_SYS_CACHELINE_SIZE - 1),
			    ALIGN(phdr->p_filesz, CONFIG_SYS_CACHELINE_SIZE));
	}

	return ehdr->e_entry;
}
#endif

int arch_auxiliary_core_up(u32 core_id, ulong addr)
{
	u32 stack, pc;

	if (!addr)
		return -EINVAL;

#if defined(CONFIG_IMX8M)
	stack = *(u32 *)addr;
	pc = *(u32 *)(addr + 4);
#else
	/*
	 * handling ELF64 binaries
	 * isn't supported yet.
	 */
	if (valid_elf_image(addr)) {
		stack = 0x0;
		pc = load_elf_image_m_core_phdr(addr);
		if (!pc)
			return CMD_RET_FAILURE;

	} else {
		/*
		 * Assume binary file with vector table at the beginning.
		 * Cortex-M4 vector tables start with the stack pointer (SP)
		 * and reset vector (initial PC).
		 */
		stack = *(u32 *)addr;
		pc = *(u32 *)(addr + 4);
	}
#endif
	printf("## Starting auxiliary core stack = 0x%08X, pc = 0x%08X...\n",
	       stack, pc);

#ifdef CONFIG_MX7ULP
	writel(pc, SIM0_RBASE + 0x70); /* GP7 */
#else
	/* Set the stack and pc to MCU bootROM */
	writel(stack, MCU_BOOTROM_BASE_ADDR);
	writel(pc, MCU_BOOTROM_BASE_ADDR + 4);

	flush_dcache_all();

	/* Enable MCU */
#ifdef CONFIG_IMX8M
	arm_smccc_smc(IMX_SIP_SRC, IMX_SIP_SRC_MCU_START, 0, 0,
		      0, 0, 0, 0, NULL);
#else
	clrsetbits_le32(SRC_BASE_ADDR + SRC_M4_REG_OFFSET,
			SRC_M4C_NON_SCLR_RST_MASK, SRC_M4_ENABLE_MASK);
#endif /*CONFIG_IMX8M */
#endif /* CONFIG_MX7ULP */

	return 0;
}

int arch_auxiliary_core_check_up(u32 core_id)
{
#ifdef CONFIG_IMX8M
	struct arm_smccc_res res;

	arm_smccc_smc(IMX_SIP_SRC, IMX_SIP_SRC_MCU_STARTED, 0, 0,
		      0, 0, 0, 0, &res);

	return res.a0;
#elif defined(CONFIG_MX7ULP)
	/* Only one core need to be considered */
	/* As this is the master core, it can't do reset from A7 side */
	return (0 == core_id) ? 0 : 1;
#else
	unsigned int val;

	val = readl(SRC_BASE_ADDR + SRC_M4_REG_OFFSET);

	if (val & SRC_M4C_NON_SCLR_RST_MASK)
		return 0;  /* assert in reset */

	return 1;
#endif
}
#endif
/*
 * To i.MX6SX and i.MX7D, the image supported by bootaux needs
 * the reset vector at the head for the image, with SP and PC
 * as the first two words.
 *
 * Per the cortex-M reference manual, the reset vector of M4/M7 needs
 * to exist at 0x0 (TCMUL/IDTCM). The PC and SP are the first two addresses
 * of that vector.  So to boot M4/M7, the A core must build the M4/M7's reset
 * vector with getting the PC and SP from image and filling them to
 * TCMUL/IDTCM. When M4/M7 is kicked, it will load the PC and SP by itself.
 * The TCMUL/IDTCM is mapped to (MCU_BOOTROM_BASE_ADDR) at A core side for
 * accessing the M4/M7 TCMUL/IDTCM.
 */
static int do_bootaux(struct cmd_tbl *cmdtp, int flag, int argc,
		      char *const argv[])
{
	ulong addr;
	int ret, up;
	u32 core = 0;

	if (argc < 2)
		return CMD_RET_USAGE;

	if (argc > 2)
		core = simple_strtoul(argv[2], NULL, 10);

	up = arch_auxiliary_core_check_up(core);
	if (up) {
		printf("## Auxiliary core is already up\n");
		return CMD_RET_SUCCESS;
	}

	addr = hextoul(argv[1], NULL);

	if (!addr)
		return CMD_RET_FAILURE;

	ret = arch_auxiliary_core_up(core, addr);
	if (ret)
		return CMD_RET_FAILURE;

	return CMD_RET_SUCCESS;
}

U_BOOT_CMD(
	bootaux, CONFIG_SYS_MAXARGS, 1,	do_bootaux,
	"Start auxiliary core",
	"<address> [<core>]\n"
	"   - start auxiliary core [<core>] (default 0),\n"
	"     at address <address>\n"
);
