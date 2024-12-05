/*
 * BlackBox.c
 *
 *  Created on: Dec 3, 2024
 *      Author: cdealba
 */

#include "fatfs.h"
#include "Libraries/BMP280.h"
#include "Libraries/MPU6050.h"
#include "Modules/Status/memory.h"
#include "Modules/BlackBox/BlackBox.h"
#include "tim.h"

FATFS fs;  // file system
FIL fil; // File
FILINFO fno;
FRESULT fresult;  // result
UINT br, bw;  // File read/write count

BlackBox_Data_t BLACKBOX;

extern uint8_t Parachute_Status;
extern MEMORY_u MEMORY;
extern MPU6050_modules_t MPU6050;
extern BMP280_t BMP280;

char pahtName[7] = "Data000";
char fileName[] = "FD000.csv";

void Refresh_data(void){
	BLACKBOX.AccX = (int16_t)(MPU6050.Data.Ax*100);
	BLACKBOX.AccY = (int16_t)(MPU6050.Data.Ay*100);
	BLACKBOX.AccZ = (int16_t)(MPU6050.Data.Az*100);
	BLACKBOX.GyroX = (int16_t)(MPU6050.Data.Gx*100);
	BLACKBOX.GyroY = (int16_t)(MPU6050.Data.Gy*100);
	BLACKBOX.GyroZ = (int16_t)(MPU6050.Data.Gz*100);
	BLACKBOX.AngX = (int16_t)(MPU6050.KalmanAngleX*100);
	BLACKBOX.AngY = (int16_t)(MPU6050.KalmanAngleY*100);

}

void Get_NewDir(void){
	uint8_t Buffer;
	Buffer = MEMORY.str.STATUS.Reset_Number;


	pahtName[4] = Buffer/100 + 48;
	Buffer = Buffer - (Buffer/100)*100;
	pahtName[5]= Buffer/10 + 48;
	Buffer = Buffer - (Buffer/10)*10;
	pahtName[6] = Buffer + 48;

	fresult = f_mkdir(pahtName);
	fresult = f_chdir(pahtName);
}

void BLACKBOX_Init(void){
	  fresult = f_mount(&fs, "/", 1);
	  Get_NewDir();
	  f_open(&fil, fileName, FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
	  fresult = f_lseek(&fil , f_size(&fil));
	  f_printf(&fil,"Nmsg,AccX,AccY,AccZ,GyroX,GyroY,GyroZ,AngX,AngY,Alt,Pressure,Temp,Parachute,Peripheral\n");
	  f_close(&fil);

	  if(fresult == FR_OK){
		HAL_TIM_Base_Start_IT(&htim5);
	  }
	  else{
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);
	  }
}

void BLACKBOX_NewFile(void){
	  f_close(&fil);
	  static uint8_t r,r2,r3 = 0;
	  r++;
	  fileName[4] = 48+r;
	  if(r==10){
		  r2++;
		  r=0;
		  fileName[3] = 48 + r2;
		  fileName[2] = 48;
		  if(r2==10){
			  r3++;
			  r2=0;
			  fileName[4] = 48 + r3;
			  fileName[3] = 48;
		  }
	  }
	  f_open(&fil, fileName, FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
}

void BLACKBOX_StoreData(void){
	static uint32_t N_MSG = 0;
	static uint16_t RstCont = 0;
	static uint8_t SaveChanges = 100;

	if(RstCont>=48000){
		BLACKBOX_NewFile();
		RstCont = 0;
	}

	if(SaveChanges == 100){
		f_close(&fil);
		f_open(&fil, fileName, FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
		SaveChanges = 0;
	}
	Refresh_data();
	f_lseek(&fil , f_size(&fil));
	f_printf(&fil,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",N_MSG,BLACKBOX.AccX,BLACKBOX.AccY,BLACKBOX.AccZ,BLACKBOX.GyroX,BLACKBOX.GyroY,BLACKBOX.GyroZ,BLACKBOX.AngX,BLACKBOX.AngY,BMP280.Barometric_Altitude\
			,BMP280.Pressure,BMP280.Temp, Parachute_Status);

	N_MSG++;
	SaveChanges++;
	RstCont++;
}
