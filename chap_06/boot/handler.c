/*
 * handler.c
 *
 *  Created on: Feb 03, 2021
 *      Author: maanu
 * Arranged by: Kim Taehoon
 */
#include "stdbool.h"
#include "stdint.h"
#include "halinterrupt.h"

__attribute__ ((interrupt ("IRQ"))) void IRQ_handler(void)
{
    HAL_interrupt_run_handler();
}

__attribute__ ((interrupt ("FIQ"))) void FIQ_handler(void)
{
    while(1);
}