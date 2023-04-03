#ifndef __DS1302_H_
#define __DS1302_H_
#include "LCD1602.h"

extern char DS1302_Time[];
	
void DS1302_Init();
	
void DS1302_Write(unsigned char Command,Data);
	
unsigned char DS1302_Read(unsigned char Command);

void DS1302_SetTime();

void DS1302_ReadTime();

#endif