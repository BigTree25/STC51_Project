#include <REGX52.H>



unsigned char compare;

unsigned char Motor_ChangeSpeed(unsigned char a)
{
	if(a==0x15)
	{
		if(compare>=10)
		{
			compare-=10;
		}
	}else if(a==0x09)
	{
		if(compare<=90)
		{
			compare+=10;
		}	
	}
	return compare;
}