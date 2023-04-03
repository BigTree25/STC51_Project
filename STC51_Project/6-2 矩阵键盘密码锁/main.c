#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char a=0;
unsigned int Password=0;
unsigned char count=0;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	
	while(1)
	{
		a=MatrixKey();
		if(a)
			{
				if(a<=10)
				{
					if(count<4)
					{
						Password*=10;
						Password+=a%10;
						count++;
					}
				}
				LCD_ShowNum(2,1,Password,4);
			}
		if(a==11)
			{
				if(Password==2345)
				{
					LCD_ShowString(1,14,"OK ");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
				}
				else
				{
					LCD_ShowString(1,14,"ERR");
					Password=0;
					count=0;
					LCD_ShowNum(2,1,Password,4);
				}
			}
		if(a==12)
			{
				Password=0;
				count=0;
				LCD_ShowNum(2,1,Password,4);
			}
		
	}
}
