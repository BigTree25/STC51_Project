#include <REGX52.H>
#include "Delay.h"

char a=0x00;
void main()
{
	while(1)
	{
		if(P3_1==0)
		{
			P2=~a;
			Delay(20);
			while(P3_1==0);
			Delay(20);
			if(a==0xFF)
			{
				a=0x00;
			}else
			{
				a=a+1;//按下k1加1
			}
			P2=~a;
		}
		if(P3_0==0)
		{
			P2=~a;
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if(a==0x00)
			{
				a=0xFF;
			}else
			{
				a=a-1;//按下k2减1
			}
			P2=~a;
		}
	}
}

