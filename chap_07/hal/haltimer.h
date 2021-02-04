/*
 * haltimer.h
 *
 * Arranged by: Kim Taehoon (Feb 04, 2021)
 */
#ifndef HAL_HALTIMER_H_
#define HAL_HALTIMER_H_

void HAL_timer_init(void);
uint32_t HAL_timer_get_1ms_counter(void);

#endif /* HAL_HALTIMER_H_ */