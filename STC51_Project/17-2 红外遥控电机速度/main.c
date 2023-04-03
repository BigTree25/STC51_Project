#include <REGX52.H>
#include "IR.h"
#include "Motor.h"
#include "Timer1.h"

sbit Motor=P1^0;

unsigned char Address,Command;
unsigned char Speed;

void main()
{ 
	IR_Init();
	Timer1_Init();
	while(1)
	{
		if(IR_GetDataFlag() || IR_GetRepeatFlag())
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			Speed=Motor_ChangeSpeed(Command);
		}
	}
}

void Timer1_Routine() interrupt 3
{
	static unsigned char T1count;
	TL1 = 0xA4;				//设置定时初始值
	TH1 = 0xFF;				//设置定时初始值
	T1count++;
	T1count%=100;
	if(T1count<Speed)
	{
		Motor=1;
	}else
	{
		Motor=0;
	}
}