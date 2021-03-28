#ifndef _UART_H_
#define _UART_H_

#include "board.h"


typedef void (*OnUartRx)(char c);


// Definitions for typical UART 'mode' settings
#define UART_CHAR_5       (0x0<<6)
#define UART_CHAR_6       (0x1<<6)
#define UART_CHAR_7       (0x2<<6)
#define UART_CHAR_8       (0x3<<6)

#define UART_STOP_1       (0x0<<12)
#define UART_STOP_1_5     (0x1<<12)
#define UART_STOP_2       (0x2<<12)

#define UART_PAR_EVEN     (0x0<<9)
#define UART_PAR_ODD      (0x1<<9)
#define UART_PAR_0        (0x2<<9)
#define UART_PAR_1        (0x3<<9)
#define UART_PAR_NO       (0x4<<9)

#define UART_8N1          (UART_CHAR_8 | UART_PAR_NO   | UART_STOP_1)
#define UART_7N1          (UART_CHAR_7 | UART_PAR_NO   | UART_STOP_1)
#define UART_8N2          (UART_CHAR_8 | UART_PAR_NO   | UART_STOP_2)
#define UART_7N2          (UART_CHAR_7 | UART_PAR_NO   | UART_STOP_2)
#define UART_8E1          (UART_CHAR_8 | UART_PAR_EVEN | UART_STOP_1)
#define UART_7E1          (UART_CHAR_7 | UART_PAR_EVEN | UART_STOP_1)
#define UART_8E2          (UART_CHAR_8 | UART_PAR_EVEN | UART_STOP_2)
#define UART_7E2          (UART_CHAR_7 | UART_PAR_EVEN | UART_STOP_2)
#define UART_8O1          (UART_CHAR_8 | UART_PAR_ODD  | UART_STOP_1)
#define UART_7O1          (UART_CHAR_7 | UART_PAR_ODD  | UART_STOP_1)
#define UART_8O2          (UART_CHAR_8 | UART_PAR_ODD  | UART_STOP_2)
#define UART_7O2          (UART_CHAR_7 | UART_PAR_ODD  | UART_STOP_2)

/*
 * uart_init : initialize with baud, line mode parameters,
 *             polling Tx and IRQ Rx
 */
int uart_init(USART *u, uint32_t baud, uint32_t mode, OnUartRx cb);

/*
 * uart_getc : get a char from the serial link (polling)
 */
char uart_getc(USART *u);

/*
 * uart_getchar : check if a char has been received from the serial link
 * (non-blocking)
 */
int uart_getchar(USART *u, char *pChar);

/*
 * uart_putc : send a char over the serial link (polling)
 */
void uart_putc(USART *u, char c);

/*
 * uart_puts : send a string over the serial link (polling)
 */
void uart_puts(USART *u, char *s);

/*
 * uart_printf : print formatted text to serial link
 */
void uart_printf(USART *u, const char* fmt, ...);

#endif
