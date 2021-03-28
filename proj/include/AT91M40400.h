//  ----------------------------------------------------------------------------
//          AT91M40400 Microcontroller Software Support
//  ----------------------------------------------------------------------------
//  Copyright (c) 2014, Eric Boucharé
//
//  All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//
//  - Redistributions of source code must retain the above copyright notice,
//  this list of conditions and the disclaimer below.
//
//  Atmel's name may not be used to endorse or promote products derived from
//  this software without specific prior written permission.
//
//  DISCLAIMER:  THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
//  DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
//  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  ----------------------------------------------------------------------------
// File Name           : AT91M40400.h based upon AT91SAM7X256.h
// Object              : AT91M40400 definitions
// Generated           : Eric Boucharé
//  ----------------------------------------------------------------------------

#ifndef _AT91M40400_H_
#define _AT91M40400_H_

#ifndef __ASSEMBLY__
#define __REG_CAST_32(a) 		(*((volatile unsigned long *)(a)))
#define __STRUCT_CAST(type, a) 	((type *)(a))
#else
#define __REG_CAST_32(a) 		(a)
#define __STRUCT_CAST(type, a) 	(a)
#endif

/***************************************************************************
 * External Bus Interface (EBI)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	CSR[8];		// Chip Select Register [0-7]
	unsigned long	RCR;		// Remap Control Register
	unsigned long	MCR;		// Memory Control Register
} EBI;
#endif

#define EBI_BASE_ADDR	0xFFE00000
#define EBI_BASE		(__STRUCT_CAST(EBI,EBI_BASE_ADDR))

#define _EBI_CSR0    (__REG_CAST_32( 0xFFE00000 ))
#define _EBI_CSR1    (__REG_CAST_32( 0xFFE00004 ))
#define _EBI_CSR2    (__REG_CAST_32( 0xFFE00008 ))
#define _EBI_CSR3    (__REG_CAST_32( 0xFFE0000C ))
#define _EBI_CSR4    (__REG_CAST_32( 0xFFE00010 ))
#define _EBI_CSR5    (__REG_CAST_32( 0xFFE00014 ))
#define _EBI_CSR6    (__REG_CAST_32( 0xFFE00018 ))
#define _EBI_CSR7    (__REG_CAST_32( 0xFFE0001C ))
#define _EBI_RCR     (__REG_CAST_32( 0xFFE00020 ))
#define _EBI_MCR     (__REG_CAST_32( 0xFFE00024 ))

/***************************************************************************
 * Advanced Interrupt Controller (AIC)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	 SMR[32]; 	// Source Mode Register
	unsigned long	 SVR[32]; 	// Source Vector Register
	unsigned long	 IVR; 		// IRQ Vector Register
	unsigned long	 FVR; 		// FIQ Vector Register
	unsigned long	 ISR; 		// Interrupt Status Register
	unsigned long	 IPR; 		// Interrupt Pending Register
	unsigned long	 IMR; 		// Interrupt Mask Register
	unsigned long	 CISR; 		// Core Interrupt Status Register
	unsigned long	 Reserved0[2]; 	//
	unsigned long	 IECR; 		// Interrupt Enable Command Register
	unsigned long	 IDCR; 		// Interrupt Disable Command Register
	unsigned long	 ICCR; 		// Interrupt Clear Command Register
	unsigned long	 ISCR; 		// Interrupt Set Command Register
	unsigned long	 EOICR; 	// End of Interrupt Command Register
	unsigned long	 SPU; 		// Spurious Vector Register
} AIC;
#endif

#define AIC_BASE_ADDR	0xFFFFF000
#define AIC_BASE		(__STRUCT_CAST(AIC,AIC_BASE_ADDR))

#define _AIC_SMR0    (__REG_CAST_32( 0xFFFFF000 )) // (AIC_SMR) Source Mode Register
#define _AIC_SMR1    (__REG_CAST_32( 0xFFFFF004 ))
#define _AIC_SMR2    (__REG_CAST_32( 0xFFFFF008 ))
#define _AIC_SMR3    (__REG_CAST_32( 0xFFFFF00C ))
#define _AIC_SMR4    (__REG_CAST_32( 0xFFFFF010 ))
#define _AIC_SMR5    (__REG_CAST_32( 0xFFFFF014 ))
#define _AIC_SMR6    (__REG_CAST_32( 0xFFFFF018 ))
#define _AIC_SMR7    (__REG_CAST_32( 0xFFFFF01C ))
#define _AIC_SMR8    (__REG_CAST_32( 0xFFFFF020 ))
#define _AIC_SMR9    (__REG_CAST_32( 0xFFFFF024 ))
#define _AIC_SMR10   (__REG_CAST_32( 0xFFFFF028 ))
#define _AIC_SMR11   (__REG_CAST_32( 0xFFFFF02C ))
#define _AIC_SMR12   (__REG_CAST_32( 0xFFFFF030 ))
#define _AIC_SMR13   (__REG_CAST_32( 0xFFFFF034 ))
#define _AIC_SMR14   (__REG_CAST_32( 0xFFFFF038 ))
#define _AIC_SMR15   (__REG_CAST_32( 0xFFFFF03C ))
#define _AIC_SMR16   (__REG_CAST_32( 0xFFFFF040 ))
#define _AIC_SMR17   (__REG_CAST_32( 0xFFFFF044 ))
#define _AIC_SMR18   (__REG_CAST_32( 0xFFFFF048 ))
#define _AIC_SMR19   (__REG_CAST_32( 0xFFFFF04C ))
#define _AIC_SMR20   (__REG_CAST_32( 0xFFFFF050 ))
#define _AIC_SMR21   (__REG_CAST_32( 0xFFFFF054 ))
#define _AIC_SMR22   (__REG_CAST_32( 0xFFFFF058 ))
#define _AIC_SMR23   (__REG_CAST_32( 0xFFFFF05C ))
#define _AIC_SMR24   (__REG_CAST_32( 0xFFFFF060 ))
#define _AIC_SMR25   (__REG_CAST_32( 0xFFFFF064 ))
#define _AIC_SMR26   (__REG_CAST_32( 0xFFFFF068 ))
#define _AIC_SMR27   (__REG_CAST_32( 0xFFFFF06C ))
#define _AIC_SMR28   (__REG_CAST_32( 0xFFFFF070 ))
#define _AIC_SMR29   (__REG_CAST_32( 0xFFFFF074 ))
#define _AIC_SMR30   (__REG_CAST_32( 0xFFFFF078 ))
#define _AIC_SMR31   (__REG_CAST_32( 0xFFFFF07C ))
#define _AIC_SVR0    (__REG_CAST_32( 0xFFFFF080 )) // (AIC_SVR) Source Vector Register
#define _AIC_SVR1    (__REG_CAST_32( 0xFFFFF084 ))
#define _AIC_SVR2    (__REG_CAST_32( 0xFFFFF088 ))
#define _AIC_SVR3    (__REG_CAST_32( 0xFFFFF08C ))
#define _AIC_SVR4    (__REG_CAST_32( 0xFFFFF090 ))
#define _AIC_SVR5    (__REG_CAST_32( 0xFFFFF094 ))
#define _AIC_SVR6    (__REG_CAST_32( 0xFFFFF098 ))
#define _AIC_SVR7    (__REG_CAST_32( 0xFFFFF09C ))
#define _AIC_SVR8    (__REG_CAST_32( 0xFFFFF0A0 ))
#define _AIC_SVR9    (__REG_CAST_32( 0xFFFFF0A4 ))
#define _AIC_SVR10   (__REG_CAST_32( 0xFFFFF0A8 ))
#define _AIC_SVR11   (__REG_CAST_32( 0xFFFFF0AC ))
#define _AIC_SVR12   (__REG_CAST_32( 0xFFFFF0B0 ))
#define _AIC_SVR13   (__REG_CAST_32( 0xFFFFF0B4 ))
#define _AIC_SVR14   (__REG_CAST_32( 0xFFFFF0B8 ))
#define _AIC_SVR15   (__REG_CAST_32( 0xFFFFF0BC ))
#define _AIC_SVR16   (__REG_CAST_32( 0xFFFFF0C0 ))
#define _AIC_SVR17   (__REG_CAST_32( 0xFFFFF0C4 ))
#define _AIC_SVR18   (__REG_CAST_32( 0xFFFFF0C8 ))
#define _AIC_SVR19   (__REG_CAST_32( 0xFFFFF0CC ))
#define _AIC_SVR20   (__REG_CAST_32( 0xFFFFF0D0 ))
#define _AIC_SVR21   (__REG_CAST_32( 0xFFFFF0D4 ))
#define _AIC_SVR22   (__REG_CAST_32( 0xFFFFF0D8 ))
#define _AIC_SVR23   (__REG_CAST_32( 0xFFFFF0DC ))
#define _AIC_SVR24   (__REG_CAST_32( 0xFFFFF0E0 ))
#define _AIC_SVR25   (__REG_CAST_32( 0xFFFFF0E4 ))
#define _AIC_SVR26   (__REG_CAST_32( 0xFFFFF0E8 ))
#define _AIC_SVR27   (__REG_CAST_32( 0xFFFFF0EC ))
#define _AIC_SVR28   (__REG_CAST_32( 0xFFFFF0F0 ))
#define _AIC_SVR29   (__REG_CAST_32( 0xFFFFF0F4 ))
#define _AIC_SVR30   (__REG_CAST_32( 0xFFFFF0F8 ))
#define _AIC_SVR31   (__REG_CAST_32( 0xFFFFF0FC ))
#define _AIC_IVR     (__REG_CAST_32( 0xFFFFF100 )) // (AIC_IVR) IRQ Vector Register
#define _AIC_FVR     (__REG_CAST_32( 0xFFFFF104 )) // (AIC_FVR) FIQ Vector Register
#define _AIC_ISR     (__REG_CAST_32( 0xFFFFF108 )) // (AIC_ISR) Interrupt Status Register
#define _AIC_IPR     (__REG_CAST_32( 0xFFFFF10C )) // (AIC_IPR) Interrupt Pending Register
#define _AIC_IMR     (__REG_CAST_32( 0xFFFFF110 )) // (AIC_IMR) Interrupt Mask Register
#define _AIC_CISR    (__REG_CAST_32( 0xFFFFF114 )) // (AIC_CISR) Core Interrupt Status Register
#define _AIC_IECR    (__REG_CAST_32( 0xFFFFF120 )) // (AIC_IECR) Interrupt Enable Command Register
#define _AIC_IDCR    (__REG_CAST_32( 0xFFFFF124 )) // (AIC_IDCR) Interrupt Disable Command Register
#define _AIC_ICCR    (__REG_CAST_32( 0xFFFFF128 )) // (AIC_ICCR) Interrupt Clear Command Register
#define _AIC_ISCR    (__REG_CAST_32( 0xFFFFF12C )) // (AIC_ISCR) Interrupt Set Command Register
#define _AIC_EOICR   (__REG_CAST_32( 0xFFFFF130 )) // (AIC_EOICR) End of Interrupt Command Register
#define _AIC_SPU     (__REG_CAST_32( 0xFFFFF134 )) // (AIC_SPU) Spurious Vector Register

// -------- AIC_SMR : (AIC Offset: 0x0) Control Register --------
#define AT91C_AIC_PRIOR       (0x7 <<  0) // (AIC) Priority Level
#define 	AT91C_AIC_PRIOR_LOWEST               (0x0) // (AIC) Lowest priority level
#define 	AT91C_AIC_PRIOR_HIGHEST              (0x7) // (AIC) Highest priority level
#define AT91C_AIC_SRCTYPE     (0x3 <<  5) // (AIC) Interrupt Source Type
#define 	AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL       (0x0 <<  5) // (AIC) Internal Sources Code Label High-level Sensitive
#define 	AT91C_AIC_SRCTYPE_EXT_LOW_LEVEL        (0x0 <<  5) // (AIC) External Sources Code Label Low-level Sensitive
#define 	AT91C_AIC_SRCTYPE_INT_POSITIVE_EDGE    (0x1 <<  5) // (AIC) Internal Sources Code Label Positive Edge triggered
#define 	AT91C_AIC_SRCTYPE_EXT_NEGATIVE_EDGE    (0x1 <<  5) // (AIC) External Sources Code Label Negative Edge triggered
#define 	AT91C_AIC_SRCTYPE_HIGH_LEVEL           (0x2 <<  5) // (AIC) Internal Or External Sources Code Label High-level Sensitive
#define 	AT91C_AIC_SRCTYPE_POSITIVE_EDGE        (0x3 <<  5) // (AIC) Internal Or External Sources Code Label Positive Edge triggered
// -------- AIC_CISR : (AIC Offset: 0x114) AIC Core Interrupt Status Register --------
#define AT91C_AIC_NFIQ        (0x1 <<  0) // (AIC) NFIQ Status
#define AT91C_AIC_NIRQ        (0x1 <<  1) // (AIC) NIRQ Status

/***************************************************************************
 * Parallel Input Output Controler (PIO)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	 PER; 	// PIO Enable Register
	unsigned long	 PDR; 	// PIO Disable Register
	unsigned long	 PSR; 	// PIO Status Register
	unsigned long	 Reserved0[1]; 	//
	unsigned long	 OER; 	// Output Enable Register
	unsigned long	 ODR; 	// Output Disable Registerr
	unsigned long	 OSR; 	// Output Status Register
	unsigned long	 Reserved1[1]; 	//
	unsigned long	 IFER; 	// Input Filter Enable Register
	unsigned long	 IFDR; 	// Input Filter Disable Register
	unsigned long	 IFSR; 	// Input Filter Status Register
	unsigned long	 Reserved2[1]; 	//
	unsigned long	 SODR; 	// Set Output Data Register
	unsigned long	 CODR; 	// Clear Output Data Register
	unsigned long	 ODSR; 	// Output Data Status Register
	unsigned long	 PDSR; 	// Pin Data Status Register
	unsigned long	 IER; 	// Interrupt Enable Register
	unsigned long	 IDR; 	// Interrupt Disable Register
	unsigned long	 IMR; 	// Interrupt Mask Register
	unsigned long	 ISR; 	// Interrupt Status Register
} PIO;
#endif

#define PIO_BASE_ADDR	0xFFFF0000
#define PIO_BASE		(__STRUCT_CAST(PIO,PIO_BASE_ADDR))

#define _PIO_PER         (__REG_CAST_32( 0xFFFF0000 )) // (PIO_PER) PIO Enable Register
#define _PIO_PDR         (__REG_CAST_32( 0xFFFF0004 )) // (PIO_PDR) PIO Disable Register
#define _PIO_PSR         (__REG_CAST_32( 0xFFFF0008 )) // (PIO_PSR) PIO Status Register
#define _PIO_OER         (__REG_CAST_32( 0xFFFF0010 )) // (PIO_OER) Output Enable Register
#define _PIO_ODR         (__REG_CAST_32( 0xFFFF0014 )) // (PIO_ODR) Output Disable Registerr
#define _PIO_OSR         (__REG_CAST_32( 0xFFFF0018 )) // (PIO_OSR) Output Status Register
#define _PIO_IFER        (__REG_CAST_32( 0xFFFF0020 )) // (PIO_IFER) Input Filter Enable Register
#define _PIO_IFDR        (__REG_CAST_32( 0xFFFF0024 )) // (PIO_IFDR) Input Filter Disable Register
#define _PIO_IFSR        (__REG_CAST_32( 0xFFFF0028 )) // (PIO_IFSR) Input Filter Status Register
#define _PIO_SODR        (__REG_CAST_32( 0xFFFF0030 )) // (PIO_SODR) Set Output Data Register
#define _PIO_CODR        (__REG_CAST_32( 0xFFFF0034 )) // (PIO_CODR) Clear Output Data Register
#define _PIO_ODSR        (__REG_CAST_32( 0xFFFF0038 )) // (PIO_ODSR) Output Data Status Register
#define _PIO_PDSR        (__REG_CAST_32( 0xFFFF003C )) // (PIO_PDSR) Pin Data Status Register
#define _PIO_IER         (__REG_CAST_32( 0xFFFF0040 )) // (PIO_IER) Interrupt Enable Register
#define _PIO_IDR         (__REG_CAST_32( 0xFFFF0044 )) // (PIO_IDR) Interrupt Disable Register
#define _PIO_IMR         (__REG_CAST_32( 0xFFFF0048 )) // (PIO_IMR) Interrupt Mask Register
#define _PIO_ISR         (__REG_CAST_32( 0xFFFF004C )) // (PIO_ISR) Interrupt Status Register

/***************************************************************************
 * Universal Synchronous/Asynchronous Receiver/Transmitter (USART)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	 CR; 	// Control Register
	unsigned long	 MR; 	// Mode Register
	unsigned long	 IER; 	// Interrupt Enable Register
	unsigned long	 IDR; 	// Interrupt Disable Register
	unsigned long	 IMR; 	// Interrupt Mask Register
	unsigned long	 CSR; 	// Channel Status Register
	unsigned long	 RHR; 	// Receiver Holding Register
	unsigned long	 THR; 	// Transmitter Holding Register
	unsigned long	 BRGR; 	// Baud Rate Generator Register
	unsigned long	 RTOR; 	// Receiver Time-out Register
	unsigned long	 TTGR; 	// Transmitter Time-guard Register
	unsigned long	 Reserved0[1]; 	//
	unsigned long	 RPR; 	// Receive Pointer Register
	unsigned long	 RCR; 	// Receive Counter Register
	unsigned long	 TPR; 	// Transmit Pointer Register
	unsigned long	 TCR; 	// Transmit Counter Register
} USART;
#endif

#define USART0_BASE_ADDR	0xFFFD0000
#define USART0_BASE		(__STRUCT_CAST(USART,USART0_BASE_ADDR))

#define _US0_CR           (__REG_CAST_32( 0xFFFD0000 )) // (US_CR) Control Register
#define _US0_MR           (__REG_CAST_32( 0xFFFD0004 )) // (US_MR) Mode Register
#define _US0_IER          (__REG_CAST_32( 0xFFFD0008 )) // (US_IER) Interrupt Enable Register
#define _US0_IDR          (__REG_CAST_32( 0xFFFD000C )) // (US_IDR) Interrupt Disable Register
#define _US0_IMR          (__REG_CAST_32( 0xFFFD0010 )) // (US_IMR) Interrupt Mask Register
#define _US0_CSR          (__REG_CAST_32( 0xFFFD0014 )) // (US_CSR) Channel Status Register
#define _US0_RHR          (__REG_CAST_32( 0xFFFD0018 )) // (US_RHR) Receiver Holding Register
#define _US0_THR          (__REG_CAST_32( 0xFFFD001C )) // (US_THR) Transmitter Holding Register
#define _US0_BRGR         (__REG_CAST_32( 0xFFFD0020 )) // (US_BRGR) Baud Rate Generator Register
#define _US0_RTOR         (__REG_CAST_32( 0xFFFD0024 )) // (US_RTOR) Receiver Time-out Register
#define _US0_TTGR         (__REG_CAST_32( 0xFFFD0028 )) // (US_TTGR) Transmitter Time-guard Register
#define _US0_RPR          (__REG_CAST_32( 0xFFFD0030 )) // (US_RPR) Receive Pointer Register
#define _US0_RCR          (__REG_CAST_32( 0xFFFD0034 )) // (US_RCR) Receive Counter Register
#define _US0_TPR          (__REG_CAST_32( 0xFFFD0034 )) // (US_TPR) Transmit Pointer Register
#define _US0_TCR          (__REG_CAST_32( 0xFFFD003C )) // (US_TCR) Transmit Counter Register

#define USART1_BASE_ADDR	0xFFFCC000
#define USART1_BASE		(__STRUCT_CAST(USART,USART1_BASE_ADDR))

#define _US1_CR           (__REG_CAST_32( 0xFFFCC000 )) // (US_CR) Control Register
#define _US1_MR           (__REG_CAST_32( 0xFFFCC004 )) // (US_MR) Mode Register
#define _US1_IER          (__REG_CAST_32( 0xFFFCC008 )) // (US_IER) Interrupt Enable Register
#define _US1_IDR          (__REG_CAST_32( 0xFFFCC00C )) // (US_IDR) Interrupt Disable Register
#define _US1_IMR          (__REG_CAST_32( 0xFFFCC010 )) // (US_IMR) Interrupt Mask Register
#define _US1_CSR          (__REG_CAST_32( 0xFFFCC014 )) // (US_CSR) Channel Status Register
#define _US1_RHR          (__REG_CAST_32( 0xFFFCC018 )) // (US_RHR) Receiver Holding Register
#define _US1_THR          (__REG_CAST_32( 0xFFFCC01C )) // (US_THR) Transmitter Holding Register
#define _US1_BRGR         (__REG_CAST_32( 0xFFFCC020 )) // (US_BRGR) Baud Rate Generator Register
#define _US1_RTOR         (__REG_CAST_32( 0xFFFCC024 )) // (US_RTOR) Receiver Time-out Register
#define _US1_TTGR         (__REG_CAST_32( 0xFFFCC028 )) // (US_TTGR) Transmitter Time-guard Register
#define _US1_RPR          (__REG_CAST_32( 0xFFFCC030 )) // (US_RPR) Receive Pointer Register
#define _US1_RCR          (__REG_CAST_32( 0xFFFCC034 )) // (US_RCR) Receive Counter Register
#define _US1_TPR          (__REG_CAST_32( 0xFFFCC034 )) // (US_TPR) Transmit Pointer Register
#define _US1_TCR          (__REG_CAST_32( 0xFFFCC03C )) // (US_TCR) Transmit Counter Register


// -------- US_CR : (USART Offset: 0x0) Debug Unit Control Register --------
#define AT91C_US_STTBRK       (0x1 <<  9) // (USART) Start Break
#define AT91C_US_STPBRK       (0x1 << 10) // (USART) Stop Break
#define AT91C_US_STTTO        (0x1 << 11) // (USART) Start Time-out
#define AT91C_US_SENDA        (0x1 << 12) // (USART) Send Address
#define AT91C_US_RSTIT        (0x1 << 13) // (USART) Reset Iterations
#define AT91C_US_RSTNACK      (0x1 << 14) // (USART) Reset Non Acknowledge
#define AT91C_US_RETTO        (0x1 << 15) // (USART) Rearm Time-out
#define AT91C_US_DTREN        (0x1 << 16) // (USART) Data Terminal ready Enable
#define AT91C_US_DTRDIS       (0x1 << 17) // (USART) Data Terminal ready Disable
#define AT91C_US_RTSEN        (0x1 << 18) // (USART) Request to Send enable
#define AT91C_US_RTSDIS       (0x1 << 19) // (USART) Request to Send Disable
// -------- US_MR : (USART Offset: 0x4) Debug Unit Mode Register --------
#define AT91C_US_USMODE       (0xF <<  0) // (USART) Usart mode
#define 	AT91C_US_USMODE_NORMAL               (0x0) // (USART) Normal
#define 	AT91C_US_USMODE_RS485                (0x1) // (USART) RS485
#define 	AT91C_US_USMODE_HWHSH                (0x2) // (USART) Hardware Handshaking
#define 	AT91C_US_USMODE_MODEM                (0x3) // (USART) Modem
#define 	AT91C_US_USMODE_ISO7816_0            (0x4) // (USART) ISO7816 protocol: T = 0
#define 	AT91C_US_USMODE_ISO7816_1            (0x6) // (USART) ISO7816 protocol: T = 1
#define 	AT91C_US_USMODE_IRDA                 (0x8) // (USART) IrDA
#define 	AT91C_US_USMODE_SWHSH                (0xC) // (USART) Software Handshaking
#define AT91C_US_CLKS         (0x3 <<  4) // (USART) Clock Selection (Baud Rate generator Input Clock
#define 	AT91C_US_CLKS_CLOCK                (0x0 <<  4) // (USART) Clock
#define 	AT91C_US_CLKS_FDIV1                (0x1 <<  4) // (USART) fdiv1
#define 	AT91C_US_CLKS_SLOW                 (0x2 <<  4) // (USART) slow_clock (ARM)
#define 	AT91C_US_CLKS_EXT                  (0x3 <<  4) // (USART) External (SCK)
#define AT91C_US_CHRL         (0x3 <<  6) // (USART) Clock Selection (Baud Rate generator Input Clock
#define 	AT91C_US_CHRL_5_BITS               (0x0 <<  6) // (USART) Character Length: 5 bits
#define 	AT91C_US_CHRL_6_BITS               (0x1 <<  6) // (USART) Character Length: 6 bits
#define 	AT91C_US_CHRL_7_BITS               (0x2 <<  6) // (USART) Character Length: 7 bits
#define 	AT91C_US_CHRL_8_BITS               (0x3 <<  6) // (USART) Character Length: 8 bits
#define AT91C_US_SYNC         (0x1 <<  8) // (USART) Synchronous Mode Select
#define AT91C_US_NBSTOP       (0x3 << 12) // (USART) Number of Stop bits
#define 	AT91C_US_NBSTOP_1_BIT                (0x0 << 12) // (USART) 1 stop bit
#define 	AT91C_US_NBSTOP_15_BIT               (0x1 << 12) // (USART) Asynchronous (SYNC=0) 2 stop bits Synchronous (SYNC=1) 2 stop bits
#define 	AT91C_US_NBSTOP_2_BIT                (0x2 << 12) // (USART) 2 stop bits
#define AT91C_US_MSBF         (0x1 << 16) // (USART) Bit Order
#define AT91C_US_MODE9        (0x1 << 17) // (USART) 9-bit Character length
#define AT91C_US_CKLO         (0x1 << 18) // (USART) Clock Output Select
#define AT91C_US_OVER         (0x1 << 19) // (USART) Over Sampling Mode
#define AT91C_US_INACK        (0x1 << 20) // (USART) Inhibit Non Acknowledge
#define AT91C_US_DSNACK       (0x1 << 21) // (USART) Disable Successive NACK
#define AT91C_US_MAX_ITER     (0x1 << 24) // (USART) Number of Repetitions
#define AT91C_US_FILTER       (0x1 << 28) // (USART) Receive Line Filter
// -------- US_IER : (USART Offset: 0x8) Debug Unit Interrupt Enable Register --------
#define AT91C_US_RXBRK        (0x1 <<  2) // (USART) Break Received/End of Break
#define AT91C_US_TIMEOUT      (0x1 <<  8) // (USART) Receiver Time-out
#define AT91C_US_ITERATION    (0x1 << 10) // (USART) Max number of Repetitions Reached
#define AT91C_US_NACK         (0x1 << 13) // (USART) Non Acknowledge
#define AT91C_US_RIIC         (0x1 << 16) // (USART) Ring INdicator Input Change Flag
#define AT91C_US_DSRIC        (0x1 << 17) // (USART) Data Set Ready Input Change Flag
#define AT91C_US_DCDIC        (0x1 << 18) // (USART) Data Carrier Flag
#define AT91C_US_CTSIC        (0x1 << 19) // (USART) Clear To Send Input Change Flag
// -------- US_IDR : (USART Offset: 0xc) Debug Unit Interrupt Disable Register --------
// -------- US_IMR : (USART Offset: 0x10) Debug Unit Interrupt Mask Register --------
// -------- US_CSR : (USART Offset: 0x14) Debug Unit Channel Status Register --------
#define AT91C_US_RI           (0x1 << 20) // (USART) Image of RI Input
#define AT91C_US_DSR          (0x1 << 21) // (USART) Image of DSR Input
#define AT91C_US_DCD          (0x1 << 22) // (USART) Image of DCD Input
#define AT91C_US_CTS          (0x1 << 23) // (USART) Image of CTS Input

/***************************************************************************
 * Timer Counter Channel (TC)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	 CCR; 	// Channel Control Register
	unsigned long	 CMR; 	// Channel Mode Register (Capture Mode / Waveform Mode)
	unsigned long	 Reserved0[2]; 	//
	unsigned long	 CV; 	// Counter Value
	unsigned long	 RA; 	// Register A
	unsigned long	 RB; 	// Register B
	unsigned long	 RC; 	// Register C
	unsigned long	 SR; 	// Status Register
	unsigned long	 IER; 	// Interrupt Enable Register
	unsigned long	 IDR; 	// Interrupt Disable Register
	unsigned long	 IMR; 	// Interrupt Mask Register
} TCC;
#endif

#define TC0_BASE_ADDR	0xFFFE0000
#define TC0_BASE		(__STRUCT_CAST(TCC,TC0_BASE_ADDR))

#define _TC0_CCR          (__REG_CAST_32( 0xFFFE0000 )) // (TC_CCR) Channel Control Register
#define _TC0_CMR          (__REG_CAST_32( 0xFFFE0004 )) // (TC_CMR) Channel Mode Register (Capture Mode / Waveform Mode)
#define _TC0_CV           (__REG_CAST_32( 0xFFFE0010 )) // (TC_CV) Counter Value
#define _TC0_RA           (__REG_CAST_32( 0xFFFE0014 )) // (TC_RA) Register A
#define _TC0_RB           (__REG_CAST_32( 0xFFFE0018 )) // (TC_RB) Register B
#define _TC0_RC           (__REG_CAST_32( 0xFFFE001C )) // (TC_RC) Register C
#define _TC0_SR           (__REG_CAST_32( 0xFFFE0020 )) // (TC_SR) Status Register
#define _TC0_IER          (__REG_CAST_32( 0xFFFE0024 )) // (TC_IER) Interrupt Enable Register
#define _TC0_IDR          (__REG_CAST_32( 0xFFFE0028 )) // (TC_IDR) Interrupt Disable Register
#define _TC0_IMR          (__REG_CAST_32( 0xFFFE002C )) // (TC_IMR) Interrupt Mask Register

#define TC1_BASE_ADDR	0xFFFE0040
#define TC1_BASE		(__STRUCT_CAST(TCC,TC1_BASE_ADDR))

#define _TC1_CCR          (__REG_CAST_32( 0xFFFE0040 )) // (TC_CCR) Channel Control Register
#define _TC1_CMR          (__REG_CAST_32( 0xFFFE0044 )) // (TC_CMR) Channel Mode Register (Capture Mode / Waveform Mode)
#define _TC1_CV           (__REG_CAST_32( 0xFFFE0050 )) // (TC_CV) Counter Value
#define _TC1_RA           (__REG_CAST_32( 0xFFFE0054 )) // (TC_RA) Register A
#define _TC1_RB           (__REG_CAST_32( 0xFFFE0058 )) // (TC_RB) Register B
#define _TC1_RC           (__REG_CAST_32( 0xFFFE005C )) // (TC_RC) Register C
#define _TC1_SR           (__REG_CAST_32( 0xFFFE0060 )) // (TC_SR) Status Register
#define _TC1_IER          (__REG_CAST_32( 0xFFFE0064 )) // (TC_IER) Interrupt Enable Register
#define _TC1_IDR          (__REG_CAST_32( 0xFFFE0068 )) // (TC_IDR) Interrupt Disable Register
#define _TC1_IMR          (__REG_CAST_32( 0xFFFE006C )) // (TC_IMR) Interrupt Mask Register

#define TC2_BASE_ADDR	0xFFFE0080
#define TC2_BASE		(__STRUCT_CAST(TCC,TC2_BASE_ADDR))

#define _TC2_CCR          (__REG_CAST_32( 0xFFFE0080 )) // (TC_CCR) Channel Control Register
#define _TC2_CMR          (__REG_CAST_32( 0xFFFE0084 )) // (TC_CMR) Channel Mode Register (Capture Mode / Waveform Mode)
#define _TC2_CV           (__REG_CAST_32( 0xFFFE0090 )) // (TC_CV) Counter Value
#define _TC2_RA           (__REG_CAST_32( 0xFFFE0094 )) // (TC_RA) Register A
#define _TC2_RB           (__REG_CAST_32( 0xFFFE0098 )) // (TC_RB) Register B
#define _TC2_RC           (__REG_CAST_32( 0xFFFE009C )) // (TC_RC) Register C
#define _TC2_SR           (__REG_CAST_32( 0xFFFE00A0 )) // (TC_SR) Status Register
#define _TC2_IER          (__REG_CAST_32( 0xFFFE00A4 )) // (TC_IER) Interrupt Enable Register
#define _TC2_IDR          (__REG_CAST_32( 0xFFFE00A8 )) // (TC_IDR) Interrupt Disable Register
#define _TC2_IMR          (__REG_CAST_32( 0xFFFE00AC )) // (TC_IMR) Interrupt Mask Register

// -------- TC_CCR : (TC Offset: 0x0) TC Channel Control Register --------
#define AT91C_TC_CLKEN        (0x1 <<  0) // (TC) Counter Clock Enable Command
#define AT91C_TC_CLKDIS       (0x1 <<  1) // (TC) Counter Clock Disable Command
#define AT91C_TC_SWTRG        (0x1 <<  2) // (TC) Software Trigger Command
// -------- TC_CMR : (TC Offset: 0x4) TC Channel Mode Register: Capture Mode / Waveform Mode --------
#define AT91C_TC_CLKS         (0x7 <<  0) // (TC) Clock Selection
#define 	AT91C_TC_CLKS_TIMER_DIV1_CLOCK     (0x0) // (TC) Clock selected: TIMER_DIV1_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV2_CLOCK     (0x1) // (TC) Clock selected: TIMER_DIV2_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV3_CLOCK     (0x2) // (TC) Clock selected: TIMER_DIV3_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV4_CLOCK     (0x3) // (TC) Clock selected: TIMER_DIV4_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV5_CLOCK     (0x4) // (TC) Clock selected: TIMER_DIV5_CLOCK
#define 	AT91C_TC_CLKS_XC0                  (0x5) // (TC) Clock selected: XC0
#define 	AT91C_TC_CLKS_XC1                  (0x6) // (TC) Clock selected: XC1
#define 	AT91C_TC_CLKS_XC2                  (0x7) // (TC) Clock selected: XC2
#define AT91C_TC_CLKI         (0x1 <<  3) // (TC) Clock Invert
#define AT91C_TC_BURST        (0x3 <<  4) // (TC) Burst Signal Selection
#define 	AT91C_TC_BURST_NONE                 (0x0 <<  4) // (TC) The clock is not gated by an external signal
#define 	AT91C_TC_BURST_XC0                  (0x1 <<  4) // (TC) XC0 is ANDed with the selected clock
#define 	AT91C_TC_BURST_XC1                  (0x2 <<  4) // (TC) XC1 is ANDed with the selected clock
#define 	AT91C_TC_BURST_XC2                  (0x3 <<  4) // (TC) XC2 is ANDed with the selected clock
#define AT91C_TC_CPCSTOP      (0x1 <<  6) // (TC) Counter Clock Stopped with RC Compare
#define AT91C_TC_LDBSTOP      (0x1 <<  6) // (TC) Counter Clock Stopped with RB Loading
#define AT91C_TC_CPCDIS       (0x1 <<  7) // (TC) Counter Clock Disable with RC Compare
#define AT91C_TC_LDBDIS       (0x1 <<  7) // (TC) Counter Clock Disabled with RB Loading
#define AT91C_TC_ETRGEDG      (0x3 <<  8) // (TC) External Trigger Edge Selection
#define 	AT91C_TC_ETRGEDG_NONE                 (0x0 <<  8) // (TC) Edge: None
#define 	AT91C_TC_ETRGEDG_RISING               (0x1 <<  8) // (TC) Edge: rising edge
#define 	AT91C_TC_ETRGEDG_FALLING              (0x2 <<  8) // (TC) Edge: falling edge
#define 	AT91C_TC_ETRGEDG_BOTH                 (0x3 <<  8) // (TC) Edge: each edge
#define AT91C_TC_EEVTEDG      (0x3 <<  8) // (TC) External Event Edge Selection
#define 	AT91C_TC_EEVTEDG_NONE                 (0x0 <<  8) // (TC) Edge: None
#define 	AT91C_TC_EEVTEDG_RISING               (0x1 <<  8) // (TC) Edge: rising edge
#define 	AT91C_TC_EEVTEDG_FALLING              (0x2 <<  8) // (TC) Edge: falling edge
#define 	AT91C_TC_EEVTEDG_BOTH                 (0x3 <<  8) // (TC) Edge: each edge
#define AT91C_TC_EEVT         (0x3 << 10) // (TC) External Event  Selection
#define 	AT91C_TC_EEVT_TIOB                 (0x0 << 10) // (TC) Signal selected as external event: TIOB TIOB direction: input
#define 	AT91C_TC_EEVT_XC0                  (0x1 << 10) // (TC) Signal selected as external event: XC0 TIOB direction: output
#define 	AT91C_TC_EEVT_XC1                  (0x2 << 10) // (TC) Signal selected as external event: XC1 TIOB direction: output
#define 	AT91C_TC_EEVT_XC2                  (0x3 << 10) // (TC) Signal selected as external event: XC2 TIOB direction: output
#define AT91C_TC_ABETRG       (0x1 << 10) // (TC) TIOA or TIOB External Trigger Selection
#define AT91C_TC_ENETRG       (0x1 << 12) // (TC) External Event Trigger enable
#define AT91C_TC_WAVESEL      (0x3 << 13) // (TC) Waveform  Selection
#define 	AT91C_TC_WAVESEL_UP                   (0x0 << 13) // (TC) UP mode without atomatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UPDOWN               (0x1 << 13) // (TC) UPDOWN mode without automatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UP_AUTO              (0x2 << 13) // (TC) UP mode with automatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UPDOWN_AUTO          (0x3 << 13) // (TC) UPDOWN mode with automatic trigger on RC Compare
#define AT91C_TC_CPCTRG       (0x1 << 14) // (TC) RC Compare Trigger Enable
#define AT91C_TC_WAVE         (0x1 << 15) // (TC)
#define AT91C_TC_ACPA         (0x3 << 16) // (TC) RA Compare Effect on TIOA
#define 	AT91C_TC_ACPA_NONE                 (0x0 << 16) // (TC) Effect: none
#define 	AT91C_TC_ACPA_SET                  (0x1 << 16) // (TC) Effect: set
#define 	AT91C_TC_ACPA_CLEAR                (0x2 << 16) // (TC) Effect: clear
#define 	AT91C_TC_ACPA_TOGGLE               (0x3 << 16) // (TC) Effect: toggle
#define AT91C_TC_LDRA         (0x3 << 16) // (TC) RA Loading Selection
#define 	AT91C_TC_LDRA_NONE                 (0x0 << 16) // (TC) Edge: None
#define 	AT91C_TC_LDRA_RISING               (0x1 << 16) // (TC) Edge: rising edge of TIOA
#define 	AT91C_TC_LDRA_FALLING              (0x2 << 16) // (TC) Edge: falling edge of TIOA
#define 	AT91C_TC_LDRA_BOTH                 (0x3 << 16) // (TC) Edge: each edge of TIOA
#define AT91C_TC_ACPC         (0x3 << 18) // (TC) RC Compare Effect on TIOA
#define 	AT91C_TC_ACPC_NONE                 (0x0 << 18) // (TC) Effect: none
#define 	AT91C_TC_ACPC_SET                  (0x1 << 18) // (TC) Effect: set
#define 	AT91C_TC_ACPC_CLEAR                (0x2 << 18) // (TC) Effect: clear
#define 	AT91C_TC_ACPC_TOGGLE               (0x3 << 18) // (TC) Effect: toggle
#define AT91C_TC_LDRB         (0x3 << 18) // (TC) RB Loading Selection
#define 	AT91C_TC_LDRB_NONE                 (0x0 << 18) // (TC) Edge: None
#define 	AT91C_TC_LDRB_RISING               (0x1 << 18) // (TC) Edge: rising edge of TIOA
#define 	AT91C_TC_LDRB_FALLING              (0x2 << 18) // (TC) Edge: falling edge of TIOA
#define 	AT91C_TC_LDRB_BOTH                 (0x3 << 18) // (TC) Edge: each edge of TIOA
#define AT91C_TC_AEEVT        (0x3 << 20) // (TC) External Event Effect on TIOA
#define 	AT91C_TC_AEEVT_NONE                 (0x0 << 20) // (TC) Effect: none
#define 	AT91C_TC_AEEVT_SET                  (0x1 << 20) // (TC) Effect: set
#define 	AT91C_TC_AEEVT_CLEAR                (0x2 << 20) // (TC) Effect: clear
#define 	AT91C_TC_AEEVT_TOGGLE               (0x3 << 20) // (TC) Effect: toggle
#define AT91C_TC_ASWTRG       (0x3 << 22) // (TC) Software Trigger Effect on TIOA
#define 	AT91C_TC_ASWTRG_NONE                 (0x0 << 22) // (TC) Effect: none
#define 	AT91C_TC_ASWTRG_SET                  (0x1 << 22) // (TC) Effect: set
#define 	AT91C_TC_ASWTRG_CLEAR                (0x2 << 22) // (TC) Effect: clear
#define 	AT91C_TC_ASWTRG_TOGGLE               (0x3 << 22) // (TC) Effect: toggle
#define AT91C_TC_BCPB         (0x3 << 24) // (TC) RB Compare Effect on TIOB
#define 	AT91C_TC_BCPB_NONE                 (0x0 << 24) // (TC) Effect: none
#define 	AT91C_TC_BCPB_SET                  (0x1 << 24) // (TC) Effect: set
#define 	AT91C_TC_BCPB_CLEAR                (0x2 << 24) // (TC) Effect: clear
#define 	AT91C_TC_BCPB_TOGGLE               (0x3 << 24) // (TC) Effect: toggle
#define AT91C_TC_BCPC         (0x3 << 26) // (TC) RC Compare Effect on TIOB
#define 	AT91C_TC_BCPC_NONE                 (0x0 << 26) // (TC) Effect: none
#define 	AT91C_TC_BCPC_SET                  (0x1 << 26) // (TC) Effect: set
#define 	AT91C_TC_BCPC_CLEAR                (0x2 << 26) // (TC) Effect: clear
#define 	AT91C_TC_BCPC_TOGGLE               (0x3 << 26) // (TC) Effect: toggle
#define AT91C_TC_BEEVT        (0x3 << 28) // (TC) External Event Effect on TIOB
#define 	AT91C_TC_BEEVT_NONE                 (0x0 << 28) // (TC) Effect: none
#define 	AT91C_TC_BEEVT_SET                  (0x1 << 28) // (TC) Effect: set
#define 	AT91C_TC_BEEVT_CLEAR                (0x2 << 28) // (TC) Effect: clear
#define 	AT91C_TC_BEEVT_TOGGLE               (0x3 << 28) // (TC) Effect: toggle
#define AT91C_TC_BSWTRG       (0x3 << 30) // (TC) Software Trigger Effect on TIOB
#define 	AT91C_TC_BSWTRG_NONE                 (0x0 << 30) // (TC) Effect: none
#define 	AT91C_TC_BSWTRG_SET                  (0x1 << 30) // (TC) Effect: set
#define 	AT91C_TC_BSWTRG_CLEAR                (0x2 << 30) // (TC) Effect: clear
#define 	AT91C_TC_BSWTRG_TOGGLE               (0x3 << 30) // (TC) Effect: toggle
// -------- TC_SR : (TC Offset: 0x20) TC Channel Status Register --------
#define AT91C_TC_COVFS        (0x1 <<  0) // (TC) Counter Overflow
#define AT91C_TC_LOVRS        (0x1 <<  1) // (TC) Load Overrun
#define AT91C_TC_CPAS         (0x1 <<  2) // (TC) RA Compare
#define AT91C_TC_CPBS         (0x1 <<  3) // (TC) RB Compare
#define AT91C_TC_CPCS         (0x1 <<  4) // (TC) RC Compare
#define AT91C_TC_LDRAS        (0x1 <<  5) // (TC) RA Loading
#define AT91C_TC_LDRBS        (0x1 <<  6) // (TC) RB Loading
#define AT91C_TC_ETRGS        (0x1 <<  7) // (TC) External Trigger
#define AT91C_TC_CLKSTA       (0x1 << 16) // (TC) Clock Enabling
#define AT91C_TC_MTIOA        (0x1 << 17) // (TC) TIOA Mirror
#define AT91C_TC_MTIOB        (0x1 << 18) // (TC) TIOA Mirror
// -------- TC_IER : (TC Offset: 0x24) TC Channel Interrupt Enable Register --------
// -------- TC_IDR : (TC Offset: 0x28) TC Channel Interrupt Disable Register --------
// -------- TC_IMR : (TC Offset: 0x2c) TC Channel Interrupt Mask Register --------

/***************************************************************************
 * Timer Counter Block (TCB)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	TCC	             TC0; 	// TC Channel 0
	unsigned long	 Reserved0[4]; 	//
	TCC				 TC1; 	// TC Channel 1
	unsigned long	 Reserved1[4]; 	//
	TCC				 TC2; 	// TC Channel 2
	unsigned long	 Reserved2[4]; 	//
	unsigned long	 BCR; 	// TC Block Control Register
	unsigned long	 BMR; 	// TC Block Mode Register
} TCB;
#endif

#define TCB_BASE_ADDR	0xFFFE0000
#define TCB_BASE		(__STRUCT_CAST(TCB,TCB_BASE_ADDR))

#define _TCB_BCR        (__REG_CAST_32( 0x000000C0 )) // (TCB_BCR) TC Block Control Register
#define _TCB_BMR        (__REG_CAST_32( 0x000000C4 )) // (TCB_BMR) TC Block Mode Register

// -------- TCB_BCR : (TCB Offset: 0xc0) TC Block Control Register --------
#define AT91C_TCB_SYNC        (0x1 <<  0) // (TCB) Synchro Command
// -------- TCB_BMR : (TCB Offset: 0xc4) TC Block Mode Register --------
#define AT91C_TCB_TC0XC0S     (0x3 <<  0) // (TCB) External Clock Signal 0 Selection
#define 	AT91C_TCB_TC0XC0S_TCLK0                (0x0) // (TCB) TCLK0 connected to XC0
#define 	AT91C_TCB_TC0XC0S_NONE                 (0x1) // (TCB) None signal connected to XC0
#define 	AT91C_TCB_TC0XC0S_TIOA1                (0x2) // (TCB) TIOA1 connected to XC0
#define 	AT91C_TCB_TC0XC0S_TIOA2                (0x3) // (TCB) TIOA2 connected to XC0
#define AT91C_TCB_TC1XC1S     (0x3 <<  2) // (TCB) External Clock Signal 1 Selection
#define 	AT91C_TCB_TC1XC1S_TCLK1                (0x0 <<  2) // (TCB) TCLK1 connected to XC1
#define 	AT91C_TCB_TC1XC1S_NONE                 (0x1 <<  2) // (TCB) None signal connected to XC1
#define 	AT91C_TCB_TC1XC1S_TIOA0                (0x2 <<  2) // (TCB) TIOA0 connected to XC1
#define 	AT91C_TCB_TC1XC1S_TIOA2                (0x3 <<  2) // (TCB) TIOA2 connected to XC1
#define AT91C_TCB_TC2XC2S     (0x3 <<  4) // (TCB) External Clock Signal 2 Selection
#define 	AT91C_TCB_TC2XC2S_TCLK2                (0x0 <<  4) // (TCB) TCLK2 connected to XC2
#define 	AT91C_TCB_TC2XC2S_NONE                 (0x1 <<  4) // (TCB) None signal connected to XC2
#define 	AT91C_TCB_TC2XC2S_TIOA0                (0x2 <<  4) // (TCB) TIOA0 connected to XC2
#define 	AT91C_TCB_TC2XC2S_TIOA1                (0x3 <<  4) // (TCB) TIOA2 connected to XC2

/***************************************************************************
 * Watchdog Timer (WD)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	 OMR; 	// Watchdog Overflow Mode Register
	unsigned long	 CMR; 	// Watchdog Clock Mode Register
	unsigned long	 CR; 	// Watchdog Control Register
	unsigned long	 SR; 	// Watchdog Status Register
} WD;
#endif

#define WD_BASE_ADDR	0xFFFF8000
#define WD_BASE			(__STRUCT_CAST(WD,WD_BASE_ADDR))

#define _WD_OMR         (__REG_CAST_32( 0xFFFF8000 )) // (WD_OMR) Watchdog Overflow Mode Register
#define _WD_CMR         (__REG_CAST_32( 0xFFFF8004 )) // (WD_CMR) Watchdog Clock Mode Register
#define _WD_CR          (__REG_CAST_32( 0xFFFF8008 )) // (WD_CR) Watchdog Control Register
#define _WD_SR          (__REG_CAST_32( 0xFFFF800C )) // (WD_SR) Watchdog Status Register

/***************************************************************************
 * Power Saving (PS)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	 CR; 	// Control Register
} PS;
#endif

#define PS_BASE_ADDR	0xFFFF4000
#define PS_BASE			(__STRUCT_CAST(PS,PS_BASE_ADDR))

#define _PS_CR        (__REG_CAST_32( 0xFFFF4000 )) // (PS_CR) Control Register

/***************************************************************************
 * Special Function (SF)
 ***************************************************************************/
#ifndef __ASSEMBLY__
typedef volatile struct {
	unsigned long	 CIDR; 	// Chip ID Register
	unsigned long	 EXID; 	// Chip ID Extension Register
	unsigned long	 RSR; 	// Reset Status register
	unsigned long	 Reserved0[3]; 	//
	unsigned long	 PMR; 	// Protect Mode Register
} SF;
#endif

#define SF_BASE_ADDR	0xFFF00000
#define SF_BASE			(__STRUCT_CAST(SF,SF_BASE_ADDR))

#define _SF_CIDR        (__REG_CAST_32( 0xFFF00000 )) // Chip ID Register
#define _SF_EXID        (__REG_CAST_32( 0xFFF00004 )) // Chip ID Extension Register
#define _SF_RSR         (__REG_CAST_32( 0xFFF00008 )) // Reset Status register
#define _SF_PMR         (__REG_CAST_32( 0xFFF00018 )) // Protect Mode Register


#endif
