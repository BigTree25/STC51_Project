#include <REGX52.H>
#include "Delay.h"
/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码0~4,无按键按下时返回值为0
  */
unsigned char KeyNum;

unsigned char Key_Num()
{
	unsigned char Temp=0;
	Temp=KeyNum;
	KeyNum=0;
	return Temp;
}

unsigned char Key()
{
	unsigned char KeyNumber=0;
	
	if(P3_1==0){KeyNumber=1;}
	if(P3_0==0){KeyNumber=2;}
	if(P3_2==0){KeyNumber=3;}
	if(P3_3==0){KeyNumber=4;}
	return KeyNumber;
}

void Key_Loop()
{
	static unsigned char LastKeyNum,NowKeyNum;
	LastKeyNum=NowKeyNum;
	NowKeyNum=Key();
	if(LastKeyNum!=0&&NowKeyNum==0)
	{
		KeyNum=LastKeyNum;
	}
}