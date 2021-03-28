#include "tc.h"
#include "irq.h"

/* timerX_isr
 *   timerX ISR (Interrupt Service Routine)
 */
static OnTick callback0=0;
static OnTick callback1=0;
static OnTick callback2=0;

void tc0_isr()
{
    if ((_TC0->SR & (1<<4)) && callback0) callback0();
}

void tc1_isr()
{
    if ((_TC1->SR & (1<<4)) && callback1) callback1();
}

void tc2_isr()
{
    if ((_TC2->SR & (1<<4)) && callback2) callback2();
}


/* tc_tick_ms
 *   setup timer to call cb function periodically, each tick_ms
 *   if no callback is provided, no irq will be generated
 */
int tc_tick_ms(TCC *tc, uint32_t tick_ms, OnTick cb)
{
	tc->SR;									// acknowledge pending irq
	tc->IER = 0xFF;							// disable irq
	
	tc->CCR = 2;							// disable clock
	
	tc->CMR = (1<<15) | (1<<14) | 0x4;		// clk=MCLK/1024, WAVEFORM, reset
											// and restart counter on match 
											// with RC
	tc->RC = (MCLK/1000*tick_ms/1024) & 0xFFFF;
	
    if (cb) {
	    if (tc==_TC0) {
	        if (cb) callback0=cb;
	        irq_register(IRQ_ID_TC0, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc0_isr);
	    } else if (tc==_TC1) {
	        if (cb) callback1=cb;
	        irq_register(IRQ_ID_TC1, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc1_isr);
	    } else if (tc==_TC2) {
	        if (cb) callback2=cb;
	        irq_register(IRQ_ID_TC2, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc2_isr);
	    } 
        tc->IER = 1<<4;
	    tc->CCR = 0x5;			// enable clock, reset and start counting
    } else {
    	return 0;
	}

    return 1;
}


/* tc_delay_ms
 *   timer configured to generate a delay in ms
 *   if cb is defined, the function returns immediatly and an irq is generated
 *   after the delay is over, else, the function waits for the end of the 
 *   delay
 */
int tc_delay_ms(TCC *tc, uint32_t ms, OnTick cb)
{
	tc->SR;									// acknowledge pending irq
	tc->IER = 0xFF;							// disable irq
	
	tc->CCR = 2;							// disable clock
	
	tc->CMR = (1<<15) | (3<<6) | 0x4;		// clk=MCLK/1024, WAVEFORM, stop
											// and disable clk on match with 
											// RC
	tc->RC = (MCLK/1000*ms/1024) &0xFFFF;
	
    if (cb) {
	    if (tc==_TC0) {
	        if (cb) callback0=cb;
	        irq_register(IRQ_ID_TC0, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc0_isr);
	    } else if (tc==_TC1) {
	        if (cb) callback1=cb;
	        irq_register(IRQ_ID_TC1, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc1_isr);
	    } else if (tc==_TC2) {
	        if (cb) callback2=cb;
	        irq_register(IRQ_ID_TC2, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc2_isr);
	    } 
        tc->IER = 1<<4;
    	tc->CCR = 0x5;			// enable clock, reset and start counting
    } else {
    	tc->CCR = 0x5;			// enable clock, reset and start counting
		while (!(tc->SR & (1<<4))) ;
	}

    return 1;
}


/* tc_delay_us
 *   timer configured to generate a delay in ms
 *   if cb is defined, the function returns immediatly and an irq is generated
 *   after the delay is over, else, the function waits for the end of the 
 *   delay
 */
int tc_delay_us(TCC *tc, uint32_t us, OnTick cb)
{
	tc->SR;									// acknowledge pending irq
	tc->IER = 0xFF;							// disable irq
	
	tc->CCR = 2;							// disable clock
	
	tc->CMR = (1<<15) | (3<<6);				// clk=MCLK/2, WAVEFORM, stop
											// and disable clk on match with 
											// RC
	tc->RC = (MCLK/1000*us/2000) &0xFFFF;
	
    if (cb) {
	    if (tc==_TC0) {
	        if (cb) callback0=cb;
	        irq_register(IRQ_ID_TC0, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc0_isr);
	    } else if (tc==_TC1) {
	        if (cb) callback1=cb;
	        irq_register(IRQ_ID_TC1, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc1_isr);
	    } else if (tc==_TC2) {
	        if (cb) callback2=cb;
	        irq_register(IRQ_ID_TC2, IRQ_PRIO_5|IRQ_TRIG_ON_RISING_EDGE, (Handler_t)tc2_isr);
	    } 
        tc->IER = 1<<4;
    	tc->CCR = 0x5;			// enable clock, reset and start counting
    } else {
    	tc->CCR = 0x5;			// enable clock, reset and start counting
		while (!(tc->SR & (1<<4))) ;
	}

    return 1;
}


/* tc_start
 *   start counting
 */
void tc_start(TCC *tc)
{
    tc->CCR = 0x5;			// enable clock, reset and start counting
}

/* tc_stop
 *   stop and reset counting
 */
void tc_stop(TCC *tc)
{
    tc->CCR = 2;			// disable clock
}

