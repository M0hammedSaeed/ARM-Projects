/**************************************************************************************
 *  [File Name]	 : OS_program.c
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

/* Global variables */
OS_Task_t Global_Task[OS_NUMBER_OF_TASKS] = {0}; /* Array of Tasks */


/***********************   Public functions   *********************/

/***********************   Scheduler APIS   *********************/

void OS_voidStart(void)
{
	/* To Initialize the SysTick */
	MSTK_voidInit();
	/* To pass the scheduler function to the SysTick ISR */
	MSTK_voidSetPeriodicInterval(OS_TICK_PERIOD, OS_voidScheduler);
}

void OS_voidStop(void)
{
	MSTK_voidDisable();
	MSTK_voidInterruptDisable();
}

void OS_voidResume(void)
{
	MSTK_voidEnable();
	MSTK_voidInterruptEnable();
}

void OS_voidDispatcher (void)
{
	/* Check on all the tasks and execute any task with RunMe flag above zero*/
	for(u8 i = 0; i < OS_NUMBER_OF_TASKS; i++)
	{
		if(Global_Task[i].func && (Global_Task[i].RunMe > 0))
		{
			Global_Task[i].func();
			Global_Task[i].RunMe--;
		}
		else{}
	}
	/* To save the power between ticks when there is no tasks ready yet*/
	OS_voidGoToSleep();
}
/***************************************************************/

/***********************   Task APIS   *********************/

void OS_voidCreateTask(u8 Copy_u8ID , u32 Copy_u16delay , u32 Copy_u16period , void (* Copy_voidFunc) (void))
{
	/* assign task parameters to the right array index */
	if(Copy_u8ID < OS_NUMBER_OF_TASKS)
	{
		Global_Task[Copy_u8ID].firstDelay = Copy_u16delay;
		Global_Task[Copy_u8ID].period     = Copy_u16period;
		Global_Task[Copy_u8ID].func		  = Copy_voidFunc;
		Global_Task[Copy_u8ID].taskState  = OS_TASK_READY;
		Global_Task[Copy_u8ID].RunMe	  = 0;
	}
	else{}
}

void OS_voidDeleteTask (u8 Copy_u8ID)
{
	if(Global_Task[Copy_u8ID].func)
	{
		Global_Task[Copy_u8ID].firstDelay = 0;
		Global_Task[Copy_u8ID].period     = 0;
		Global_Task[Copy_u8ID].func		  = NULL_PTR;
		Global_Task[Copy_u8ID].RunMe	  = 0;
	}
	else{}
}

void OS_voidSetTaskState(u8 Copy_u8ID , OS_TaskStates_t Copy_state)
{
	if(Global_Task[Copy_u8ID].func)
	{
		Global_Task[Copy_u8ID].taskState  = Copy_state;
	}
	else{}
}
/***************************************************************/

/***********************   Private functions   *********************/

static void OS_voidScheduler(void)
{
	/* Co operative scheduling */
	for(u8 i = 0; i < OS_NUMBER_OF_TASKS; i++)
	{
		if(Global_Task[i].func && (Global_Task[i].taskState == OS_TASK_READY))
		{
			/* Time of the task has come */
			if(Global_Task[i].firstDelay == 0)
			{
				/* Dispatcher will check this flag in the while */
				Global_Task[i].RunMe++;

				/* Only if the task periodic will updated the initialDelay */
				if(Global_Task[i].period)
				{
					Global_Task[i].firstDelay = Global_Task[i].period - OS_TICK_PERIOD;
				}
				else{}
			}
			else
			{
				Global_Task[i].firstDelay -= OS_TICK_PERIOD;
			}
		}
		else{}
	}
}

static void OS_voidGoToSleep(void)
{
	__asm("WFI");	/* Wait for interrupt */
}
