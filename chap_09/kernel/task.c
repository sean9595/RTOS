/*
 * task.c
 *
 *  Created on: Feb 8, 2021
 * Arranged by: Kim Taehoon
 */
#include "task.h"

static KernelTcb_t sTask_list[MAX_TASK_NUM]; 
static uint32_t sAllocated_tcb_index;

static uint32_t sCurrent_tcb_index;

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

uint32_t Kernel_task_create(KernelTaskFunc_t startFunc, uint32_t pri)
{
    KernelTcb_t* new_tcb = &sTask_list[sAllocated_tcb_index++];

    if (sAllocated_tcb_index > MAX_TASK_NUM)
    {
        return NOT_ENOUGH_TASK_NUM;
    }
    //new_tcb->priority = pri; //우선순위를 TCB에 등록

    new_tcb->pc = (uint32_t)startFunc;

    return (sAllocated_tcb_index - 1);
}

static KernelTcb_t* Scheduler_round_robin_algorithm(void)
{
    sCurrent_tcb_index++;
    sCurrent_tcb_index &= sAllocated_tcb_index;

    return &sTask_list[sAllocated_tcb_index];
}
/*
static KernelTcb_t* Scheduler_round_robin_algorithm(void)
{
    for(uint32_t i = 0;i<sAllocated_tcb_index;i++)
    {
        KernelTcb_t* pNextTcb = &sTask_list[i];
        if(pNextTcb != pNextTcb)
        {
            if(pNextTcb->priority<=sCurrent->priority) //pesudocode로 봐야한다...
            {
                return pNextTcb;
            }
        }
    }
}*/