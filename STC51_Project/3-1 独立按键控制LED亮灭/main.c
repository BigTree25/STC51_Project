#include <REGX52.H>
#include "Delay.h"

void main()
{
	while(1)
	{
		if(P3_1==0)//按下k1独立按键
		{
			P2_0=0;//亮灯
		}else
		{
			P2_0=1;
		}
	}
}