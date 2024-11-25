/*
 * memory.h
 *
 *  Created on: Nov 6, 2024
 *      Author: cdealba
 */

#ifndef INC_MODULES_STATUS_MEMORY_H_
#define INC_MODULES_STATUS_MEMORY_H_

#include "stm32f4xx.h"
#include "Libraries/Flash.h"

#define FLASH_ADDR 0x08020000

#define SIZEOFSTR  8

typedef struct MPU6050_Flash{
	int16_t Ax_Offset, Ay_Offset, Az_Offset, Gx_Offset, Gy_Offset, Gz_Offset;
}MPU6050_Flash_t;

typedef struct BMP280_Flash{
	int16_t Altitude_Calibration, Temp_Calibration;
}BMP280_Flash_t;

typedef struct Status_Flash{
	uint8_t Reset_Number, Parachute_Deployment;
}Status_Flash_t;

typedef struct Flash_info{
	MPU6050_Flash_t MPU6050_1;
	MPU6050_Flash_t MPU6050_2;
	BMP280_Flash_t BMP280;
	Status_Flash_t STATUS;
}Flash_Info_t;

typedef union{
	Flash_Info_t str;
	uint32_t word[SIZEOFSTR];
	uint8_t bytes[SIZEOFSTR*4];
}MEMORY_u;


extern MEMORY_u MEMORY;

void MEMORY_init(void);
void MEMORY_write(void);
void MEMORY_refresh(void);

#endif /* INC_MODULES_STATUS_MEMORY_H_ */
