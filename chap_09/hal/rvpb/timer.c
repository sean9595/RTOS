/*
 * Timer.c
 *
 *  Created on: Sep 27, 2018
 *      Author: yiman
 * Arranged by: Kim Taehoon
 */

#include "stdint.h"
#include "timer.h"
#include "haltimer.h"
#include "halinterrupt.h"

extern volatile Timer_t* Timer;

static void interrupt_handler(void);

static uint32_t internal_1ms_counter;

void HAL_timer_init(void)
{
    // interface reset
    Timer->timerxcontrol.bits.TimerEn = 0; //1.Off timer
    Timer->timerxcontrol.bits.TimerMode = 0; //2.Set timer as 'free-running mode'
    Timer->timerxcontrol.bits.OneShot = 0; 
    Timer->timerxcontrol.bits.TimerSize = 0; //3.16bit counter
    Timer->timerxcontrol.bits.TimerPre = 0; //4.Prescaler divider '1'
    Timer->timerxcontrol.bits.IntEnable = 1; //5.On interrupt
    Timer->timerxload = 0; //6.Load reg. on
    Timer->timerxvalue = 0xFFFFFFFF; //7.Set counter reg. '0xFFFFFFFF'

    // set periodic mode
    Timer->timerxcontrol.bits.TimerMode = TIMER_PERIOIC; //->'1'use Periodic mode
    Timer->timerxcontrol.bits.TimerSize = TIMER_32BIT_COUNTER; //->'1'
    Timer->timerxcontrol.bits.OneShot = 0;
    Timer->timerxcontrol.bits.TimerPre = 0;
    Timer->timerxcontrol.bits.IntEnable = 1;

//    uint32_t interval = TIMER_10HZ_INTERVAL / 100;
    uint32_t interval_1ms = TIMER_1MZ_INTERVAL / 1000;

    Timer->timerxload = interval_1ms;
    Timer->timerxcontrol.bits.TimerEn = 1;

    internal_1ms_counter = 0;

    // Register Timer interrupt handler
    HAL_interrupt_enable(TIMER_INTERRUPT);
    HAL_interrupt_register_handler(interrupt_handler, TIMER_INTERRUPT);
}


uint32_t HAL_timer_get_1ms_counter(void)
{
    return internal_1ms_counter;
}

static void interrupt_handler(void)
{
    internal_1ms_counter++;

    Timer->timerxintclr = 1;
}
