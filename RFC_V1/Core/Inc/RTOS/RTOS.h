/*
 * RTOS.h
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#ifndef INC_RTOS_RTOS_H_
#define INC_RTOS_RTOS_H_

#include "Libraries/BMP280.h"
#include "Libraries/MPU6050.h"
#include "Libraries/NRF24.h"

void init_task_1ms(void);
void init_task_5ms(void);
void init_task_10ms(void);
void init_task_50ms(void);
void init_task_100ms(void);
void init_task_500ms(void);

void task_1ms(void);
void task_5ms(void);
void task_10ms(void);
void task_50ms(void);
void task_100ms(void);
void task_500ms(void);

#endif /* INC_RTOS_RTOS_H_ */