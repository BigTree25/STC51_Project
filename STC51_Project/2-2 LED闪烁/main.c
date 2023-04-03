#include <REGX52.H>
#include "Delay.h"
void main()
{
	while(1)
	{
		P2=0xFE;
		Delay(500);//延时0.5秒
		P2=0xFF;
		Delay(500);
	}
}