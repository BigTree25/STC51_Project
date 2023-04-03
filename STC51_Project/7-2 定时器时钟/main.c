#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "LCD1602.h"

unsigned int sec;
unsigned char a;
unsigned char b;
unsigned char c;

void main()
{
	LCD_INit();
	Timer0_INit();
	
	LCD_ShowString(1,1,"CLOCK");
	
	while(1)
	{
		if(sec==86400)
			sec=0;
		a=sec/3600;
		b=(sec/60)%60;
		c=sec%60;
		LCD_ShowNum(2,1,a,2);
		LCD_ShowChar(2,3,':');
		LCD_ShowNum(2,4,b,2);
		LCD_ShowChar(2,6,':');
		LCD_ShowNum(2,7,c,2);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0count;
	TL0 = 0x66;
	TH0 = 0xFC;
	T0count++;
	if(T0count==1000)
	{
		T0count=0;
		sec++;
	}
}