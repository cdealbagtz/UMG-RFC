/*
 * status.h
 *
 *  Created on: Nov 8, 2024
 *      Author: cdealba
 */

#ifndef INC_MODULES_STATUS_STATUS_H_
#define INC_MODULES_STATUS_STATUS_H_

#include "Global/Global.h"

#define MPU60501_ERRORMASK	0x01
#define MPU60502_ERRORMASK	0x02

typedef struct STATUS{
	uint8_t peripheral_Flags;
}status_t;

extern status_t SYSTEM_STATUS;

void get_STATUS(void);

#endif /* INC_MODULES_STATUS_STATUS_H_ */
