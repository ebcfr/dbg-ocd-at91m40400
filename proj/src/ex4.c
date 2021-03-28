/*
 * pio, irq mode, lib functions to encapsulate peripheral access
 */
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "io.h"
#include "irq.h"

#define LED_RED_PIN		(1<<1)
#define BTN_PIN			(1<<12)

#define PIOIRQ			(8)

volatile int pushed=0;

// PIO ISR : an irq is generated when the button is pressed, an when it is
// released so that we have to track for button state
void btn_isr()
{
	static int btn_state=0;		// track state 
	if (io_get_isr(_PIO) & BTN_PIN) {
		if (!btn_state) {
			btn_state=1;
			pushed=1;
		} else {
			btn_state=0;
		}
	}
	
}


int main()
{
	int led_on=0;

	// control red led on P1/TIA0 PIN
	io_configure(_PIO, LED_RED_PIN, IO_PIN_OUTPUT);

	// test to switch light on and off (to be done in step mode)
	io_set(_PIO, LED_RED_PIN);	// switch light on
	io_clear(_PIO, LED_RED_PIN);	// switch light off

	// button on P12/FIQ PIN
	io_configure(_PIO, BTN_PIN, IO_PIN_INPUT|IO_PIN_IRQ_EN);
	
	// configure AIC to capture PIO IRQ
	irq_register(IRQ_ID_PIO, IRQ_PRIO_1|IRQ_TRIG_ON_RISING_EDGE, btn_isr);
	
	irq_enable();
	
	while(1) {
		// wait for the button to be pushed
		if (pushed) {
			if (led_on) io_clear(_PIO, LED_RED_PIN);	// switch light off
			else io_set(_PIO, LED_RED_PIN);				// switch light on
			led_on=!led_on;
			pushed=0;
		}
	}
	return 0;
}

