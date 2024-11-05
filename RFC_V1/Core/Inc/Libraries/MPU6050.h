/*
 * MPU6050.h
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#ifndef INC_LIBRARIES_MPU6050_H_
#define INC_LIBRARIES_MPU6050_H_

#include "stm32f4xx.h"
#include <string.h>
#include "i2c.h"

#define MPU6050_ADDR 0xD0

enum MPU6050_MemMap{
	CONFIG		= 0x1A,
	GYRO_CONFIG = 0x1B,
	ACCEL_CONFIG= 0x1C,
	SMPLRT_DIV 	= 0x19,
	WHOAMI 		= 0x75,
	PWR_MGMT_1 	= 0x6B
};

typedef struct Offset{
	int16_t Ax, Ay, Az, Gx, Gy, Gz;
}Offset_t;

typedef struct MPU6050_data{
	uint8_t ID;
	float Ax, Ay, Az, Gx, Gy, Gz;
	Offset_t  Offset;
}MPU6050_data_t;

typedef struct MPU6050{
	MPU6050_data_t S1;
	MPU6050_data_t S2;
}MPU6050_t;

void MPU6050_init(void);
void MPU6050_getData(void);

#endif /* INC_LIBRARIES_MPU6050_H_ */
