#include <REGX52.H>

/**
  * @brief  串口初始化，4800bps@11.0592MHz
  * @param  无
  * @retval 无
  */
void UART_Init()
{
	SCON=0x50;
	PCON=0x80;
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x20;			//设置定时器模式
	TL1 = 0xF4;			//设置定时初始值
	TH1 = 0xF4;			//设置定时重载值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	EA=1;						//设置中断
	ES=1;
}

/**
  * @brief  串口发送一个字节数据
  * @param  Byte 要发送的一个字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}

/*串口中断函数模板
void UART_Routine() interrupt 4
{
	if(RI==1)
	{
		
		RI=0;
	}
}
*/

