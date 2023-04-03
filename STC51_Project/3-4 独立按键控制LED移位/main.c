#include <REGX52.H>
#include "Delay.h"

void main()
{
	unsigned char a=0x01;
	P2=~a;
	while(1)
	{
		if(P3_1==0)
		{		
			Delay(20);
			while(P3_1==0);
			Delay(20);
			if(a==0x01)//右移
			{
				a=0x80;
			}else
			{
				a=a>>1;
			}
		}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if(a==0x80)//左移
			{
				a=0x01;
			}else
			{
				a=a<<1;
			}
		}
		P2=~a;
	}
}