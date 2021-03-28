/*
 * basic pio, polling mode
 */
#include <stdlib.h>
#include <stdio.h>
#include "board.h"

#define LED_RED_PIN		(1<<1)
#define BTN_PIN			(1<<12)


#define MAIN1

#ifdef MAIN1
int main()
{
	int i;
	int led_on=0;
	int pushed=0;
	int evt_pushed=0;
	// control red led on P1/TIA0 PIN 
	_PIO->IDR=LED_RED_PIN;	// disable interrupts
	_PIO->IFDR=LED_RED_PIN;	// disable deglitch
	_PIO->OER=LED_RED_PIN;	// pin configured as output (enable output)
	_PIO->PER=LED_RED_PIN;	// pin controlled by PIO

	// test to switch light on and off (to be done in step mode)
	_PIO->SODR=LED_RED_PIN;	// switch light on
	_PIO->CODR=LED_RED_PIN;	// switch light off

	// control red led on P12/FIQ PIN
	_PIO->IDR=BTN_PIN;		// disable interrupts
	_PIO->IFDR=BTN_PIN;		// disable deglitch
	_PIO->ODR=BTN_PIN;		// pin configured as input (disable output)
	_PIO->PER=BTN_PIN;		// pin controlled by PIO
	
	while(1) {
		// detect pushed evt
		if (_PIO->PDSR & BTN_PIN) {
			if (!pushed) {
				pushed=1;
				evt_pushed=1;
			} else evt_pushed=0;
		} else {
			pushed=0;
		}
		
		if (evt_pushed) {
			if (led_on) _PIO->CODR=LED_RED_PIN;		// switch light off
			else _PIO->SODR=LED_RED_PIN;			// switch light on
			led_on=!led_on;
		}
		for (i=0; i<10000; i++) ;
	}
	return 0;
}
#endif

#ifdef MAIN2
// detect btn pushed transition
int btn_pushed()
{
    static uint16_t btn_state=0x0000;
    btn_state = (btn_state<<1) | ((_PIO->PDSR>>12) & 1) & 0x1FFF;
    if (btn_state==0x0FFF) return 1;
    return 0;
}

int main()
{
	int i;
	int led_on=0;
	// control red led on P1/TIA0 PIN
	_PIO->IDR=LED_RED_PIN;		// disable interrupts
	_PIO->IFDR=LED_RED_PIN;	// disable deglitch
	_PIO->OER=LED_RED_PIN;		// pin configured as output (enable output)
	_PIO->PER=LED_RED_PIN;		// pin controlled by PIO

	_PIO->SODR=LED_RED_PIN;	// switch light on
	_PIO->CODR=LED_RED_PIN;	// switch light off

	// control red led on P12/FIQ PIN
	_PIO->IDR=BTN_PIN;		// disable interrupts
	_PIO->IFDR=BTN_PIN;		// disable deglitch
	_PIO->ODR=BTN_PIN;		// pin configured as input (disable output)
	_PIO->PER=BTN_PIN;		// pin controlled by PIO
	while(1) {
		if (btn_pushed()) {
			if (led_on) _PIO->CODR=LED_RED_PIN;			
			else _PIO->SODR=LED_RED_PIN;
			led_on=!led_on;
		}
		for (i=0; i<10000; i++) ;
	}
	return 0;
}
#endif
