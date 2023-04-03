#include <REGX52.H>
/**
  * @brief  定时器0初始化，1毫秒@11.0592MHz
  * @param  无
  * @retval 无
  */
void Timer0_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;
	EA =1;
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0count;
	TL0 = 0x66;
	TH0 = 0xFC;
	T0count++;
	if(T0count==1000)
	{
		T0count=0;
		P2_0=~P2_0;
	}
}

*/