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

#define SIZEOFSTR  6

typedef struct MPU6050_Flash{
	int16_t Ax_Offset, Ay_Offset, Az_Offset, Gx_Offset, Gy_Offset, Gz_Offset;
}MPU6050_Flash_t;

typedef struct BMP280_Flash{

}BMP280_Flash_t;

typedef struct Flash_info{
	MPU6050_Flash_t MPU6050_1;
	MPU6050_Flash_t MPU6050_2;
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
