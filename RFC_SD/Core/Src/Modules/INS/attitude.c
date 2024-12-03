/*
 * actitude.c
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#include "Modules/INS/attitude.h"

uint32_t timer;

Kalman_t KalmanX = {
        .Q_angle = 0.001f,
        .Q_bias = 0.003f,
        .R_measure = 0.03f
};

Kalman_t KalmanY = {
        .Q_angle = 0.001f,
        .Q_bias = 0.003f,
        .R_measure = 0.03f,
};

void get_ACC(void){


	if(!(SYSTEM_STATUS.peripheral_Flags & (MPU60501_ERRORMASK | MPU60502_ERRORMASK))){
		MPU6050_Read_All(&hi2c1, &MPU6050.Module_1);
		MPU6050_Read_All(&hi2c2, &MPU6050.Module_2);

		MPU6050_getPromModule(&MPU6050.Module_1);
		MPU6050_getPromModule(&MPU6050.Module_2);

		MPU6050.Data.Accel_X_RAW = (MPU6050.Module_1.Accel_X_RAW + MPU6050.Module_2.Accel_X_RAW)/2;
		MPU6050.Data.Accel_Y_RAW = (MPU6050.Module_1.Accel_Y_RAW + MPU6050.Module_2.Accel_Y_RAW)/2;
		MPU6050.Data.Accel_Z_RAW = (MPU6050.Module_1.Accel_Z_RAW + MPU6050.Module_2.Accel_Z_RAW)/2;

		MPU6050.Data.Gyro_X_RAW  = (MPU6050.Module_1.Gyro_X_RAW + MPU6050.Module_2.Gyro_X_RAW)/2;
		MPU6050.Data.Gyro_Y_RAW  = (MPU6050.Module_1.Gyro_Y_RAW + MPU6050.Module_2.Gyro_Y_RAW)/2;
		MPU6050.Data.Gyro_Z_RAW  = (MPU6050.Module_1.Gyro_Z_RAW + MPU6050.Module_2.Gyro_Z_RAW)/2;

		MPU6050.Data.Ax			 = (MPU6050.Module_1.Ax + MPU6050.Module_2.Ax)/2;
		MPU6050.Data.Ay			 = (MPU6050.Module_1.Ay + MPU6050.Module_2.Ay)/2;
		MPU6050.Data.Az			 = (MPU6050.Module_1.Az + MPU6050.Module_2.Az)/2;

		MPU6050.Data.Gx			 = (MPU6050.Module_1.Gx + MPU6050.Module_2.Gx)/2;
		MPU6050.Data.Gy			 = (MPU6050.Module_1.Gy + MPU6050.Module_2.Gy)/2;
		MPU6050.Data.Gz			 = (MPU6050.Module_1.Gz + MPU6050.Module_2.Gz)/2;

		MPU6050.Data.Temperature = (MPU6050.Module_1.Temperature + MPU6050.Module_2.Temperature)/2;
	}
	else if(!(SYSTEM_STATUS.peripheral_Flags & MPU60501_ERRORMASK)){
		MPU6050_Read_All(&hi2c1, &MPU6050.Module_1);
		MPU6050_getPromModule(&MPU6050.Module_1);

		MPU6050.Data.Accel_X_RAW = MPU6050.Module_1.Accel_X_RAW;
		MPU6050.Data.Accel_Y_RAW = MPU6050.Module_1.Accel_Y_RAW;
		MPU6050.Data.Accel_Z_RAW = MPU6050.Module_1.Accel_Z_RAW;

		MPU6050.Data.Gyro_X_RAW  = MPU6050.Module_1.Gyro_X_RAW;
		MPU6050.Data.Gyro_Y_RAW  = MPU6050.Module_1.Gyro_Y_RAW;
		MPU6050.Data.Gyro_Z_RAW  = MPU6050.Module_1.Gyro_Z_RAW;

		MPU6050.Data.Ax			 = MPU6050.Module_1.Ax;
		MPU6050.Data.Ay			 = MPU6050.Module_1.Ay;
		MPU6050.Data.Az			 = MPU6050.Module_1.Az;

		MPU6050.Data.Gx			 = MPU6050.Module_1.Gx;
		MPU6050.Data.Gy			 = MPU6050.Module_1.Gy;
		MPU6050.Data.Gz			 = MPU6050.Module_1.Gz;

		MPU6050.Data.Temperature = MPU6050.Module_1.Temperature;
	}
	else if(!(SYSTEM_STATUS.peripheral_Flags & MPU60502_ERRORMASK)){
		MPU6050_Read_All(&hi2c2, &MPU6050.Module_2);
		MPU6050_getPromModule(&MPU6050.Module_2);

		MPU6050.Data.Accel_X_RAW = MPU6050.Module_2.Accel_X_RAW;
		MPU6050.Data.Accel_Y_RAW = MPU6050.Module_2.Accel_Y_RAW;
		MPU6050.Data.Accel_Z_RAW = MPU6050.Module_2.Accel_Z_RAW;

		MPU6050.Data.Gyro_X_RAW  = MPU6050.Module_2.Gyro_X_RAW;
		MPU6050.Data.Gyro_Y_RAW  = MPU6050.Module_2.Gyro_Y_RAW;
		MPU6050.Data.Gyro_Z_RAW  = MPU6050.Module_2.Gyro_Z_RAW;

		MPU6050.Data.Ax			 = MPU6050.Module_2.Ax;
		MPU6050.Data.Ay			 = MPU6050.Module_2.Ay;
		MPU6050.Data.Az			 = MPU6050.Module_2.Az;

		MPU6050.Data.Gx			 = MPU6050.Module_2.Gx;
		MPU6050.Data.Gy			 = MPU6050.Module_2.Gy;
		MPU6050.Data.Gz			 = MPU6050.Module_2.Gz;

		MPU6050.Data.Temperature = MPU6050.Module_2.Temperature;
	}
	MPU6050_getPromModule(&MPU6050.Data);
}

double Kalman_getAngle(Kalman_t *Kalman, double newAngle, double newRate, double dt) {
    double rate = newRate - Kalman->bias;
    Kalman->angle += dt * rate;

    Kalman->P[0][0] += dt * (dt * Kalman->P[1][1] - Kalman->P[0][1] - Kalman->P[1][0] + Kalman->Q_angle);
    Kalman->P[0][1] -= dt * Kalman->P[1][1];
    Kalman->P[1][0] -= dt * Kalman->P[1][1];
    Kalman->P[1][1] += Kalman->Q_bias * dt;

    double S = Kalman->P[0][0] + Kalman->R_measure;
    double K[2];
    K[0] = Kalman->P[0][0] / S;
    K[1] = Kalman->P[1][0] / S;

    double y = newAngle - Kalman->angle;
    Kalman->angle += K[0] * y;
    Kalman->bias += K[1] * y;

    double P00_temp = Kalman->P[0][0];
    double P01_temp = Kalman->P[0][1];

    Kalman->P[0][0] -= K[0] * P00_temp;
    Kalman->P[0][1] -= K[0] * P01_temp;
    Kalman->P[1][0] -= K[1] * P00_temp;
    Kalman->P[1][1] -= K[1] * P01_temp;

    return Kalman->angle;
};

void get_ATTS(MPU6050_modules_t *DataStruct){
    double dt = (double) (HAL_GetTick() - timer) / 1000;
    timer = HAL_GetTick();
    double roll;
    double roll_sqrt = sqrt(
            DataStruct->Data.Prom.Accel_X_RAW * DataStruct->Data.Prom.Accel_X_RAW + DataStruct->Data.Prom.Accel_Z_RAW * DataStruct->Data.Prom.Accel_Z_RAW);
    if (roll_sqrt != 0.0) {
        roll = atan(DataStruct->Data.Prom.Accel_Y_RAW / roll_sqrt) * RAD_TO_DEG;
    } else {
        roll = 0.0;
    }
    double pitch = atan2(-DataStruct->Data.Prom.Accel_X_RAW, DataStruct->Data.Prom.Accel_Z_RAW) * RAD_TO_DEG;
    if ((pitch < -90 && DataStruct->KalmanAngleY > 90) || (pitch > 90 && DataStruct->KalmanAngleY < -90)) {
        KalmanY.angle = pitch;
        DataStruct->KalmanAngleY = pitch;
    } else {
        DataStruct->KalmanAngleY = Kalman_getAngle(&KalmanY, pitch, DataStruct->Data.Gy, dt);
    }
    if (fabs(DataStruct->KalmanAngleY) > 90)
        DataStruct->Data.Gx = -DataStruct->Data.Gx;
    DataStruct->KalmanAngleX = Kalman_getAngle(&KalmanX, roll, DataStruct->Data.Gy, dt);

}


