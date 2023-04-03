#include <REGX52.H>
#include "Key.h"
#include "Nixie.h"
#include "Timer1.h"

sbit Motor=P1^0;

unsigned char T1count,compare;
unsigned char KeyNum,speed=0;

void main()
{
	Timer1_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			speed++;
			speed%=5;
			Nixie(1,speed);
		}
		if(speed==0){compare=0;}
		if(speed==1){compare=30;}
		if(speed==2){compare=55;}
		if(speed==3){compare=80;}
		if(speed==4){compare=100;}
	}
}

void Timer1_Routine() interrupt 3
{
	TL1 = 0xA4;				//设置定时初始值
	TH1 = 0xFF;				//设置定时初始值
	T1count++;
	T1count%=100;
	if(T1count<compare)
	{
		Motor=1;
	}else
	{
		Motor=0;
	}
}