/*
 * blackbox.c
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#include "Modules/BlackBox/blackbox.h"

char gucDirName[7];
char fileName[] = "FD000.csv";

void BlackBox_init(void){

	uint8_t buf = 0;
    char *path = pvPortMalloc(20*sizeof (char));
    sprintf (path, "%s","/");

	Mount_SD("/");

	buf = MEMORY.str.STATUS.Reset_Number;
	sprintf(gucDirName,"LOG_");
	gucDirName[4] = buf/100 + 48;
	buf -= (buf/100) * 100;
	gucDirName[5] = buf/10 + 48;
	buf -= (buf/10) * 10;
	gucDirName[6] = buf + 48;

	MEMORY.str.STATUS.Reset_Number++;

	Create_Dir(gucDirName);

	Open_Dir(gucDirName);

	Create_File(fileName);

	MEMORY_write();
}

void BlackBox_SaveData(void){
	char Buffer[100];

	sprintf(Buffer,"%f,%f",MPU6050.Data.Ax,MPU6050.Data.Ay);


	Update_File(fileName, Buffer);
}
