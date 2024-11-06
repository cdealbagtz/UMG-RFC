/*
 * MPU6050.c
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#include "Libraries/MPU6050.h"

MPU6050_t MPU6050;

void MPU6050_calibration(void){
	uint8_t Rec_Data[6];

	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, 0x3B, 1, Rec_Data, 6, 1);

	MEMORY.str.MPU6050_1.Ax_Offset = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	MEMORY.str.MPU6050_1.Ay_Offset = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	MEMORY.str.MPU6050_1.Az_Offset = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]) - 2048;

	memset(Rec_Data,0,6);

	HAL_I2C_Mem_Read(&hi2c2, MPU6050_ADDR, 0x3B, 1, Rec_Data, 6, 1);

	MEMORY.str.MPU6050_2.Ax_Offset = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	MEMORY.str.MPU6050_2.Ay_Offset = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	MEMORY.str.MPU6050_2.Az_Offset = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]) - 2048;

	memset(Rec_Data,0,6);

	HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, 0x43, 1, Rec_Data, 6, 1000);

	MEMORY.str.MPU6050_1.Gx_Offset = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	MEMORY.str.MPU6050_1.Gy_Offset = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	MEMORY.str.MPU6050_1.Gz_Offset = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	memset(Rec_Data,0,6);

	HAL_I2C_Mem_Read (&hi2c2, MPU6050_ADDR, 0x43, 1, Rec_Data, 6, 1000);

	MEMORY.str.MPU6050_2.Gx_Offset = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]);
	MEMORY.str.MPU6050_2.Gy_Offset = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]);
	MEMORY.str.MPU6050_2.Gz_Offset = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]);

	MEMORY_write();
}

void MPU6050_init(void){
	uint8_t cont = 0;
	uint8_t Data = 0;

	HAL_Delay(100);
	HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, WHOAMI, 1, &MPU6050.S1.ID, 1,1);
	HAL_I2C_Mem_Read (&hi2c2, MPU6050_ADDR, WHOAMI, 1, &MPU6050.S2.ID, 1,1);

	while((MPU6050.S1.ID != 104)&&(cont < 2)){
		Data = 0x40;
		HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1, 1, &Data, 1, 1000);
		MX_I2C1_Init();
		HAL_Delay(100);
		HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, WHOAMI, 1, &MPU6050.S2.ID, 1, 1000);
		cont += 1;
	}
	cont = 0;
	while((MPU6050.S2.ID != 104)&&(cont < 2)){
		Data = 0x40;
		HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, PWR_MGMT_1, 1, &Data, 1, 1000);
		MX_I2C2_Init();
		HAL_Delay(100);
		HAL_I2C_Mem_Read (&hi2c2, MPU6050_ADDR, WHOAMI, 1, &MPU6050.S2.ID, 1, 1000);
		cont += 1;
	}
	Data = 0x00;
	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1, 1, &Data, 1, 1000);
	HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, PWR_MGMT_1, 1, &Data, 1, 1000);

	Data = 0x07;
	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, SMPLRT_DIV, 1, &Data, 1, 1000);
	HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, SMPLRT_DIV, 1, &Data, 1, 1000);

	Data = 0x18;
	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, GYRO_CONFIG, 1, &Data, 1, 1000);
	HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, GYRO_CONFIG, 1, &Data, 1, 1000);

	HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, ACCEL_CONFIG, 1, &Data, 1, 1000);
	HAL_I2C_Mem_Write(&hi2c2, MPU6050_ADDR, ACCEL_CONFIG, 1, &Data, 1, 1000);
}

void MPU6050_accel(void){
	 uint8_t Rec_Data[6];
	 int16_t Accel_X_RAW, Accel_Y_RAW, Accel_Z_RAW;

	HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, 0x3B, 1, Rec_Data, 6, 1);

	Accel_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]) - MEMORY.str.MPU6050_1.Ax_Offset;
	Accel_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]) - MEMORY.str.MPU6050_1.Ay_Offset;
	Accel_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]) - MEMORY.str.MPU6050_1.Az_Offset;

	MPU6050.S1.Ax = (float)Accel_X_RAW/2048.0 ;
	MPU6050.S1.Ay = (float)Accel_Y_RAW/2048.0 ;
	MPU6050.S1.Az = (float)Accel_Z_RAW/2048.0 ;

	memset(Rec_Data,0,6);

	HAL_I2C_Mem_Read (&hi2c2, MPU6050_ADDR, 0x3B, 1, Rec_Data, 6, 1);

	Accel_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]) - MEMORY.str.MPU6050_2.Ax_Offset;
	Accel_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]) - MEMORY.str.MPU6050_2.Ay_Offset;
	Accel_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]) - MEMORY.str.MPU6050_2.Az_Offset;

	MPU6050.S2.Ax = (float)Accel_X_RAW/2048.0;
	MPU6050.S2.Ay = (float)Accel_Y_RAW/2048.0;
	MPU6050.S2.Az = (float)Accel_Z_RAW/2048.0;
}

void MPU6050_gyro(void){
	uint8_t Rec_Data[6];
	int16_t Gyro_X_RAW, Gyro_Y_RAW, Gyro_Z_RAW;

	HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, 0x43, 1, Rec_Data, 6, 1);

	Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]) - MEMORY.str.MPU6050_1.Gx_Offset;
	Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]) - MEMORY.str.MPU6050_1.Gy_Offset;
	Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]) - MEMORY.str.MPU6050_1.Gz_Offset;

	MPU6050.S1.Gx = (float)Gyro_X_RAW/16.4;
	MPU6050.S1.Gy = (float)Gyro_Y_RAW/16.4;
	MPU6050.S1.Gz = (float)Gyro_Z_RAW/16.4;

	memset(Rec_Data,0,6);

	HAL_I2C_Mem_Read (&hi2c2, MPU6050_ADDR, 0x43, 1, Rec_Data, 6, 1);

	Gyro_X_RAW = (int16_t)(Rec_Data[0] << 8 | Rec_Data [1]) - MEMORY.str.MPU6050_2.Gx_Offset;
	Gyro_Y_RAW = (int16_t)(Rec_Data[2] << 8 | Rec_Data [3]) - MEMORY.str.MPU6050_2.Gy_Offset;
	Gyro_Z_RAW = (int16_t)(Rec_Data[4] << 8 | Rec_Data [5]) - MEMORY.str.MPU6050_2.Gz_Offset;

	MPU6050.S2.Gx = (float)Gyro_X_RAW/16.4;
	MPU6050.S2.Gy = (float)Gyro_Y_RAW/16.4;
	MPU6050.S2.Gz = (float)Gyro_Z_RAW/16.4;
}

void MPU6050_getData(void){
	MPU6050_accel();
	MPU6050_gyro();
}
