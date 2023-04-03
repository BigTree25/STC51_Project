#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Key.h"
#include "AT24C02.h"
#include "I2C.h"

unsigned char KeyNum;
unsigned int i;

void main()
{
	LCD_Init();
	LCD_ShowNum(1,1,0,5);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum==1)
		{
			LCD_ShowNum(1,1,++i,5);					
		}
		if(KeyNum==2)
		{
			LCD_ShowNum(1,1,--i,5);
		}
		if(KeyNum==3)
		{
			AT24C02_WriteByte(1,i/256);
			Delay(5);
			AT24C02_WriteByte(2,i%256);
			Delay(5);
			LCD_ShowString(2,1,"Write OK");
			Delay(2000);
			LCD_ShowString(2,1,"        ");
		}
		if(KeyNum==4)
		{
			i=AT24C02_ReadByte(1)*256+AT24C02_ReadByte(2);
			LCD_ShowNum(1,1,i,5);
			LCD_ShowString(2,1,"Read OK");
			Delay(2000);
			LCD_ShowString(2,1,"        ");
		}
	}
}