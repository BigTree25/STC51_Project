#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>

unsigned char KeyNumber;
unsigned char LEDmode;
void main()
{
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNumber=Key();
		if(KeyNumber==1)
		{
			LEDmode++;
			if(LEDmode>=2)
			{
				LEDmode=0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0count;
	TL0 = 0x66;
	TH0 = 0xFC;
	T0count++;
	if(T0count==1000)
	{
		T0count=0;
		if(LEDmode==0){P2=_crol_(P2,1);}
		if(LEDmode==1){P2=_cror_(P2,1);}	
	}
}