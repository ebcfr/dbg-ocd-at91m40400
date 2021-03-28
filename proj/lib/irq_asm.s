      
        .text
        .arm
        .global  irq_enable, irq_disable
        
irq_enable:
        mrs     r12, cpsr
        bic     r12, r12, #0xC0
        msr     cpsr_c, r12
        mov     pc, lr
        
        
irq_disable:
        mrs     r12, cpsr
        orr     r12, r12, #0xC0
        msr     cpsr_c, r12
        mov     pc, lr

		.end
		