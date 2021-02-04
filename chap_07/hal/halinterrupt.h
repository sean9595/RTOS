/*
 * halinterrupt.h
 *
 *  Created on: Feb 03, 2021
 *      Author: maanu
 * Arranged by: Kim Taehoon
 */
#ifndef HAL_HALINTERRUPT_H_
#define HAL_HALINTERRUPT_H_

#define INTERRUPT_HANDLER_NUM 255

typedef void (*InterHdlr_fptr)(void);

void HAL_interrupt_init(void);
void HAL_interrupt_enable(uint32_t interrupt_num);
void HAL_interrupt_disable(uint32_t interrupt_num);
void HAL_interrupt_register_handler(InterHdlr_fptr handler, uint32_t interrupt_num);
void HAL_interrupt_run_handler(void);

#endif /* HAL_HALINTERRUPT_H_ */