/*
* haluart.h
*
*  Created on: Jan 31, 2021
*      Author: maanu
* Arranged by: Kim Taehoon 
*/

#ifndef HAL_HALUART_H_
#define HAL_HALUART_H_

void HAL_uart_init(void);
void HAL_uart_put_char(uint8_t ch);
uint8_t HAL_uart_get_char(void);

#endif /* HAL_HALUART_H_ */