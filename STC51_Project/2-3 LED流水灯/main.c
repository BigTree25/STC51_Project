#include <REGX52.H>
#include "Delay.h"//调用延时头文件

void main()
{
	while(1)//避免重复执行main函数
	{
		char i=0;//用来计数
		char j=0x01;//初始化亮灯
		P2=~j;//1111 1110//因为输出0为亮，所以采用取反
		Delay(500);
		for(i=0;i<=8;i++)
		{
			if(i==8)//判断移位次数
			{
				j=0x01;//重新初始化
				P2=~j;
				Delay(500);//延迟0.5秒
				i=i-8;
			}	
			j=j<<1;//向左移位1
			P2=~j;
			Delay(500);
		}
	}
}
