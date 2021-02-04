/*
 * Uart.c
 *
 *  Created on: Jan 31, 2021
 *      Author: maanu
 * Arranged by: Kim Taehoon
 * */

#include "uart.h"
#include "haluart.h"

extern volatile PL011_t* Uart;

void HAL_uart_init(void)
{
    // Enable UART
    Uart->uartcr.bits.UARTEN = 0;
    Uart->uartcr.bits.TXE = 1;
    Uart->uartcr.bits.RXE = 1;
    Uart->uartcr.bits.UARTEN = 1;
}

void HAL_uart_put_char(uint8_t ch)
{
    while(Uart->uartfr.bits.TXFF);
    Uart->uartdr.all = (ch & 0xFF);
}

uint8_t HAL_uart_get_char(void)
{
	uint8_t data;

	while(Uart->uartfr.bits.RXFE);

    data = Uart->uartdr.all;

	//Check for an error flag
	if(data & 0xFFFFFF00)
	{
		//clear the error
		Uart->uartrsr.all = 0xFF;
		return 0;
	}

	return (uint8_t)(data&0xFF);
}