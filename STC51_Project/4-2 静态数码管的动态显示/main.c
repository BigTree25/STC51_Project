#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

void main()
{
	while(1)
	{
		Nixie(1,1);
		Delay(5);
		Nixie(2,2);
		Delay(5);
		Nixie(3,3);
		Delay(5);
	}
}