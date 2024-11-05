/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "RTOS/RTOS.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
float AccelData[3];
float GyroData[3];
/* USER CODE END Variables */
osThreadId Task_5msHandle;
osThreadId Task_10msHandle;
osThreadId Task_50msHandle;
osThreadId Task_100msHandle;
osThreadId Task_500msHandle;
osThreadId Task_1msHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Task5ms(void const * argument);
void Task10ms(void const * argument);
void Task50ms(void const * argument);
void Task100ms(void const * argument);
void Task500ms(void const * argument);
void Task1ms(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of Task_5ms */
  osThreadDef(Task_5ms, Task5ms, osPriorityNormal, 0, 128);
  Task_5msHandle = osThreadCreate(osThread(Task_5ms), NULL);

  /* definition and creation of Task_10ms */
  osThreadDef(Task_10ms, Task10ms, osPriorityNormal, 0, 128);
  Task_10msHandle = osThreadCreate(osThread(Task_10ms), NULL);

  /* definition and creation of Task_50ms */
  osThreadDef(Task_50ms, Task50ms, osPriorityNormal, 0, 128);
  Task_50msHandle = osThreadCreate(osThread(Task_50ms), NULL);

  /* definition and creation of Task_100ms */
  osThreadDef(Task_100ms, Task100ms, osPriorityNormal, 0, 128);
  Task_100msHandle = osThreadCreate(osThread(Task_100ms), NULL);

  /* definition and creation of Task_500ms */
  osThreadDef(Task_500ms, Task500ms, osPriorityNormal, 0, 128);
  Task_500msHandle = osThreadCreate(osThread(Task_500ms), NULL);

  /* definition and creation of Task_1ms */
  osThreadDef(Task_1ms, Task1ms, osPriorityNormal, 0, 128);
  Task_1msHandle = osThreadCreate(osThread(Task_1ms), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_Task5ms */
/**
  * @brief  Function implementing the Task_5ms thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Task5ms */
void Task5ms(void const * argument)
{
  /* USER CODE BEGIN Task5ms */
	init_task_5ms();
  /* Infinite loop */
  for(;;)
  {
	task_5ms();
    osDelay(5);
  }
  /* USER CODE END Task5ms */
}

/* USER CODE BEGIN Header_Task10ms */
/**
* @brief Function implementing the Task_10ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task10ms */
void Task10ms(void const * argument)
{
  /* USER CODE BEGIN Task10ms */
	init_task_10ms();
  /* Infinite loop */
  for(;;)
  {
	task_10ms();
    osDelay(10);
  }
  /* USER CODE END Task10ms */
}

/* USER CODE BEGIN Header_Task50ms */
/**
* @brief Function implementing the Task_50ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task50ms */
void Task50ms(void const * argument)
{
  /* USER CODE BEGIN Task50ms */
	init_task_50ms();
  /* Infinite loop */
  for(;;)
  {
	task_50ms();
    osDelay(50);
  }
  /* USER CODE END Task50ms */
}

/* USER CODE BEGIN Header_Task100ms */
/**
* @brief Function implementing the Task_100ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task100ms */
void Task100ms(void const * argument)
{
  /* USER CODE BEGIN Task100ms */
	init_task_100ms();
  /* Infinite loop */
  for(;;)
  {
	task_100ms();
    osDelay(100);
  }
  /* USER CODE END Task100ms */
}

/* USER CODE BEGIN Header_Task500ms */
/**
* @brief Function implementing the Task_500ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task500ms */
void Task500ms(void const * argument)
{
  /* USER CODE BEGIN Task500ms */
	init_task_500ms();
  /* Infinite loop */
  for(;;)
  {
	task_500ms();
    osDelay(500);
  }
  /* USER CODE END Task500ms */
}

/* USER CODE BEGIN Header_Task1ms */
/**
* @brief Function implementing the Task_1ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task1ms */
void Task1ms(void const * argument)
{
  /* USER CODE BEGIN Task1ms */
	init_task_1ms();
  /* Infinite loop */
  for(;;)
  {
	task_1ms();
    osDelay(1);
  }
  /* USER CODE END Task1ms */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
