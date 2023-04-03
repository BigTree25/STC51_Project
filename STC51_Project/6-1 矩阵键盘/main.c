#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
#include "LCD1602.h"
#include "MatrixKey.h"

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey:");
	
	while(1)
	{
		unsigned char a=0;
		a=MatrixKey();
		if(a)
			{
				LCD_ShowNum(2,1,a,2);
			}
		
	}
}
