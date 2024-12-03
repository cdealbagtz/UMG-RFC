/*
 * payload.c
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */


#include "Modules/Telemetry/payload.h"

extern BMP280_t BMP280;

uint8_t Parachute_Status = 0x00;



void DeployParachute(void){
	Parachute_Status = 0x00;

	if(((abs((int)MPU6050.KalmanAngleX)) > 70 || (abs((int)MPU6050.KalmanAngleY)) > 70)){
		Parachute_Status |= Desplegar;
		Parachute_Status |= Desp_Ang;
	}

	if((BMP280.Barometric_Altitude + 10) < BMP280.Max_Altitude){
		Parachute_Status |= Desplegar;
		Parachute_Status |= Desp_Alt;
	}

	if(Parachute_Status){
		  TIM2->CCR4 = 2000;
		  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	}
	else{
		  TIM2->CCR4 = 1000;
		  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);
	}
}
