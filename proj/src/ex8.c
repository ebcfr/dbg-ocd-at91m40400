/*
 * pio, irq mode, lib functions to encapsulate peripheral access
 */
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "io.h"
#include "irq.h"
#include "tc.h"

#define LED_RED_PIN		(1<<1)
#define LED_GREEN_PIN	(1<<2)
int led_on=0;

void tc_cb()
{
	if (led_on) io_clear(_PIO, LED_RED_PIN);	// switch light off
	else io_set(_PIO, LED_RED_PIN);				// switch light on
	led_on=!led_on;
}

int main()
{

	// control red led on P1/TIA0 PIN
	io_configure(_PIO, LED_RED_PIN | LED_GREEN_PIN, IO_PIN_OUTPUT);

	irq_enable();

	// configure timer
	tc_tick_ms(_TC0, 500, tc_cb);
	
	while(1) {
		io_set(_PIO, LED_GREEN_PIN);
		tc_delay_ms(_TC1, 500, NULL);
		io_clear(_PIO, LED_GREEN_PIN);
		tc_delay_ms(_TC1, 500, NULL);
	}
	return 0;
}

