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

/*------------------------------------------------------------------------------
 *      Linker script for running in internal SRAM on the AT91SAM7X256.
 *----------------------------------------------------------------------------*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

/* The sizes of the stacks used by the application. NOTE: you need to adjust */
USR_STACK_SIZE = 1024;
IRQ_STACK_SIZE = 128;
FIQ_STACK_SIZE = 0;
SVC_STACK_SIZE = 0;
ABT_STACK_SIZE = 0;
UND_STACK_SIZE = 0;

HEAP_END = 0x00080000;

MEMORY
{
	iram (rwx)  : ORIGIN = 0x00000000, LENGTH = 4k
    xram (rwx)  : ORIGIN = 0x02000000, LENGTH = 512k
    xflash (rx) : ORIGIN = 0x01000000, LENGTH = 128k
}

SECTIONS
{
    .vectors : {
        KEEP(*(.vectors));
    } >iram

	.text : {
        *(.text .text.* .gnu.linkonce.t.*)
         /* The sections are named 'glue' because they glue together ARM and Thumb
		code.  I assume the 7 is there because the ARM7 was the first one to
		support Thumb code.  .glue_7 is used for ARM code calling Thumb code,
		and .glue_7t is used for Thumb code calling ARM code. */
        *(.glue_7t) *(.glue_7)
		*(.vfp11_veneer)
		*(.v4_bx)
		*(.iplt .igot.* .rel.*)
		end = .;
	} >xram
	
	.rodata : {
       KEEP(*(.rodata .rodata.*));
        . = ALIGN(4);
	} >xram

/*	
    .relocate : {
        . = ALIGN(4);
        __relocate_load = LOADADDR (.relocate);
        __relocate_start = .;
         *(.data .data.*)
        . = ALIGN(4);
        __relocate_end = .;
    } >xram AT>iram
*/
	.data : {
		__data_start = .;
		*(.data .data.*)
		. = ALIGN(4);
        __data_end = .;
	} >xram
	
    .bss (NOLOAD) : {
        __bss_start = .;
        *(.bss* .gnu.linkonce.b.*)
        . = ALIGN(4);
        *(COMMON)
        . = ALIGN(4);
        __bss_end = .;
    } >xram
    
    .noinit (NOLOAD) : {
        *(.noinit)
     } >xram
     
    .stack (NOLOAD) : {
        . = ALIGN (8);
        __stack_start = . ;
		
        . += IRQ_STACK_SIZE;
        . = ALIGN (4);
        __irq_stack_top = . ;

        . += FIQ_STACK_SIZE;
        . = ALIGN (4);
        __fiq_stack_top = . ;

        . += SVC_STACK_SIZE;
        . = ALIGN (4);
        __svc_stack_top = . ;

        . += ABT_STACK_SIZE;
        . = ALIGN (4);
        __abt_stack_top = . ;

        . += UND_STACK_SIZE;
        . = ALIGN (4);
        __und_stack_top = . ;

        . += USR_STACK_SIZE;
        . = ALIGN (4);
        __usr_stack_top = . ;

        __stack_end = .;
    } >xram
    
    __heap_start = __stack_end ;
    __heap_end = HEAP_END ;
/*
   .heap (NOLOAD) : {
        . = ALIGN (8);
		__heap_start = .;
		. = HEAP_END - 1 ;
        . = ALIGN (8);
		__heap_end = . +1;
   } >xram
*/
}
