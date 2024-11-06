/*
 * memory.c
 *
 *  Created on: Nov 6, 2024
 *      Author: cdealba
 */


#include "Modules/Status/memory.h"

MEMORY_u MEMORY;

void MEMORY_init(void){
	Flash_Read(FLASH_ADDR,MEMORY.word,SIZEOFSTR);
}


void MEMORY_write(void){
	Flash_Write(FLASH_ADDR,MEMORY.word,SIZEOFSTR);
	Flash_Read(FLASH_ADDR,MEMORY.word,SIZEOFSTR);
}
