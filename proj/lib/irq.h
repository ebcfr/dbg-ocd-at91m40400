#ifndef _IRQ_H_
#define _IRQ_H_

#include "board.h"

typedef void (*Handler_t)(void);

/* peripheral id */
#define IRQ_ID_FIQ		( 0) // Advanced Interrupt Controller (FIQ)
#define IRQ_ID_SWI		( 1) // System Peripheral
#define IRQ_ID_US0		( 2) // USART 0
#define IRQ_ID_US1		( 3) // USART 1
#define IRQ_ID_TC0		( 4) // Timer Counter 0
#define IRQ_ID_TC1		( 5) // Timer Counter 1
#define IRQ_ID_TC2		( 6) // Timer Counter 2
#define IRQ_ID_WDT		( 7) // Watchdog Timer
#define IRQ_ID_PIO		( 8) // Parallel IO Controller
/* ID 9 to 15 are reserved */
#define IRQ_ID_IRQ0		(16) // Advanced Interrupt Controller (IRQ0)
#define IRQ_ID_IRQ1		(17) // Advanced Interrupt Controller (IRQ1)
#define IRQ_ID_IRQ2		(18) // Advanced Interrupt Controller (IRQ2)
/* ID 19 to 31 are reserved */
#define IRQ_ALL_INT		(0x000701FF) // ALL VALID INTERRUPTS

/* mode */
#define	IRQ_PRIO_0		(0)
#define	IRQ_PRIO_1		(1)
#define	IRQ_PRIO_2		(2)
#define	IRQ_PRIO_3		(3)
#define	IRQ_PRIO_4		(4)
#define	IRQ_PRIO_5		(5)
#define	IRQ_PRIO_6		(6)
#define	IRQ_PRIO_7		(7)
#define IRQ_TRIG_ON_LOW_LEVEL		(0<<5)
#define IRQ_TRIG_ON_FALLING_EDGE	(1<<5)
#define IRQ_TRIG_ON_HIGH_LEVEL		(2<<5)
#define IRQ_TRIG_ON_RISING_EDGE		(3<<5)

/* irq/fiq enable/disable in cpsr */
void  irq_enable();
void  irq_disable();

/* irq_register: register an isr, enable channel interrupt
 *
 *   id       : peripheral irq id
 *   priority : priority (0 to 7 (greater priority))
 *   isr      : ISR
 */
int   irq_register(uint32_t id, uint32_t mode, Handler_t isr);

/* irq_unregister: unregister slot, disable irq handling
 *
 *   channel : irq vic channel
 *   slot    : slot to be deallocated
 */
void  irq_unregister(uint32_t id);

#endif
