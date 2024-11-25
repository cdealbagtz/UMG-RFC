/*
 * MPU6050.c
 *
 *  Created on: Nov 5, 2024
 *      Author: cdealba
 */

#include "Libraries/MPU6050.h"

MPU6050_modules_t MPU6050;

#define MPU6050_ADDR 0xD0
const uint16_t i2c_timeout = 10;
const double Accel_Z_corrector = 2048.0;

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

void MPU6050_getPromModule(MPU6050_t *DataStruct){
	int64_t Buffer = 0;
	int32_t AuxBuffer[5] = {0};

	for(uint8_t n = 0;n<5;n++){
		AuxBuffer[n] = DataStruct->PromBuffer[n].Accel_X_RAW;
	}
	for(uint8_t n = 0;n<4;n++){

		DataStruct->PromBuffer[n+1].Accel_X_RAW = AuxBuffer[n];
		Buffer += DataStruct->PromBuffer[n].Accel_X_RAW;
	}
	DataStruct->PromBuffer[0].Accel_X_RAW = DataStruct->Accel_X_RAW;
	Buffer += DataStruct->PromBuffer[0].Accel_X_RAW;
	DataStruct->Prom.Accel_X_RAW = Buffer / 5;

	Buffer = 0;

	for(uint8_t n = 0;n<5;n++){
		AuxBuffer[n] = DataStruct->PromBuffer[n].Accel_Y_RAW;
	}
	for(uint8_t n = 0;n<4;n++){

		DataStruct->PromBuffer[n+1].Accel_Y_RAW = AuxBuffer[n];
		Buffer += DataStruct->PromBuffer[n].Accel_Y_RAW;
	}
	DataStruct->PromBuffer[0].Accel_Y_RAW = DataStruct->Accel_Y_RAW;
	Buffer += DataStruct->PromBuffer[0].Accel_Y_RAW;
	DataStruct->Prom.Accel_Y_RAW = Buffer / 5;

	Buffer = 0;

	for(uint8_t n = 0;n<5;n++){
		AuxBuffer[n] = DataStruct->PromBuffer[n].Accel_Z_RAW;
	}
	for(uint8_t n = 0;n<4;n++){

		DataStruct->PromBuffer[n+1].Accel_Z_RAW = AuxBuffer[n];
		Buffer += DataStruct->PromBuffer[n].Accel_Z_RAW;
	}
	DataStruct->PromBuffer[0].Accel_Z_RAW = DataStruct->Accel_Z_RAW;
	Buffer += DataStruct->PromBuffer[0].Accel_Z_RAW;
	DataStruct->Prom.Accel_Z_RAW = Buffer / 5;


}

uint8_t MPU6050_status(void){
	uint8_t check  = 0;
	uint8_t status = 0;

	static uint8_t eCont1 = 0, eCont2 = 0;

	HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, i2c_timeout);
	if(check != 104){
		eCont1++;
		if(eCont1 > 2){
			status |= 0x01;
			eCont1 = 3;
		}
	}
	else{
		eCont1 = 0;
	}
	check = 0;

	HAL_I2C_Mem_Read(&hi2c2, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, i2c_timeout);
	if(check != 104){
		eCont2++;
		if(eCont1 > 2){
			status |= 0x01;
			eCont2 = 3;
		}
	}
	else{
		eCont2 = 0;
	}

	return status;
}

void MPU6050_memoryRefresh(void){
	MPU6050.Module_1.OffSet.Ax_Offset = MEMORY.str.MPU6050_1.Ax_Offset;
	MPU6050.Module_1.OffSet.Ay_Offset = MEMORY.str.MPU6050_1.Ay_Offset;
	MPU6050.Module_1.OffSet.Az_Offset = MEMORY.str.MPU6050_1.Az_Offset;

	MPU6050.Module_1.OffSet.Gx_Offset = MEMORY.str.MPU6050_1.Gx_Offset;
	MPU6050.Module_1.OffSet.Gy_Offset = MEMORY.str.MPU6050_1.Gy_Offset;
	MPU6050.Module_1.OffSet.Gz_Offset = MEMORY.str.MPU6050_1.Gz_Offset;

	MPU6050.Module_2.OffSet.Ax_Offset = MEMORY.str.MPU6050_2.Ax_Offset;
	MPU6050.Module_2.OffSet.Ay_Offset = MEMORY.str.MPU6050_2.Ay_Offset;
	MPU6050.Module_2.OffSet.Az_Offset = MEMORY.str.MPU6050_2.Az_Offset;

	MPU6050.Module_2.OffSet.Gx_Offset = MEMORY.str.MPU6050_2.Gx_Offset;
	MPU6050.Module_2.OffSet.Gy_Offset = MEMORY.str.MPU6050_2.Gy_Offset;
	MPU6050.Module_2.OffSet.Gz_Offset = MEMORY.str.MPU6050_2.Gz_Offset;
}

