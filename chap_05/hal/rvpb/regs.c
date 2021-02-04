/*
 * regs.c
 *
 *  Created on: Jan 31, 2021
 *      Author: maanu
 * Arranged by: Kim Taehoon
 */

#include "uart.h"

volatile PL011_t* Uart = (PL011_t*)UART_BASE_ADDRESS0;
