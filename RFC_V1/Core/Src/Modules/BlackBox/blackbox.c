/*
 * blackbox.c
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#include "Modules/BlackBox/blackbox.h"

char gucDirName[7];

void BlackBox_init(void){

	uint8_t buf = 0;

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

	MEMORY_write();
}
