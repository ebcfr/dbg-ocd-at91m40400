/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
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
//         Headers
//------------------------------------------------------------------------------

#include "board.h"

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

#define	ARM_MODE_USR	 0x10      /* Normal User Mode */
#define ARM_MODE_FIQ     0x11      /* FIQ Fast Interrupts Mode */
#define ARM_MODE_IRQ     0x12      /* IRQ Standard Interrupts Mode */
#define ARM_MODE_SVC     0x13      /* Supervisor Interrupts Mode */
#define ARM_MODE_ABT     0x17      /* Abort Processing memory Faults Mode */
#define	ARM_MODE_UND	 0x1B      /* Undefined Instructions Mode */
#define	ARM_MODE_SYS	 0x1F      /* System Running in Priviledged Operating Mode */
#define	ARM_MODE_MASK	 0x1F

#define I_BIT            0x80      /* disable IRQ when I bit is set */
#define F_BIT            0x40      /* disable FIQ when F bit is set */

//------------------------------------------------------------------------------
//         Startup routine
//------------------------------------------------------------------------------

            .align      4
            .arm
        
/* Exception vectors
 *******************/
        .section    .vectors, "ax", %progbits

resetVector:
        ldr     pc, =resetHandler       /* Reset */
undefVector:
        ldr     pc, =undefHandler       /* Undefined instruction */
swiVector:
        ldr     pc, =swiHandler         /* Software interrupt */
prefetchAbortVector:
        ldr     pc, =prefetchAbortHandler /* Prefetch abort */
dataAbortVector:
        ldr     pc, =dataAbortHandler   /* Data abort */
reservedVector:
        b       reservedVector          /* Reserved for future use */
irqVector:
        ldr     pc, =irqHandler          /* Interrupt */
fiqVector:
        ldr     pc, =fiqHandler         /* Fast interrupt */

//------------------------------------------------------------------------------
/// Error Handlers
//------------------------------------------------------------------------------
        .section     .text.undefHandler
        .weak        undefHandler
        .type        undefHandler, %function
undefHandler:
        b       undefHandler
		.size        undefHandler, .-undefHandler
		
        .section     .text.swiHandler
        .weak        swiHandler
        .type        swiHandler, %function
swiHandler:
        b       swiHandler
		.size        swiHandler, .-swiHandler
		
        .section     .text.prefetchAbortHandler
        .weak        prefetchAbortHandler
        .type        prefetchAbortHandler, %function
prefetchAbortHandler:
        b       prefetchAbortHandler
		.size        prefetchAbortHandler, .-prefetchAbortHandler

        .section     .text.dataAbortHandler
        .weak        dataAbortHandler
        .type        dataAbortHandler, %function
dataAbortHandler:
        b       dataAbortHandler
		.size        dataAbortHandler, .-dataAbortHandler

//------------------------------------------------------------------------------
/// Handles a fast interrupt request by branching to the address defined in the
/// AIC.
//------------------------------------------------------------------------------
        .section     .text.fiqHandler
        .weak        fiqHandler
        .type        fiqHandler, %function
fiqHandler:
        b       fiqHandler
		.size        fiqHandler, .-fiqHandler
	
//------------------------------------------------------------------------------
/// Handles incoming interrupt requests by branching to the corresponding
/// handler, as defined in the AIC. Supports interrupt nesting.
//------------------------------------------------------------------------------
        .section     .text.irqHandler
        .weak        irqHandler
        .type        irqHandler, %function
irqHandler:

/* Save interrupt context on the stack to allow nesting */
        sub     lr, lr, #4
        stmdb   sp!, {lr}
        mrs     lr, SPSR
        stmdb   sp!, {r0, lr}

/* Write in the IVR to support Protect Mode */
        ldr     lr, =_AIC_IVR
        ldr     r0, [lr]
        str     lr, [lr]

/* Branch to interrupt handler in System mode */
        msr     CPSR_c, #ARM_MODE_SYS
        stmdb   sp!, {r1-r3, r12, lr}
        mov     lr, pc
        bx      r0
        ldmia   sp!, {r1-r3, r12, lr}
        msr     CPSR_c, #ARM_MODE_IRQ | I_BIT

/* Acknowledge interrupt */
        ldr     lr, =_AIC_EOICR
        str     lr, [lr]

/* Restore interrupt context and branch back to calling code */
        ldmia   sp!, {r0, lr}
        msr     SPSR_cxsf, lr
        ldmia   sp!, {pc}^
        
		.size  irqHandler, .-irqHandler

//------------------------------------------------------------------------------
/// Initializes the chip and branches to the main() function.
//------------------------------------------------------------------------------
        .section     .text.resetHandler
        .weak        resetHandler
        .type        resetHandler, %function
        .global      _start, _exit

_start:
resetHandler:

/* Dummy access to the .vectors section so it does not get optimized */
        ldr     r0, =resetVector

/* Set pc to actual code location (i.e. not in remap zone) */
	    ldr     pc, =1f

/* Perform low-level initialization of the chip using LowLevelInit() */
1:
        ldr     r4, =__usr_stack_top
        mov     sp, r4
	    ldr     r0, =LowLevelInit
        mov     lr, pc
        bx      r0

/* Initialize the relocate segment */
/*
        ldr     r0, =__relocate_load
        ldr     r1, =__relocate_start
        ldr     r2, =__relocate_end
1:
        cmp     r1, r2
        ldrcc   r3, [r0], #4
        strcc   r3, [r1], #4
        bcc     1b
*/
/* Clear the zero segment */
	    ldr     r0, =__bss_start
        ldr     r1, =__bss_end
        mov     r2, #0
1:
        cmp     r0, r1
        strcc   r2, [r0], #4
        bcc     1b

/* Initialize stack pointers for all ARM modes */
        msr     CPSR_c,#(ARM_MODE_IRQ | I_BIT | F_BIT)
        ldr     sp,=__irq_stack_top           /* set the IRQ stack pointer */

        msr     CPSR_c,#(ARM_MODE_FIQ | I_BIT | F_BIT)
        ldr     sp,=__fiq_stack_top           /* set the FIQ stack pointer */

        msr     CPSR_c,#(ARM_MODE_SVC | I_BIT | F_BIT)
        ldr     sp,=__svc_stack_top           /* set the SVC stack pointer */

        msr     CPSR_c,#(ARM_MODE_ABT | I_BIT | F_BIT)
        ldr     sp,=__abt_stack_top           /* set the ABT stack pointer */

        msr     CPSR_c,#(ARM_MODE_UND | I_BIT | F_BIT)
        ldr     sp,=__und_stack_top           /* set the UND stack pointer */

        msr     CPSR_c,#(ARM_MODE_SYS | F_BIT) /* System Mode (interrupt enabled) */
        ldr     sp,=__usr_stack_top           /* set the USR stack pointer */

/* Branch to main()
 ******************/
        ldr     r0, =main
        mov     lr, pc
        bx      r0

/* Loop indefinitely when program is finished */
_exit:
        b       _exit

		.size  resetHandler, .-resetHandler
