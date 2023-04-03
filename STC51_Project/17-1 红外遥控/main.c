#include <REGX52.H>
#include "LCD1602.h"
#include "IR.h"

unsigned char DataFlag,RepeatFlag;
unsigned char Address,Command;

void main()
{ 
	LCD_Init();
	IR_Init();
	while(1)
	{
		DataFlag=IR_GetDataFlag();
		RepeatFlag=IR_GetRepeatFlag();
		if(DataFlag || RepeatFlag)
		{
			Address=IR_GetAddress();
			Command=IR_GetCommand();
			LCD_ShowHexNum(1,1,Address,2);
			LCD_ShowHexNum(1,4,Command,2);
		}
	}
}