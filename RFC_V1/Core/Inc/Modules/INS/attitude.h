/*
 * actitude.h
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#ifndef INC_MODULES_INS_ATTITUDE_H_
#define INC_MODULES_INS_ATTITUDE_H_

#include "Global/Global.h"
#include "Modules/Status/status.h"

// Kalman structure
typedef struct {
    double Q_angle;
    double Q_bias;
    double R_measure;
    double angle;
    double bias;
    double P[2][2];
} Kalman_t;

void get_ACC(void);
void get_ATTS(MPU6050_modules_t *DataStruct);

#endif /* INC_MODULES_INS_ATTITUDE_H_ */
