/*
 * actitude.h
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#ifndef INC_MODULES_INS_ATTITUDE_H_
#define INC_MODULES_INS_ATTITUDE_H_

#include "Global/Global.h"




typedef struct ATTS_data{
	float Ax, Ay, Az, Gx, Gy, Gz;
}ATTS_data_t;

void ATTS_getAcc(void);
void ATTS_getATT(void);

#endif /* INC_MODULES_INS_ATTITUDE_H_ */
