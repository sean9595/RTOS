/*
 * armcpu.h
 *
 *  Created on: Sep 21, 2018
 *      Author: maanu
 * Arranged by: Kim Taehoon (Feb 02, 2021)
 */
#ifndef LIB_ARMCPU_H_
#define LIB_ARMCPU_H_

void enable_irq(void);
void enable_fiq(void);
void disable_irq(void);
void disable_fiq(void);

#endif /* LIB_ARMCPU_H_ */