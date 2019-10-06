/*
	mini - a Free Software replacement for the Nintendo/BroadOn IOS.
	Hollywood register definitions

Copyright (C) 2008, 2009	Haxx Enterprises <bushing@gmail.com>
Copyright (C) 2008, 2009	Sven Peter <svenpeter@gmail.com>
Copyright (C) 2008, 2009	Hector Martin "marcan" <marcan@marcansoft.com>
Copyright (C) 2008, 2009	John Kelley <wiidev@kelley.ca>

# This code is licensed to you under the terms of the GNU GPL, version 2;
# see file COPYING or http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
*/

#ifndef __HOLLYWOOD_H__
#define __HOLLYWOOD_H__

/* ----------------------------------------------------------------------------
 * Hollywood register space */
#define		HW_REG_BASE		0x0d800000

// ----------------------------
// IPC registers

// The PPC can only see the first three IPC registers
#define		HW_IPC_PPCMSG		(HW_REG_BASE + 0x000)
#define		HW_IPC_PPCCTRL		(HW_REG_BASE + 0x004)
#define		HW_IPC_ARMMSG		(HW_REG_BASE + 0x008)
#define		HW_IPC_ARMCTRL		(HW_REG_BASE + 0x00c)
#define		  IPC_CTRL_Y1		0x01
#define		  IPC_CTRL_X2		0x02
#define		  IPC_CTRL_X1		0x04
#define		  IPC_CTRL_Y2		0x08
#define		  IPC_CTRL_IX1		0x10
#define		  IPC_CTRL_IX2		0x20

// ----------------------------
// Timer registers

#define		HW_TIMER		(HW_REG_BASE + 0x010)
#define		HW_ALARM		(HW_REG_BASE + 0x014)

// ----------------------------
// Interrupt management registers

#define		HW_PPCIRQFLAG		(HW_REG_BASE + 0x030)
#define		HW_PPCIRQMASK		(HW_REG_BASE + 0x034)
#define		HW_ARMIRQFLAG		(HW_REG_BASE + 0x038)
#define		HW_ARMIRQMASK		(HW_REG_BASE + 0x03c)

// ----------------------------
// Protection control registers

#define		HW_MEMMIRR		(HW_REG_BASE + 0x060)
#define		  SRAM_MIRROR		0x20
#define		HW_AHBPROT		(HW_REG_BASE + 0x064)

#define		HW_EXICTRL		(HW_REG_BASE + 0x070)
#define		  EXICTRL_ENABLE_EXI	1

// ----------------------------
// PowerPC GPIO registers

// Output state
#define		HW_GPIO1BOUT		(HW_REG_BASE + 0x0c0)
// Direction (1=output)
#define		HW_GPIO1BDIR		(HW_REG_BASE + 0x0c4)
// Input state
#define		HW_GPIO1BIN		(HW_REG_BASE + 0x0c8)
// Interrupt level
#define		HW_GPIO1BINTLVL		(HW_REG_BASE + 0x0cc)
// Interrupt flags (write 1 to clear)
#define		HW_GPIO1BINTFLAG	(HW_REG_BASE + 0x0d0)
// Interrupt propagation enable
// Do these interrupts go anywhere???
#define		HW_GPIO1BINTENABLE	(HW_REG_BASE + 0x0d4)
//??? seems to be a mirror of inputs at some point... power-up state?
#define		HW_GPIO1BINMIR		(HW_REG_BASE + 0x0d8)
// 0xFFFFFF by default, if cleared disables respective outputs. Top bits non-settable.
#define		HW_GPIO1ENABLE		(HW_REG_BASE + 0x0dc)
#define		  HW_GPIO1_SLOT		0x000020
#define		  HW_GPIO1_DEBUG	0xFF0000
#define		  HW_GPIO1_DEBUG_SH	16

// ----------------------------
// ARM GPIO registers

// Output state
#define		HW_GPIO1OUT		(HW_REG_BASE + 0x0e0)
// Direction (1=output)
#define		HW_GPIO1DIR		(HW_REG_BASE + 0x0e4)
// Input state
#define		HW_GPIO1IN		(HW_REG_BASE + 0x0e8)
// Interrupt level
#define		HW_GPIO1INTLVL		(HW_REG_BASE + 0x0ec)
// Interrupt flags (write 1 to clear)
#define		HW_GPIO1INTFLAG		(HW_REG_BASE + 0x0f0)
// Interrupt propagation enable (interrupts go to main interrupt 0x800)
#define		HW_GPIO1INTENABLE	(HW_REG_BASE + 0x0f4)
//??? seems to be a mirror of inputs at some point... power-up state?
#define		HW_GPIO1INMIR		(HW_REG_BASE + 0x0f8)
// Owner of each GPIO bit. If 1, GPIO1B registers assume control. If 0, GPIO1 registers assume control.
#define		HW_GPIO1OWNER		(HW_REG_BASE + 0x0fc)


// ----------------------------
// AHB registers?

#define		HW_ARB_CFG_M0		(HW_REG_BASE + 0x100)
#define		HW_ARB_CFG_M1		(HW_REG_BASE + 0x104)
#define		HW_ARB_CFG_M2		(HW_REG_BASE + 0x108)
#define		HW_ARB_CFG_M3		(HW_REG_BASE + 0x10c)
#define		HW_ARB_CFG_M4		(HW_REG_BASE + 0x110)
#define		HW_ARB_CFG_M5		(HW_REG_BASE + 0x114)
#define		HW_ARB_CFG_M6		(HW_REG_BASE + 0x118)
#define		HW_ARB_CFG_M7		(HW_REG_BASE + 0x11c)
#define		HW_ARB_CFG_M8		(HW_REG_BASE + 0x120)
#define		HW_ARB_CFG_M9		(HW_REG_BASE + 0x124)
#define		HW_ARB_CFG_MC		(HW_REG_BASE + 0x130)
#define		HW_ARB_CFG_MD		(HW_REG_BASE + 0x134)
#define		HW_ARB_CFG_ME		(HW_REG_BASE + 0x138)

