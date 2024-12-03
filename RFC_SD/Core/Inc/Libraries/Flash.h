/*
 * Flash.h
 *
 *  Created on: Nov 5, 2024
 *      Author: Chris
 */

#ifndef INC_LIBRARIES_FLASH_H_
#define INC_LIBRARIES_FLASH_H_

#include "stm32f4xx.h"
#include "stdint.h"
#include "string.h"

uint32_t Flash_Write (uint32_t StartSectorAddress, uint32_t *Data, uint16_t numberofwords);
void Flash_Read (uint32_t StartSectorAddress, uint32_t *RxBuf, uint16_t numberofwords);


#endif /* INC_LIBRARIES_FLASH_H_ */
