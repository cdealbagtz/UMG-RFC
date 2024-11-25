/*
 * blackbox.h
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#ifndef INC_BLACKBOX_BLACKBOX_H_
#define INC_BLACKBOX_BLACKBOX_H_

#include "stm32f4xx.h"
#include "File_Handling_RTOS.h"
#include "Modules/Status/memory.h"
#include "Global/Global.h"

extern MEMORY_u MEMORY;



void BlackBox_init(void);
void BlackBox_SaveData(void);

#endif /* INC_BLACKBOX_BLACKBOX_H_ */
