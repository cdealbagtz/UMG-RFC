/*
 * MPU6050.h
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#ifndef INC_LIBRARIES_MPU6050_H_
#define INC_LIBRARIES_MPU6050_H_

#include <stdint.h>
#include "i2c.h"
#include <math.h>
#include "Modules/Status/memory.h"

#define RAD_TO_DEG 57.295779513082320876798154814105

#define WHO_AM_I_REG 0x75
#define PWR_MGMT_1_REG 0x6B
#define SMPLRT_DIV_REG 0x19
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_CONFIG_REG 0x1B
#define GYRO_XOUT_H_REG 0x434
#define MPU6050_ADDR 0xD0

typedef struct {
    int16_t Accel_X_RAW;
    int16_t Accel_Y_RAW;
    int16_t Accel_Z_RAW;

    int16_t Gyro_X_RAW;
    int16_t Gyro_Y_RAW;
    int16_t Gyro_Z_RAW;

    float Temperature;
}MPU6050_promData;

// MPU6050 structure
typedef struct {

    int16_t Accel_X_RAW;
    int16_t Accel_Y_RAW;
    int16_t Accel_Z_RAW;
    double Ax;
    double Ay;
    double Az;

    int16_t Gyro_X_RAW;
    int16_t Gyro_Y_RAW;
    int16_t Gyro_Z_RAW;
    double Gx;
    double Gy;
    double Gz;

    float Temperature;

    MPU6050_promData PromBuffer[5];
    MPU6050_promData Prom;

    MPU6050_Flash_t OffSet;
} MPU6050_t;

typedef struct{
	MPU6050_t Module_1;
	MPU6050_t Module_2;
	MPU6050_t Data;

    double KalmanAngleX;
    double KalmanAngleY;
}MPU6050_modules_t;

void MPU6050_getPromModule(MPU6050_t *DataStruct);

extern MPU6050_modules_t MPU6050;

void MPU6050_calibration(void);

uint8_t MPU6050_status(void);

void MPU6050_Init(void);

void MPU6050_Read_All(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct);

#endif /* INC_LIBRARIES_MPU6050_H_ */
