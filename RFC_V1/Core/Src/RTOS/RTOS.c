/*
 * RTOS.c
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#include "RTOS/RTOS.h"

//////////////////////////////INICIALIZACIÓN DE FUNCIONES///////////////////////////////////////

void init_task_1ms(void){
	MPU6050_init();
	MEMORY_init();
}

void init_task_5ms(void){
	BMP280_init();
	MPU6050_calibration();		//TODO Quitar función cuando se tenga calibración por comandos
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
	ATTS_getAcc();
}

void task_5ms(void){
	BMP280_calculate();
}

void task_10ms(void){

}

void task_50ms(void){

}

void task_100ms(void){

}

void task_500ms(void){

}
