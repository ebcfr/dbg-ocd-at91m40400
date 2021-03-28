/*
 * uart, polling Tx, irq Rx
 */
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "uart.h"
#include "util.h"

static void on_rx_cb(char c)
{
	char  s[34];
	num2str(s,c,16);
	uart_puts(_US0, " 0x");
	uart_puts(_US0, s);
}

int main()
{
	uart_init(_US0,115200,UART_8N1,on_rx_cb);

	uart_puts(_US0,"\x1B[2J\x1B[H");

	uart_puts(_US0,"We display a message here");

	// positionnement du curseur ligne 20, col 5
	uart_puts(_US0,"\x1B[20;5H");

	// on écrit en couleur
	uart_puts(_US0,"\x1B[31mEnter some text please:\x1B[0m");

	irq_enable();

	while (1) ;

	return 1;
}
