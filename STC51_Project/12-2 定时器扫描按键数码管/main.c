#include <REGX52.H>
#include "Timer0.h"
#include "Nixie.h"
#include "Delay.h"
#include "AT24C02.h"
#include "I2C.h"

unsigned char Temp,RunFlag;
unsigned char Min,Sec,MinSec;

void main()
{
	Timer0_Init();
	while(1)
	{	
		Temp=Key_Num();
		if(Temp==1)
		{
			RunFlag=~RunFlag;
		}
		if(Temp==2)
		{
			Min=0;
			Sec=0;
			MinSec=0;
		}
		if(Temp==3)
		{
			AT24C02_WriteByte(1,Min);
			Delay(5);
			AT24C02_WriteByte(2,Sec);
			Delay(5);
			AT24C02_WriteByte(3,MinSec);
			Delay(5);
		}
		if(Temp==4)
		{
			Min=AT24C02_ReadByte(1);
			Sec=AT24C02_ReadByte(2);
			MinSec=AT24C02_ReadByte(3);	
		}
		Nixie_SetBuf(1,Min/10);
		Nixie_SetBuf(2,Min%10);
		Nixie_SetBuf(3,10);
		Nixie_SetBuf(4,Sec/10);
		Nixie_SetBuf(5,Sec%10);
		Nixie_SetBuf(6,10);
		Nixie_SetBuf(7,MinSec/10);
		Nixie_SetBuf(8,MinSec%10);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0count1,T0count2,T0count3;
	TL0 = 0x66;
	TH0 = 0xFC;
	T0count1++;
	T0count2++;
	T0count3++;
	if(T0count1>=10)
	{
		T0count1=0;
		Key_Loop();
	}
	if(T0count2>=2)
	{
		T0count2=0;
		Nixie_Loop();
	}
	if(RunFlag)
	{	
		if(T0count3>=10)
		{
			MinSec++;
			T0count3=0;
			if(MinSec>=100)
			{
				MinSec=0;
				Sec++;
				if(Sec>=60)
				{
					Sec=0;
					Min++;
				}
			}
		}
	}
}