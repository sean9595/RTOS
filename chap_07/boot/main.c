/*
 * main.c
 *
 *  Created on: Feb 02, 2021
 * Arranged by: Kim Taehoon
 */
#include "stdint.h"
#include "haluart.h"
#include "stdio.h"
#include "halinterrupt.h"

static void HW_init(void);
static void Printf_test(void);

int main()
{
    HW_init();

    uint32_t i = 100;
    while (i--)
    {
        HAL_uart_put_char('N');
    }
    HAL_uart_put_char('\n');

    putstr("Hello World!\n");

    Printf_test();

    while (1); //infinite loop

    /*    i = 100;
    while (i--)
    {
        uint8_t ch = HAL_uart_get_char();
        HAL_uart_put_char(ch);
    }*/
    return 0;
}

static void HW_init(void)
{
    HAL_interrupt_init(); //prior to uart_init()
    HAL_uart_init();
}

static void Printf_test(void)
{
    char *str = "Printf pointer test";
    char *nullptr = 0;
    uint32_t i = 5;

    debug_printf("%s\n", "Hello printf");
    debug_printf("output string pointer: %s\n", str);
    debug_printf("%s is null pointer, %u number\n", nullptr, 10);
    debug_printf("%u = 5\n", i);
    debug_printf("dec=%u hex=%x\n", 0xff, 0xff);
    debug_printf("print zero %u\n", 0);
}