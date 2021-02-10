/*
 * task.c
 *
 *  Created on: Feb 8, 2021
 * Arranged by: Kim Taehoon
 */
#include "task.h"

static KernelTCB_t sTask_list[MAX_TASK_NUM]; 
static uint32_t sAllocated_tcb_index;

void Kernel_task_init(void)
{
    sAllocated_tcb_index = 0;

    for(uint32_t i=0;i<MAX_TASK_NUM;i++)
    {
        sTask_list[i].stack_base = (uint8_t*)(TASK_STACK_START+(i*USR_TASK_STACK_SIZE));
        sTask_list[i].sp = (uint32_t)(sTask_list[i].stack_base+USR_TASK_STACK_SIZE-4);

        sTask_list[i].sp -= sizeof(KernelTaskContext_t);
        KernelTaskContext_t* ctx = (KernelTaskContext_t*)sTask_list[i].sp;
        //Task context is stored at stack region.

        ctx->pc = 0;
        ctx->spsr = ARM_MODE_BIT_SYS;
        /*     이렇게 64개가 만들어짐. 전체 사이즈는 USR_TASK_STACK_SIZE, 즉, 1MB.
        *      각각의 task는 독립적인 프로세스로 간주함을 의미한다. 이는 추후에 scheduler에 의해 관리된다.
        *      ///////////////////// ->stack_base+USR_TASK_STACK_SIZE
        *      /      4byte        /
        *      ///////////////////// 
        *      /       Task        / ='KernelTaskContext_t'
        *      /      context      /
        *      ///////////////////// ->SP
        *      /                   /
        *      /       Stack       /
        *      /                   /
        *      /                   /
        *      ///////////////////// ->stack_base
        * 
        */
    }
}

uint32_t Kernel_task_create(KernelTaskFunc_t startFunc)
{
    KernelTCB_t* new_tcb = &sTask_list[sAllocated_tcb_index++];

    if(sAllocated_tcb_index>MAX_TASK_NUM)
    {
        return NOT_ENOUGH_TASK_NUM;
    }

    KernelTaskContext_t* ctx = (KernelTaskContext_t*)new_tcb->sp;
    ctx->pc = (uint32_t)startFunc;

    return (sAllocated_tcb_index-1);
}