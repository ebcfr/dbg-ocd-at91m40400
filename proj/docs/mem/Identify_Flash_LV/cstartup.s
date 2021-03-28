;------------------------------------------------------------------------------
;-         ATMEL Microcontroller Software Support  -  ROUSSET  -
;------------------------------------------------------------------------------
; The software is delivered "AS IS" without warranty or condition of any
; kind, either express, implied or statutory. This includes without
; limitation any warranty or condition with respect to merchantability or
; fitness for any particular purpose, or against the infringements of
; intellectual property rights of others.
;-----------------------------------------------------------------------------
;- File source          : cstartup.s
;- Object               : Boot for simulate Final Application version to be 
;-                        loaded in SRAM. Only change as the internal RAM address
;-                        and support the Semihosting
;- Compilation flag     : SEMIHOSTING => use the semihosting facilities
;-
;- 1.0 06/04/02 NL     : Creation
;------------------------------------------------------------------------------
				

;------------------------------------------------------------------------------
;- Area Definition
;-----------------
;- Must be defined as function to put first in the code as it must be mapped
;- at SRAM.
;------------------------------------------------------------------------------
                AREA        reset, CODE, READONLY

                ENTRY

;------------------------------------------------------------------------------
;- Exception vectors
;--------------------
;- In the ICE function your board as run the boot code and initialize the remap
;- feature. but these code it's location independant and can be emulate the csartup_fash
;- fonctionnality.
;- These vectors are read at RAM address. in Flash mode these vectors are at 0 
;- They absolutely requires to be in relative addresssing mode in order to 
;- guarantee a valid jump. For the moment, all are just looping (what may be 
;- dangerous in a final system). If an exception occurs before remap, this 
;- would result in an infinite loop. 
;------------------------------------------------------------------------------
                B           InitReset       ; reset
undefvec
                B           undefvec        ; Undefined Instruction
swivec
                B           swivec          ; Software Interrupt
pabtvec
                B           pabtvec         ; Prefetch Abort
dabtvec 
                B           dabtvec         ; Data Abort
rsvdvec
                B           rsvdvec         ; reserved
irqvec
                B           irqvec          ; reserved
fiqvec
                B           fiqvec          ; reserved


;------------------------------------------------------------------------------
;- Stack Sizes Definition
;------------------------
;- Interrupt Stack requires 3 words x 8 priority level x 4 bytes when using
;- the vectoring. This assume that the IRQ_ENTRY/IRQ_EXIT macro are used. 
;- The Interrupt Stack must be adjusted depending on the interrupt handlers.
;- Fast Interrupt is the same than Interrupt without priority level.
;- Other stacks are defined by default to save one word each.
;- The System stack size is not defined and is limited by the free internal 
;- SRAM. 
;- User stack size is not defined and is limited by the free external SRAM.
;------------------------------------------------------------------------------
IRQ_STACK_SIZE      EQU     (3*8*4)     ; 3 words per interrupt priority level
FIQ_STACK_SIZE      EQU     (3*4)       ; 3 words
ABT_STACK_SIZE      EQU     (1*4)       ; 1 word
UND_STACK_SIZE      EQU     (1*4)       ; 1 word

;------------------------------------------------------------------------------
;- Top of Stack Definition
;-------------------------
;- Fast Interrupt, Interrupt, Abort, Undefined and Supervisor Stack are located
;- at the top of internal memory in order to speed the exception handling 
;- context saving and restoring.
;- User (Application, C) Stack is located at the top of the external memory.
;------------------------------------------------------------------------------
RAM_SIZE            EQU     (4*1024)
RAM_BASE            EQU     (0x00000000)
RAM_LIMIT           EQU     (RAM_BASE + RAM_SIZE)


ARM_MODE_USER           EQU     0x10
ARM_MODE_FIQ            EQU     0x11
ARM_MODE_IRQ            EQU     0x12
ARM_MODE_SVC            EQU     0x13
ARM_MODE_ABORT          EQU     0x17
ARM_MODE_UNDEF          EQU     0x1B
ARM_MODE_SYS            EQU     0x1F

I_BIT                   EQU     0x80
F_BIT                   EQU     0x40
T_BIT                   EQU     0x20

;------------------------------------------------------------------------------
;- The reset handler before Remap
;--------------------------------
;- From here, the code is executed from SRAM address
;------------------------------------------------------------------------------
InitReset

                ldr     r0, =RAM_LIMIT


;- Set up Supervisor Mode and set Supervisor Mode Stack
                msr     CPSR_c, #ARM_MODE_SVC:OR:I_BIT:OR:F_BIT
                mov     r13, r0                     ; Init stack Sup
           
;------------------------------------------------------------------------------
;- Initialise C variables
;------------------------
;- Following labels are automatically generated by the linker. 
;- RO: Read-only = the code
;- RW: Read Write = the data pre-initialized and zero-initialized.
;- ZI: Zero-Initialized.
;- Pre-initialization values are located after the code area in the image.
;- Zero-initialized datas are mapped after the pre-initialized.
;- Note on the Data position : 
;- If using ARM SDT, when no -rw-base option is used for the linker, the 
;- data area is mapped after the code. You can map the data either in internal
;- SRAM ( -rw-base=0x40 or 0x34) or in external SRAM ( -rw-base=0x2000000 ).
;- Note also that to improve the code density, the pre_initialized data must 
;- be limited to a minimum.
;------------------------------------------------------------------------------
                IMPORT      |Image$$RO$$Limit|      ; End of ROM code (=start of ROM data)
                IMPORT      |Image$$RW$$Base|       ; Base of RAM to initialise
                IMPORT      |Image$$ZI$$Base|       ; Base and limit of area
                IMPORT      |Image$$ZI$$Limit|      ; to zero initialise

                ldr         r0, =|Image$$RO$$Limit| ; Get pointer to ROM data
                ldr         r1, =|Image$$RW$$Base|  ; and RAM copy
                ldr         r3, =|Image$$ZI$$Base|  ; Zero init base => top of initialised data
                cmp         r0, r1                  ; Check that they are different
                beq         NoRW
LoopRw          cmp         r1, r3                  ; Copy init data
                ldrcc       r2, [r0], #4
                strcc       r2, [r1], #4
                bcc         LoopRw
NoRW            ldr         r1, =|Image$$ZI$$Limit| ; Top of zero init segment
                mov         r2, #0
LoopZI          cmp         r3, r1                  ; Zero init
                strcc       r2, [r3], #4
                bcc         LoopZI
                
;------------------------------------------------------------------------------
;- Branch on C code Main function (with interworking)
;----------------------------------------------------
;- Branch must be performed by an interworking call as either an ARM or Thumb 
;- main C function must be supported. This makes the code not position-
;- independant. A Branch with link would generate errors 
;------------------------------------------------------------------------------
                IMPORT      main

                ldr         r0, =main
                mov         lr, pc
                bx          r0
                
	            END
