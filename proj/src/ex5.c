/*
 * pio, irq mode, lib functions
 * usart, polling mode, lib functions
 */
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "io.h"
#include "irq.h"
#include "uart.h"

#define BTN_PIN			(1<<12)

#define PIOIRQ			(8)

int cpt=0;
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
	// button config
	//// button on P12/FIQ PIN
	io_configure(_PIO, BTN_PIN, IO_PIN_INPUT|IO_PIN_IRQ_EN);
	//// configure AIC to capture PIO IRQ
	irq_register(IRQ_ID_PIO, IRQ_PRIO_1|IRQ_TRIG_ON_RISING_EDGE, btn_isr);
	
	// uart config
	uart_init(_US0, 115200, UART_8N1, NULL);
	uart_puts(_US0, "Hello World!\r\r");
	
	uart_puts(_US0,"\x1B[2J\x1B[H");

	uart_puts(_US0,"We display a message here");

	// positionnement du curseur ligne 20, col 5
	uart_puts(_US0,"\x1B[15;5H");

	// on écrit en couleur
	uart_puts(_US0,"\x1B[31mSome text in colour\r\n\x1B[0m");
	irq_enable();
	
	while(1) {
		// wait for the button to be pushed
		if (pushed) {
			pushed=0;
			uart_printf(_US0, "UART(0x%x), cpt = %d\r\n",_US0,++cpt);
		}
	}
	return 0;
}

