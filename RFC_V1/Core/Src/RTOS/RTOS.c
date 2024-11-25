/*
 * RTOS.c
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#include "RTOS/RTOS.h"

uint16_t test = 300;

//////////////////////////////INICIALIZACIÓN DE FUNCIONES///////////////////////////////////////

void init_task_1ms(void){
	MPU6050_Init();
}

void init_task_5ms(void){
	BMP280_init();


}

void init_task_10ms(void){

}

void init_task_50ms(void){

}

void init_task_100ms(void){

}

void init_task_500ms(void){

}

//////////////////////////////FUNCIONES PERIODICAS///////////////////////////////////////

void task_1ms(void){
	get_ACC();
	get_STATUS();
}

void task_5ms(void){
	BMP280_calculate();
	get_ATTS(&MPU6050);

}

void task_10ms(void){
	//if(test == 1){
	//	MPU6050_calibration();
	//	test = 0;
	//}
}

void task_50ms(void){
	DeployParachute();

}

void task_100ms(void){

}

void task_500ms(void){
	  TIM2->CCR4 = test;
	  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
}