// ----------------------------
// Unknown

#define		HW_DIFLAGS		(HW_REG_BASE + 0x180)
#define		  DIFLAGS_BOOT_CODE	0x100000

#define		HW_SPARE0		(HW_REG_BASE + 0x188)
#define		HW_SPARE1_BOOT0		(HW_REG_BASE + 0x18c)
#define		HW_RESETS		(HW_REG_BASE + 0x194)

// ----------------------------
// Clocking registers
#define		HW_CLOCKS		(HW_REG_BASE + 0x1b4)


// ----------------------------
// OTP registers
#define		HW_OTPCMD		(HW_REG_BASE + 0x1ec)
#define		HW_OTPDATA		(HW_REG_BASE + 0x1f0)

// ----------------------------
// Other registers
#define		HW_VERSION		(HW_REG_BASE + 0x214)


/* ----------------------------------------------------------------------------
 * NAND register space */
#define		NAND_REG_BASE		0x0d010000

#define		NAND_CMD		(NAND_REG_BASE + 0x000)
#define		NAND_STATUS		NAND_CMD
#define		NAND_CONF		(NAND_REG_BASE + 0x004)
#define		NAND_ADDR0		(NAND_REG_BASE + 0x008)
#define		NAND_ADDR1		(NAND_REG_BASE + 0x00c)
#define		NAND_DATA		(NAND_REG_BASE + 0x010)
#define		NAND_ECC		(NAND_REG_BASE + 0x014)
#define		NAND_UNK1		(NAND_REG_BASE + 0x018)
#define		NAND_UNK2		(NAND_REG_BASE + 0x01c)


/* ----------------------------------------------------------------------------
 * AES engine register space */
#define		AES_REG_BASE		0x0d020000

#define		AES_CMD			(AES_REG_BASE + 0x000)
#define		AES_SRC			(AES_REG_BASE + 0x004)
#define		AES_DEST		(AES_REG_BASE + 0x008)
#define		AES_KEY			(AES_REG_BASE + 0x00c)
#define		AES_IV			(AES_REG_BASE + 0x010)


/* ----------------------------------------------------------------------------
 * SHA-1 engine register space */
#define		SHA_REG_BASE		0x0d030000

#define		SHA_CMD			(SHA_REG_BASE + 0x000)
#define		SHA_SRC			(SHA_REG_BASE + 0x004)
#define		SHA_H0			(SHA_REG_BASE + 0x008)
#define		SHA_H1			(SHA_REG_BASE + 0x00c)
#define		SHA_H2			(SHA_REG_BASE + 0x010)
#define		SHA_H3			(SHA_REG_BASE + 0x014)
#define		SHA_H4			(SHA_REG_BASE + 0x018)


/* ----------------------------------------------------------------------------
 * SDHC (SD host controller) register space */
#define		SDHC_REG_BASE		0x0d070000


/* ----------------------------------------------------------------------------
 * EXI register space */
#define		EXI_REG_BASE		0x0d806800

#define		EXI0_REG_BASE		(EXI_REG_BASE+0x000)
#define		EXI1_REG_BASE		(EXI_REG_BASE+0x014)
#define		EXI2_REG_BASE		(EXI_REG_BASE+0x028)

#define		EXI0_CSR		(EXI0_REG_BASE+0x000)
#define		EXI0_MAR		(EXI0_REG_BASE+0x004)
#define		EXI0_LENGTH		(EXI0_REG_BASE+0x008)
#define		EXI0_CR			(EXI0_REG_BASE+0x00c)
#define		EXI0_DATA		(EXI0_REG_BASE+0x010)

#define		EXI1_CSR		(EXI1_REG_BASE+0x000)
#define		EXI1_MAR		(EXI1_REG_BASE+0x004)
#define		EXI1_LENGTH		(EXI1_REG_BASE+0x008)
#define		EXI1_CR			(EXI1_REG_BASE+0x00c)
#define		EXI1_DATA		(EXI1_REG_BASE+0x010)

#define		EXI2_CSR		(EXI2_REG_BASE+0x000)
#define		EXI2_MAR		(EXI2_REG_BASE+0x004)
#define		EXI2_LENGTH		(EXI2_REG_BASE+0x008)
#define		EXI2_CR			(EXI2_REG_BASE+0x00c)
#define		EXI2_DATA		(EXI2_REG_BASE+0x010)

#define		EXI_BOOT_BASE		(EXI_REG_BASE+0x040)


/* ----------------------------------------------------------------------------
 * Memory controller register space */
#define		MEM_REG_BASE		0x0d8b4000

#define		MEM_PROT		(MEM_REG_BASE+0x20a)
#define		MEM_PROT_START		(MEM_REG_BASE+0x20c)
#define		MEM_PROT_END		(MEM_REG_BASE+0x20e)
#define		MEM_FLUSHREQ		(MEM_REG_BASE+0x228)
#define		MEM_FLUSHACK		(MEM_REG_BASE+0x22a)


#endif
