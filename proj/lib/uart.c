#include <stdarg.h>
#include "uart.h"
#include "io.h"
#include "irq.h"
#include "util.h"

static OnUartRx callback0=0;
static OnUartRx callback1=0;

void uart0_isr()
{
	if ((_US0->CSR & 0x01) && callback0) callback0(_US0->RHR);
}

void uart1_isr()
{
	if ((_US1->CSR & 0x01) && callback0) callback1(_US1->RHR);
}

/*
 * uart_init : polling Tx and IRQ Rx if cb is defined, else polling Rx
 */
int uart_init(USART *u, uint32_t baud, uint32_t mode, OnUartRx cb)
{
    if (u==_US0) {					// TxD -> P14 and RxD -> P15
    	io_configure(_PIO, 0x3<<14, IO_PIN_FUNC);
    } else if (u==_US1) {			// TxD -> P21 and RxD -> P22
    	io_configure(_PIO, 0x3<<21, IO_PIN_FUNC);
    } else return 0;
    
    u->IDR = 0x3FF;					// disable interrupts
    
    u->CR = 0xAC;					// TxD and RxD reset, disable TxD and RxD

	u->MR = mode & 0x00003EC0;		// assert Asynchronous behavior
	
	u->BRGR = (MCLK)/16/baud;		// baud generator config
  
    if (cb) {
	    if (u==_US0) {
	        callback0=cb;
	        irq_register(IRQ_ID_US0,IRQ_PRIO_2|IRQ_TRIG_ON_RISING_EDGE,(Handler_t)uart0_isr);
	    } else if (u==_US1) {
	        if (cb) callback1=cb;
	        irq_register(IRQ_ID_US1,IRQ_PRIO_1|IRQ_TRIG_ON_RISING_EDGE,(Handler_t)uart1_isr);
	    } else return 0;
		u->IER=0x1;					// enable RxReady interrupt
    }    
    
    u->CR=0x50;					// enable TxD and RxD
    return 1;
}

/*
 * uart_getc : get a char from the serial link (blocking)
 */
char uart_getc(USART *u)
{
  while (!(u->CSR & 0x01));			// wait for RHR full
  return (char)(u->RHR);			// get the received char from RHR
}

/*
 * uart_getchar : check if a char has been received from the serial link
 * (non-blocking)
 */
int uart_getchar(USART *u, char *pChar)
{
	if((u->CSR & 0x01) != 0) {
		*pChar = (char)(u->RHR);
		return 1;
	}
	return 0;
}
/*
 * uart_putc : send a char over the serial link (polling)
 */
void uart_putc(USART *u, char c)
{
  while (!(u->CSR & 0x2));				// wait for THR empty
  u->THR = c;						// send char to THR
}

/*
 * uart_puts : send a string over the serial link (polling)
 */
void uart_puts(USART *u, char *s)
{
  if (s)
    while (*s) uart_putc(u, *s++);
}

/*
 * uart_printf : print formatted text to serial link
 */
void uart_printf(USART* u, const char* fmt, ...)
{
	va_list        ap;
	char          *p;
	char           ch;
	unsigned long  ul;
	char           s[34];
	
	va_start(ap, fmt);
	while (*fmt != '\0') {
		if (*fmt =='%') {
			switch (*++fmt) {
				case '%':
					uart_putc(u,'%');
					break;
				case 'c':
					ch = va_arg(ap, int);
					uart_putc(u, ch);
					break;
				case 's':
					p = va_arg(ap, char *);
					uart_puts(u, p);
					break;
				case 'd':
					ul = va_arg(ap, long);
					if ((long)ul < 0) {
						uart_putc(u, '-');
						ul = -(long)ul;
					}
					num2str(s, ul, 10);
					uart_puts(u, s);
					break;
				case 'u':
					ul = va_arg(ap, unsigned int);
					num2str(s, ul, 10);
					uart_puts(u, s);
					break;
				case 'x':
					ul = va_arg(ap, unsigned int);
					num2str(s, ul, 16);
					uart_puts(u, s);
					break;
				default:
				    uart_putc(u, *fmt);
			}
		} else uart_putc(u, *fmt);
		fmt++;
	}
	va_end(ap);
}
