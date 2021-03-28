/*
 * basic pio, irq mode
 */
#include <stdlib.h>
#include <stdio.h>
#include "board.h"

extern void irq_enable();

#define LED_RED_PIN		(1<<1)
#define BTN_PIN			(1<<12)

#define PIOIRQ			(8)

volatile int pushed=0;

// PIO ISR : an irq is generated when the button is pressed, an when it is
// released so that we have to track for button state
void btn_isr()
{
	static int btn_state=0;		// track state 
	if (_PIO->ISR & BTN_PIN) {
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
	_PIO->IDR=LED_RED_PIN;	// disable interrupts
	_PIO->IFDR=LED_RED_PIN;	// disable deglitch
	_PIO->OER=LED_RED_PIN;	// pin configured as output (enable output)
	_PIO->PER=LED_RED_PIN;	// pin controlled by PIO

	// test to switch light on and off (to be done in step mode)
	_PIO->SODR=LED_RED_PIN;	// switch light on
	_PIO->CODR=LED_RED_PIN;	// switch light off

	// button on P12/FIQ PIN
	_PIO->IDR=BTN_PIN;		// disable interrupts
	_PIO->IFDR=BTN_PIN;		// disable deglitch (already done at the physical button level)
	_PIO->ODR=BTN_PIN;		// pin configured as input (disable output)
	_PIO->PER=BTN_PIN;		// pin controlled by PIO
	_PIO->IER=BTN_PIN;		// enable pin level change to generate an IRQ:
							// pushed/released --> 2 IRQ generated
	
	// configure AIC to capture PIO IRQ
	_AIC->SVR[PIOIRQ]=(unsigned long)btn_isr;
	_AIC->SMR[PIOIRQ]=(0x3<<5) | 0x1;			// irq triggered on positive edge, priority=1
	_AIC->IECR=1<<PIOIRQ;						// enable PIO irq to be captured
	
	irq_enable();
	
	while(1) {
		// wait for the button to be pushed
		if (pushed) {
			if (led_on) _PIO->CODR=LED_RED_PIN;		// switch light off
			else _PIO->SODR=LED_RED_PIN;			// switch light on
			led_on=!led_on;
			pushed=0;
		}
	}
	return 0;
}

