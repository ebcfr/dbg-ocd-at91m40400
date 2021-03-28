/* io.h
 *
 * PIO Configure and PIO read/write ops
  */

#include <stdarg.h>
#include "io.h"

/* io_configure
 * configure pins referenced in 'pinmask' of specified port according to 
 * 'attr'
 *
 * returns 1 if success and 0 else
 */
int io_configure(PIO* p, uint32_t pinmask, uint32_t attr)
{
	p->IDR=pinmask;
	if (attr & IO_PIN_DEGLITCH) p->IFER=pinmask;
	else p->IFDR=pinmask;
	
	if (attr & IO_PIN_FUNC) {
		p->PDR=pinmask;
		return 1;
	}
	
	p->PER=pinmask;
	
	if (attr & IO_PIN_OUTPUT) p->OER=pinmask;
	else p->ODR=pinmask;			// pins are an input

	if (attr & IO_PIN_IRQ_EN) p->IER=pinmask;
	
	return 1;
}

/* io_get_isr
 *
 * read the Interrupt Status Register to get the pending PIO IRQ and to
 * acknowledge the IRQ.
 */
uint32_t io_get_isr(PIO *p)
{
	return p->ISR;
}

/* io_read
 *
 * read 32 bit data from port 'p', filter the result with mask
 */
uint32_t io_read(PIO *p, uint32_t mask)
{
	return p->PDSR & mask;
}

/* io_set
 *
 * set HIGH 32 pins specified by mask to port 'p'
 * pins must have been configured as outputs
 */
void io_set(PIO *p, uint32_t mask)
{
	p->SODR=mask;
}

/* io_clear
 *
 * set LOW 32 pins specified by mask to port 'p'
 */
void io_clear(PIO *p, uint32_t mask)
{
	p->CODR=mask;
}

/* io_write
 *
 * write 32 bit data filtered by mask to port 'p'
 * '1' in val are written as HIGH level on port pins
 */
void io_write(PIO *p, uint32_t val, uint32_t mask)
{
	p->CODR=(~val) & mask;
	p->SODR=val & mask;
}

/* io_write_n
 *
 * write 32 bit data filtered by mask to port 'p'
 * '1' in val are written as LOW level on port pins
 */
void io_write_n(PIO *p, uint32_t val, uint32_t mask)
{
	p->SODR=(~val) & mask;
	p->CODR=val & mask;
}
