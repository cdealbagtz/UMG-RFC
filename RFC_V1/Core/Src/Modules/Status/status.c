/*
 * status.c
 *
 *  Created on: Nov 8, 2024
 *      Author: cdealba
 */

#include "Modules/Status/status.h"

status_t SYSTEM_STATUS;

void get_STATUS(void){
	SYSTEM_STATUS.peripheral_Flags = MPU6050_status();
}
