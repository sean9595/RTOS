/*
 * stdlib.c
 *
 * Arranged by: Kim Taehoon (Feb 04, 2021)
 */
#include "stdlib.h"

void delay(uint32_t ms)
{
    uint32_t goal = HAL_timer_get_1ms_counter() + ms;

    while(goal != HAL_timer_get_1ms_counter());
}