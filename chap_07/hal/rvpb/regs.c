/*
 * regs.c
 *
 *  Created on: Feb 02, 2021
 *      Author: maanu
 * Arranged by: Kim Taehoon
 */

#include "uart.h"
#include "interrupt.h"
#include "timer.h"

volatile PL011_t* Uart = (PL011_t*)UART_BASE_ADDRESS0;
volatile GicCput_t* GicCpu = (GicCput_t*)GIC_CPU_BASE;
volatile GicDist_t* GicDist = (GicDist_t*)GIC_DIST_BASE;
volatile Timer_t* Timer = (Timer_t*)TIMER_CPU_BASE;