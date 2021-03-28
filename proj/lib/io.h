/* io.h
 *
 * PIO Configure and PIO read/write ops
  */
 
#ifndef _IO_H_
#define _IO_H_

#include "board.h"

/* Pin mask */
#define IO_PIN0				(1)
#define IO_PIN1				(1<<1)
#define IO_PIN2				(1<<2)
#define IO_PIN3				(1<<3)
#define IO_PIN4				(1<<4)
#define IO_PIN5				(1<<5)
#define IO_PIN6				(1<<6)
#define IO_PIN7				(1<<7)
#define IO_PIN8				(1<<8)
#define IO_PIN9				(1<<9)
#define IO_PIN10			(1<<10)
#define IO_PIN11			(1<<11)
#define IO_PIN12			(1<<12)
#define IO_PIN13			(1<<13)
#define IO_PIN14			(1<<14)
#define IO_PIN15			(1<<15)
#define IO_PIN16			(1<<16)
#define IO_PIN17			(1<<17)
#define IO_PIN18			(1<<18)
#define IO_PIN19			(1<<19)
#define IO_PIN20			(1<<20)
#define IO_PIN21			(1<<21)
#define IO_PIN22			(1<<22)
#define IO_PIN23			(1<<23)
#define IO_PIN24			(1<<24)
#define IO_PIN25			(1<<25)
#define IO_PIN26			(1<<26)
#define IO_PIN27			(1<<27)
#define IO_PIN28			(1<<28)
#define IO_PIN29			(1<<29)
#define IO_PIN30			(1<<30)
#define IO_PIN31			(1<<31)

/* attributes */
#define IO_PIN_INPUT		(1<<0)
#define IO_PIN_OUTPUT		(1<<1)
#define IO_PIN_FUNC			(1<<2)
#define IO_PIN_DEGLITCH		(1<<3)
#define IO_PIN_IRQ_EN		(1<<4)

/* io_configure
 * configure pins referenced in 'pinmask' of specified port according to 
 * 'attr'
 *
 * returns 1 if success and 0 else
 */
int io_configure(PIO* p, uint32_t pinmask, uint32_t attr);

/* io_get_isr
 *
 * read the Interrupt Status Register to get the pending PIO IRQ and to
 * acknowledge the IRQ.
 */
uint32_t io_get_isr(PIO *p);

/* io_read
 *
 * read 32 bit data from port 'p', filter the result with mask
 */
uint32_t io_read(PIO *p, uint32_t mask);

/* io_set
 *
 * set HIGH 32 pins specified by mask to port 'p'
 * pins must have been configured as outputs
 */
void io_set(PIO *p, uint32_t mask);

/* io_clear
 *
 * set LOW 32 pins specified by mask to port 'p'
 */
void io_clear(PIO *p, uint32_t mask);

/* io_write
 *
 * write 32 bit data filtered by mask to port 'p'
 * '1' in val are written as HIGH level on port pins
 */
void io_write(PIO *p, uint32_t val, uint32_t mask);

/* io_write_n
 *
 * write 32 bit data filtered by mask to port 'p'
 * '1' in val are written as LOW level on port pins
 */
void io_write_n(PIO *p, uint32_t val, uint32_t mask);

#endif
