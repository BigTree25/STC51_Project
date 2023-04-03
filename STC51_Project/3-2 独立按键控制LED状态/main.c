#include <REGX52.H>
#include "Delay.h"

void main()
{
	P2_0=1;//初始化LED
	while(1)
	{	
		if(P3_1==0)//按下k1判断
		{
			Delay(20);//延时消抖
			while(P3_1==0);//判断k1是否还没松开
			Delay(20);
			P2_0=~P2_0;//取反信号
		}		
	}
}