void MPU6050_calibration(void){



    MEMORY.str.MPU6050_1.Ax_Offset += MPU6050.Module_1.Accel_X_RAW;
    MEMORY.str.MPU6050_1.Ay_Offset += MPU6050.Module_1.Accel_Y_RAW;
    MEMORY.str.MPU6050_1.Az_Offset += MPU6050.Module_1.Accel_Z_RAW - 2048;

    MEMORY.str.MPU6050_2.Ax_Offset += MPU6050.Module_2.Accel_X_RAW;
    MEMORY.str.MPU6050_2.Ay_Offset += MPU6050.Module_2.Accel_Y_RAW;
    MEMORY.str.MPU6050_2.Az_Offset += MPU6050.Module_2.Accel_Z_RAW - 2048;

    MEMORY.str.MPU6050_1.Gx_Offset += MPU6050.Module_1.Gyro_X_RAW;
    MEMORY.str.MPU6050_1.Gy_Offset += MPU6050.Module_1.Gyro_Y_RAW;
    MEMORY.str.MPU6050_1.Gz_Offset += MPU6050.Module_1.Gyro_Z_RAW;

    MEMORY.str.MPU6050_2.Gx_Offset += MPU6050.Module_2.Gyro_X_RAW;
    MEMORY.str.MPU6050_2.Gy_Offset += MPU6050.Module_2.Gyro_Y_RAW;
    MEMORY.str.MPU6050_2.Gz_Offset += MPU6050.Module_2.Gyro_Z_RAW;

    MPU6050_memoryRefresh();
    MEMORY_write();
}



uint8_t MPU6050_Init_Module(I2C_HandleTypeDef *I2Cx) {
    uint8_t check;
    uint8_t Data;

    // check device ID WHO_AM_I

    HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, WHO_AM_I_REG, 1, &check, 1, i2c_timeout);

    if (check == 104)  // 0x68 will be returned by the sensor if everything goes well
    {
        // power management register 0X6B we should write all 0's to wake the sensor up
        Data = 0;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, PWR_MGMT_1_REG, 1, &Data, 1, i2c_timeout);

        // Set DATA RATE of 1KHz by writing SMPLRT_DIV register
        Data = 0x07;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, SMPLRT_DIV_REG, 1, &Data, 1, i2c_timeout);

        // Set accelerometer configuration in ACCEL_CONFIG Register
        // XA_ST=0,YA_ST=0,ZA_ST=0, FS_SEL=0 -> � 2g
        Data = 0x18;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, ACCEL_CONFIG_REG, 1, &Data, 1, i2c_timeout);

        // Set Gyroscopic configuration in GYRO_CONFIG Register
        // XG_ST=0,YG_ST=0,ZG_ST=0, FS_SEL=0 -> � 250 �/s
        Data = 0x18;
        HAL_I2C_Mem_Write(I2Cx, MPU6050_ADDR, GYRO_CONFIG_REG, 1, &Data, 1, i2c_timeout);
        return 0;
    }
    return 1;
}

void MPU6050_Read_All(I2C_HandleTypeDef *I2Cx, MPU6050_t *DataStruct) {
    uint8_t Rec_Data[14];
    int16_t temp;

    // Read 14 BYTES of data starting from ACCEL_XOUT_H register

    HAL_I2C_Mem_Read(I2Cx, MPU6050_ADDR, ACCEL_XOUT_H_REG, 1, Rec_Data, 14, i2c_timeout);

    DataStruct->Accel_X_RAW = ((int16_t) (Rec_Data[0] << 8 | Rec_Data[1]) - DataStruct->OffSet.Ax_Offset);
    DataStruct->Accel_Y_RAW = ((int16_t) (Rec_Data[2] << 8 | Rec_Data[3]) - DataStruct->OffSet.Ay_Offset);
    DataStruct->Accel_Z_RAW = ((int16_t) (Rec_Data[4] << 8 | Rec_Data[5]) - DataStruct->OffSet.Az_Offset);
    temp = (int16_t) (Rec_Data[6] << 8 | Rec_Data[7]);
    DataStruct->Gyro_X_RAW = ((int16_t) (Rec_Data[8] << 8 | Rec_Data[9])  - DataStruct->OffSet.Gx_Offset);
    DataStruct->Gyro_Y_RAW = ((int16_t) (Rec_Data[10] << 8 | Rec_Data[11])- DataStruct->OffSet.Gy_Offset);
    DataStruct->Gyro_Z_RAW = ((int16_t) (Rec_Data[12] << 8 | Rec_Data[13])- DataStruct->OffSet.Gz_Offset);

    DataStruct->Ax = DataStruct->Accel_X_RAW / 2048.0;
    DataStruct->Ay = DataStruct->Accel_Y_RAW / 2048.0;
    DataStruct->Az = DataStruct->Accel_Z_RAW / Accel_Z_corrector;
    DataStruct->Temperature = (float) ((int16_t) temp / (float) 340.0 + (float) 36.53);
    DataStruct->Gx = DataStruct->Gyro_X_RAW / 16.4;
    DataStruct->Gy = DataStruct->Gyro_Y_RAW / 16.4;
    DataStruct->Gz = DataStruct->Gyro_Z_RAW / 16.4;

}



void MPU6050_Init(void){

	MPU6050_Init_Module(&hi2c1);
	MPU6050_Init_Module(&hi2c2);
	MPU6050_memoryRefresh();

}
