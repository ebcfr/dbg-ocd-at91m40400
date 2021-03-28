/***************************************************************************
 * ATMEL Evaluation Board AT91EB40a
 *
 * Board level definitions
 ***************************************************************************/ 

#ifndef _BOARD_H_
#define _BOARD_H_

#ifndef __ASSEMBLY__
	#define __DEBUG__
	
	#include <stdint.h>
#endif

#include "AT91M40400.h"

/* 32.768 MHz main oscillator frequency */
#define	Fosc			(32768000)

/* Master Clock devider : defined by LK2 jumper (1, 2, 4, 8) */
#define	MCDIV			(1)

#define	MCLK			(Fosc/MCDIV)


/* Periphal definitions */
#ifndef __ASSEMBLY__
	#ifndef __DEBUG__
	#define _EBI	EBI_BASE
	#define _AIC	AIC_BASE
	#define _PIO	PIO_BASE
	#define _US0	USART0_BASE
	#define _US1	USART1_BASE
	#define _TC0	TC0_BASE
	#define	_TC1	TC1_BASE
	#define	_TC2	TC2_BASE
	#define	_TCB	TCB_BASE
	#define _WD		WD_BASE
	#define	_PS		PS_BASE
	#define _SF		SF_BASE
#else
	/* Register Definitions for Debug Access */
	extern EBI *    const _EBI;
	
	extern AIC * 	const _AIC;
	extern PIO *    const _PIO;
	extern USART *  const _US0;
	extern USART *  const _US1;
	extern TCC *    const _TC0;
	extern TCC *    const _TC1;
	extern TCC *    const _TC2;
	extern TCB *    const _TCB;
	extern WD *     const _WD;
	extern PS *     const _PS;
	extern SF *     const _SF;
	#endif
#endif


#endif /*_BOARD_H_ */

