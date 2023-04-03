#include <REGX52.H>

sbit DS1302_SCLK=P3^6;
sbit DS1302_CE=P3^5;
sbit DS1302_IO=P3^4;

#define DS1302_SECOND 0x80
#define DS1302_MINUTE 0x82
#define DS1302_HOUR 	0x84
#define DS1302_DATE 	0x86
#define DS1302_MONTH 	0x88
#define DS1302_DAY 		0x8A
#define DS1302_YEAR 	0x8C
#define DS1302_WP 		0x8E


char DS1302_Time[]={23,2,9,21,50,50,6};

/**
  * @brief  DS1302初始化
  * @param  无
  * @retval 无
  */
void DS1302_Init()
{
	DS1302_CE=0;
	DS1302_SCLK=0;
}

/**
	* @brief  单片机给DS1302写入数据
  * @param  Command 一个命令字数据 十六进制
  * @param	Data 要写入给DS1302的数据
  * @retval 无
  */
void DS1302_Write(unsigned char Command,Data)
{
	unsigned char i;
	DS1302_CE=1;
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Data&(0x01<<i);
		DS1302_SCLK=1;
		DS1302_SCLK=0;
	}
	
	DS1302_CE=0;
}

/**
  * @brief  
  * @param  
  * @retval 
  */
unsigned char DS1302_Read(unsigned char Command)
{
	unsigned char Data=0x00;
	unsigned char i;
	Command|=0x01;
	DS1302_CE=1;
	
	for(i=0;i<8;i++)
	{
		DS1302_IO=Command&(0x01<<i);
		DS1302_SCLK=0;
		DS1302_SCLK=1;	
	}
	
	for(i=0;i<8;i++)
	{	
		DS1302_SCLK=1;
		DS1302_SCLK=0;
		if(DS1302_IO){Data|=(0x01<<i);}
	}
	
	DS1302_CE=0;
	return Data;
}

void DS1302_SetTime()
{
	DS1302_Write(DS1302_WP,0x00);
	DS1302_Write(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_Write(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_Write(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_Write(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_Write(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_Write(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_Write(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_Write(DS1302_WP,0x80);
}

void DS1302_ReadTime()
{
	unsigned char Temp;
	Temp=DS1302_Read(DS1302_YEAR);
	DS1302_Time[0]=Temp/16*10+Temp%16;
	Temp=DS1302_Read(DS1302_MONTH);
	DS1302_Time[1]=Temp/16*10+Temp%16;
	Temp=DS1302_Read(DS1302_DATE);
	DS1302_Time[2]=Temp/16*10+Temp%16;
	Temp=DS1302_Read(DS1302_HOUR);
	DS1302_Time[3]=Temp/16*10+Temp%16;
	Temp=DS1302_Read(DS1302_MINUTE);
	DS1302_Time[4]=Temp/16*10+Temp%16;
	Temp=DS1302_Read(DS1302_SECOND);
	DS1302_Time[5]=Temp/16*10+Temp%16;
	Temp=DS1302_Read(DS1302_DAY);
	DS1302_Time[6]=Temp/16*10+Temp%16;

}