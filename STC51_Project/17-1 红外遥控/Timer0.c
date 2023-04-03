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
	TL0 = 0x00;				//设置定时初始值
	TH0 = 0x00;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 0;				//定时器0开始计时
}

void Timer0_SetCounter(unsigned int Value)
{
	TH0=Value/256;
	TL0=Value%256;
}

unsigned int Timer0_GetCounter()
{
	return (TH0<<8)|TL0;
}

void Timer0_Run(unsigned char Flag)
{
	TR0=Flag;
}