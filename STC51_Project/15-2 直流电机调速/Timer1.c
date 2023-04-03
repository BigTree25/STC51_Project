#include <REGX52.H>
/**
  * @brief  定时器0初始化，1毫秒@11.0592MHz
  * @param  无
  * @retval 无
  */
void Timer1_Init(void)		//1毫秒@11.0592MHz
{
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式
	TL1 = 0xA4;				//设置定时初始值
	TH1 = 0xFF;				//设置定时初始值
	TF1 = 0;				//清除TF0标志
	TR1 = 1;				//定时器0开始计时
	ET1 = 1;
	EA =1;
}

/*定时器中断函数模板
void Timer1_Routine() interrupt 1
{
	static unsigned int T0count;
	TL1 = 0x66;
	TH1 = 0xFC;
	T1count++;
	if(T1count==1000)
	{
		T1count=0;
		P2_0=~P2_0;
	}
}

*/