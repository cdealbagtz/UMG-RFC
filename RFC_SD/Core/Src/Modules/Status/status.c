/*
 * status.c
 *
 *  Created on: Nov 8, 2024
 *      Author: cdealba
 */

#include "Modules/Status/status.h"

status_t SYSTEM_STATUS;
extern BMP280_t BMP280;
extern uint32_t channel_1_past;

void get_STATUS(void){
	static uint8_t init = 1;

	if(init){
		SYSTEM_STATUS.peripheral_Flags = 0x00;
		init = 0;
	}

	if(MPU6050_status())SYSTEM_STATUS.peripheral_Flags |= MPU6050_status();
	else SYSTEM_STATUS.peripheral_Flags &= 0xFC;
	if(BMP280.ID != 111)  SYSTEM_STATUS.peripheral_Flags |= 0x04;
	else SYSTEM_STATUS.peripheral_Flags &= 0xFB;
	if(channel_1_past == 0) SYSTEM_STATUS.peripheral_Flags |= 0x08;
	else SYSTEM_STATUS.peripheral_Flags &= 0xF7;
}

void Emergency_actions(void){
	if((SYSTEM_STATUS.peripheral_Flags & (MPU60501_ERRORMASK | MPU60502_ERRORMASK))== 0x03){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
		return;
	}
}
