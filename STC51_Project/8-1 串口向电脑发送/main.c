#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char sec;

void main()
{
	UART_Init();
	
	while(1)
	{
		UART_SendByte(sec);
		sec++;
		Delay(1000);
		
	}
}