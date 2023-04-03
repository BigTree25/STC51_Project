#include <REGX52.H>
#include "Int0.h"
#include "Timer0.h"

unsigned char IR_Flag;
unsigned int IR_Time;

unsigned char IR_DataFlag;
unsigned char IR_RepeatFlag;

unsigned char IR_Address;
unsigned char IR_Command;
unsigned char IR_Data[4];
unsigned char IR_pData;

void IR_Init()
{
	Int0_Init();
	Timer0_Init();
}

unsigned char IR_GetDataFlag()
{
	if(IR_DataFlag==1)
	{
		IR_DataFlag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetRepeatFlag()
{
	if(IR_RepeatFlag==1)
	{
		IR_RepeatFlag=0;
		return 1;
	}
	return 0;
}

unsigned char IR_GetAddress()
{
	return IR_Address;
}

unsigned char IR_GetCommand()
{
	return IR_Command;
}

void Int0_Routine() interrupt 0
{
	if(IR_Flag==0)
	{
		Timer0_SetCounter(0);
		Timer0_Run(1);
		IR_Flag=1;
	}else if(IR_Flag==1)
	{
		IR_Time=Timer0_GetCounter();
		Timer0_SetCounter(0);
		if(IR_Time>(12442-500) && IR_Time<(12442+500))
		{
			IR_Flag=2;
		}else if(IR_Time>(10368-500) && IR_Time<(10368+500))
		{
			IR_RepeatFlag=1;
			Timer0_Run(0);
			IR_Flag=0;
		}else
		{
			IR_Flag=1;
		}
	}else if(IR_Flag==2)
	{
		IR_Time=Timer0_GetCounter();
		Timer0_SetCounter(0);
		if(IR_Time>(1032-500) && IR_Time<(1032+500))
		{
			IR_Data[IR_pData/8]&=~(0x01<<(IR_pData%8));
			IR_pData++;
		}else if(IR_Time>(2074-500) && IR_Time<(2074+500))
		{
			IR_Data[IR_pData/8]|=(0x01<<(IR_pData%8));
			IR_pData++;
		}else					//接收出错
		{
			IR_pData=0;			//数据位置指针清0
			IR_Flag=1;			//置状态为1
		}
		
		if(IR_pData>=32)
		{
			if((IR_Data[0]==~IR_Data[1]) && (IR_Data[2]==~IR_Data[3]))
			{
				IR_Address=IR_Data[0];
				IR_Command=IR_Data[2];
				IR_DataFlag=1;
			}
			Timer0_Run(0);
			IR_Flag=0;
			IR_pData=0;
		}
	}
}