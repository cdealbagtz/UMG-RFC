/*
 * RTOS.c
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#include "RTOS/RTOS.h"

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
	NRF24_init();
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
uint8_t test =0;
void task_10ms(void){
	if(test == 1){
		MPU6050_calibration();
		test = 0;
	}
}

void task_50ms(void){

}

void task_100ms(void){

}

void task_500ms(void){


}
