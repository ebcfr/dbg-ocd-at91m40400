#ifndef _TIMER_H_
#define _TIMER_H_

#include "board.h"

typedef void (*OnTick)(void);

/* tc_tick_ms
 *   setup timer to call cb function periodically, each tick_ms
 */
int tc_tick_ms(TCC *tc, uint32_t tick_ms, OnTick cb);

/* tc_delay_ms
 *   timer configured to generate a delay in ms
 *   if cb is defined, the function returns immediatly and an irq is generated
 *   after the delay is over, else, the function waits for the end of the 
 *   delay
 */
int tc_delay_ms(TCC *tc, uint32_t ms, OnTick cb);

/* tc_delay_us
 *   timer configured to generate a delay in ms
 *   if cb is defined, the function returns immediatly and an irq is generated
 *   after the delay is over, else, the function waits for the end of the 
 *   delay
 */
int tc_delay_us(TCC *tc, uint32_t us, OnTick cb);

/* tc_start
 *   start counting
 */
void tc_start(TCC *tc);

/* tc_stop
 *   stop counting
 */
void tc_stop(TCC *tc);

#endif
