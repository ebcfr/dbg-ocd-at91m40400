/* ----------------------------------------------------------------------------
 * AT91M40400 board_lowlevel.c
 * ----------------------------------------------------------------------------
 * Copyright (c) 2014, Eric Boucharé
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
/// \unit
///
/// !Purpose
///
/// Provides the low-level initialization function that gets called on chip
/// startup.
///
/// !Usage
///
/// LowLevelInit() is called in #board_cstartup.S#.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "board.h"

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Default spurious interrupt handler. Infinite loop.
//------------------------------------------------------------------------------
void defaultSpuriousHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for fast interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultFiqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for standard interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultIrqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Performs the low-level initialization of the chip. This includes EBI, AIC
/// & watchdog configuration, as well as memory remapping.
//------------------------------------------------------------------------------
void LowLevelInit( void )
{
    unsigned char i;

    /* Set flash wait states in the EBI
     **********************************/

    /* Initialize AIC
     ****************/
    _AIC->IDCR = 0xFFFFFFFF;
    _AIC->SVR[0] = (unsigned int) defaultFiqHandler;
    for (i = 1; i < 31; i++) {
        _AIC->SVR[i] = (unsigned int) defaultIrqHandler;
    }
    _AIC->SPU = (unsigned int) defaultSpuriousHandler;

    // Unstack nested interrupts
    for (i = 0; i < 8 ; i++) {
       _AIC->EOICR = 0;
    }

    // Enable Debug mode
    _SF->PMR = (0x27A8<<16) | (1<<5) ;

    /* Watchdog initialization
     *************************/
 
    /* Remap
     *******/
//    BOARD_RemapRam();
}

#ifdef __DEBUG__
EBI *    const _EBI 	= EBI_BASE;
AIC *    const _AIC 	= AIC_BASE;
PIO *    const _PIO		= PIO_BASE;
USART *  const _US0 	= USART0_BASE;
USART *  const _US1 	= USART1_BASE;
TCC *    const _TC0 	= TC0_BASE;
TCC *    const _TC1 	= TC1_BASE;
TCC *    const _TC2 	= TC2_BASE;
TCB *    const _TCB 	= TCB_BASE;
WD  *    const _WD 		= WD_BASE;
PS *     const _PS 		= PS_BASE;
SF *     const _SF 		= SF_BASE;
#endif
