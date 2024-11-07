/*
 * actitude.c
 *
 *  Created on: Nov 4, 2024
 *      Author: cdealba
 */

#include "Modules/INS/attitude.h"

ATTS_data_t ATTS;

void ATTS_getAcc(void){
	MPU6050_getData();
	if((MPU6050.S1.ID == 104)&&(MPU6050.S2.ID == 104)){
		ATTS.Ax = (MPU6050.S1.Ax + MPU6050.S2.Ax)/2;
		ATTS.Ay = (MPU6050.S1.Ay + MPU6050.S2.Ay)/2;
		ATTS.Az = (MPU6050.S1.Az + MPU6050.S2.Az)/2;

		ATTS.Gx = (MPU6050.S1.Gx + MPU6050.S2.Gx)/2;
		ATTS.Gy = (MPU6050.S1.Gy + MPU6050.S2.Gy)/2;
		ATTS.Gz = (MPU6050.S1.Gz + MPU6050.S2.Gz)/2;
	}
	else if(MPU6050.S1.ID != 104){
		ATTS.Ax = MPU6050.S2.Ax;
		ATTS.Ay = MPU6050.S2.Ay;
		ATTS.Az = MPU6050.S2.Az;

		ATTS.Gx = MPU6050.S2.Gx;
		ATTS.Gy = MPU6050.S2.Gy;
		ATTS.Gz = MPU6050.S2.Gz;
	}
	else{
		ATTS.Ax = MPU6050.S1.Ax;
		ATTS.Ay = MPU6050.S1.Ay;
		ATTS.Az = MPU6050.S1.Az;

		ATTS.Gx = MPU6050.S1.Gx;
		ATTS.Gy = MPU6050.S1.Gy;
		ATTS.Gz = MPU6050.S1.Gz;
	}
}

void ATTS_getATT(void){

}
