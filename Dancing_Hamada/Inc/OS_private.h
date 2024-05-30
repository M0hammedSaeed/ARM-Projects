/**************************************************************************************
 *  [File Name]	 :  OS_private.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_

/* Task data type to hold task information */
typedef struct
{
	OS_TaskStates_t taskState;
	u8 RunMe;
	u32 period;
	u32 firstDelay;
	void (*func)(void);
}OS_Task_t;


/******* Private functions *******/
static void OS_voidScheduler (void);
static void OS_voidGoToSleep(void);

#endif /* OS_PRIVATE_H_ */
