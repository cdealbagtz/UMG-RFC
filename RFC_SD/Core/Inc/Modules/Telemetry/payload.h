/*
 * payload.h
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#ifndef INC_MODULES_TELEMETRY_PAYLOAD_H_
#define INC_MODULES_TELEMETRY_PAYLOAD_H_

#include "Global/Global.h"
#include "tim.h"
#include "stdlib.h"



#define Sin_Desplegar	0x00
#define Desplegar 		0x10

#define Desp_Ang		0x01
#define Desp_Alt		0x02

void DeployParachute(void);

#endif /* INC_MODULES_TELEMETRY_PAYLOAD_H_ */
