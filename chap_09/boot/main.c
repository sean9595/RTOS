/*
 * main.c
 *
 *  Created on: Feb 8, 2021
 * Arranged by: Kim Taehoon
 */
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "haluart.h"
#include "halinterrupt.h"
#include "haltimer.h"
#include "task.h"

static void HW_init(void);
static void Kernel_init(void);

static void Printf_test(void);
static void Timer_test(void);

void User_task0(void);
void User_task1(void);
void User_task2(void);

int main(void)
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

    Timer_test();

    Kernel_init();

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
    HAL_timer_init();
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

static void Timer_test(void)
{
    while(1)
    {
        debug_printf("Current count : %u\n", HAL_timer_get_1ms_counter());
        delay(1000);
    }
}

static void Kernel_init(void)
{
    uint32_t taskID;

    Kernel_task_init();

    taskID = Kernel_task_create(User_task0);
    if(NOT_ENOUGH_TASK_NUM == taskID)
    {
        putstr("Task0 creation failed\n");
    }

    taskID = Kernel_task_create(User_task1);
    if(NOT_ENOUGH_TASK_NUM == taskID)
    {
        putstr("Task1 creation failed\n");
    }

    taskID = Kernel_task_create(User_task2);
    if(NOT_ENOUGH_TASK_NUM == taskID)
    {
        putstr("Task2 creation failed\n");
    }
}

void User_task0(void)
{
    debug_printf("User Task #0\n");
    while(1);
}

void User_task1(void)
{
    debug_printf("User Task #1\n");
    while(1);
}

void User_task2(void)
{
    debug_printf("User Task #2\n");
    while(1);
}