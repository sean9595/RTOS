/*
 * task.c
 *
 *  Created on: Feb 8, 2021
 * Arranged by: Kim Taehoon
 */
#include "task.h"

static KernelTcb_t sTask_list[MAX_TASK_NUM]; 
static uint32_t sAllocated_tcb_index;

void Kernel_task_init(void)
{
    sAllocated_tcb_index = 0;

    for(uint32_t i = 0 ; i < MAX_TASK_NUM ; i++)
    {
        sTask_list[i].spsr = ARM_MODE_BIT_SYS;
        sTask_list[i].lr = 0;
        sTask_list[i].pc = 0;

        sTask_list[i].stack_base = (uint8_t*)(TASK_STACK_START + (i * USR_TASK_STACK_SIZE));
        sTask_list[i].sp = (uint32_t)sTask_list[i].stack_base + USR_TASK_STACK_SIZE - 4;
    }
}

uint32_t Kernel_task_create(KernelTaskFunc_t startFunc)
{
    KernelTcb_t* new_tcb = &sTask_list[sAllocated_tcb_index++];

    if (sAllocated_tcb_index > MAX_TASK_NUM)
    {
        return NOT_ENOUGH_TASK_NUM;
    }

    new_tcb->pc = (uint32_t)startFunc;

    return (sAllocated_tcb_index - 1);
}