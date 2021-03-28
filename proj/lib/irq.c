#include "irq.h"

/* irq_register: register an isr, enable channel interrupt
 *
 *   id       : peripheral irq id
 *   priority : priority (0 to 7 (greater priority))
 *   isr      : ISR
 */
int irq_register(uint32_t id, uint32_t mode, Handler_t isr)
{
	if (!(IRQ_ALL_INT & (1<<id))) return 0;
	
	mode = (mode & (0x3<<5)) | (mode & 0x7);
	
    // Disable the interrupt first
    _AIC->IDCR = 1 << id;
    
    // Configure mode and handler
	_AIC->SVR[id] = (unsigned long)isr;
	_AIC->SMR[id] = mode;
	
    // Clear interrupt
    _AIC->ICCR = 1 << id;
    
	_AIC->IECR = 1 << id;			// enable irq

	return 1;
}

/* irq_unregister: unregister slot, disable irq handling
 *
 *   channel : irq vic channel
 *   slot    : slot to be deallocated
 */
void irq_unregister(uint32_t id)
{
	_AIC->IDCR = 1 << id;
}
