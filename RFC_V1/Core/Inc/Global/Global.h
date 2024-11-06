/*
 * Global.h
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#ifndef INC_GLOBAL_GLOBAL_H_
#define INC_GLOBAL_GLOBAL_H_

#include "stm32f4xx.h"
#include "Libraries/BMP280.h"
#include "Libraries/Flash.h"
#include "Libraries/MPU6050.h"
#include "Libraries/NRF24.h"


typedef struct S16{
	uint8_t	 bytes[2];
	int16_t inter;
}s16_t;

typedef struct S32{
	uint8_t	 bytes[4];
	int32_t inter;
}s32_t;

typedef struct U16{
	uint8_t	 bytes[2];
	uint16_t inter;
}u16_t;

typedef struct U32{
	uint8_t	 bytes[4];
	uint32_t inter;
}u32_t;


#endif /* INC_GLOBAL_GLOBAL_H_ */
