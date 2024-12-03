/*
 * BlackBox.h
 *
 *  Created on: Dec 3, 2024
 *      Author: cdealba
 */

#ifndef INC_MODULES_BLACKBOX_BLACKBOX_H_
#define INC_MODULES_BLACKBOX_BLACKBOX_H_

#include "stm32f4xx.h"
#include "Global/Global.h"

typedef struct BlackBox_Data{
	int16_t AccX,AccY,AccZ,GyroX,GyroY,GyroZ,AngX,AngY,OffX,OffY,OffZ;

}BlackBox_Data_t;

void BLACKBOX_Init(void);
void BLACKBOX_StoreData(void);

#endif /* INC_MODULES_BLACKBOX_BLACKBOX_H_ */
