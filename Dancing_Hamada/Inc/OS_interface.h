/**************************************************************************************
 *  [File Name]	 :  OS_interface.h
 *	[Version]	 : V01
 *  [Author]	 : Mohamed Saeed
 **************************************************************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

/* Hold the task states */
typedef enum {
	OS_TASK_READY    ,
	OS_TASK_SUSPENDE ,
}OS_TaskStates_t;

/***********************   Scheduler APIS   *********************/

/* OS_voidStart --> Initialize the OS and start the scheduling */
void OS_voidStart(void);

/* OS_voidStop --> Stop the scheduling by stopping the timer ISR */
void OS_voidStop(void);

/* OS_voidResume --> Resume the scheduling by re enabling the ISR */
void OS_voidResume(void);

/* OS_voidDispatcher --> Called in the while Loop and responsible of calling the the right task */
void OS_voidDispatcher (void);

/*********************** Task APIS ****************************/

/* OS_voidCreateTask --> create a new task note that maximum number of tasks is limited by
 *					     the configuration parameter (OS_NUMBER_OF_TASKS)
 * I/P: task id (u8), initial delay for the first invoke of the function (u16), Period of the task (u16),
 * 		void function at the task
 */
void OS_voidCreateTask(u8 Copy_u8ID , u32 Copy_u16delay , u32 Copy_u16period , void (* Copy_voidFunc) (void));

/*
 * OS_voidDeleteTask --> Delete a task permanently from the scheduler
 * I/P: task id (u8)
 */
void OS_voidDeleteTask (u8 Copy_u8ID);

/*
 * OS_voidSetTaskState --> Set task state to ready or suspended
 * I/P: task id (u8)  / state (OS_TaskStates_t)
 */
void OS_voidSetTaskState(u8 Copy_u8ID , OS_TaskStates_t Copy_state);

#endif /* OS_INTERFACE_H_ */
