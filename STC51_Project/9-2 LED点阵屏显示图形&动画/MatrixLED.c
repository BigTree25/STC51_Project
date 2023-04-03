#include <REGX52.H>
#include "Delay.h"

#define MATRIX_LED_PORT P0

/**
  * @brief  点阵屏初始化
  * @param  无
  * @retval 无
  */
void MatrixLED_Init()
{
	P3_5=0;
	P3_6=0;
}

/**
  * @brief  74HC595写入一个字节
  * @param  要写入字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char a)
{
	unsigned char i=0;
	for(i=0;i<8;i++)
	{
		P3_4=a&(0x80>>i);
		P3_6=1;
		P3_6=0;
	}
	P3_5=1;
	P3_5=0;
}

/**
	* @brief  LED点阵屏显示一列数据
  * @param  x 要选择的列 范围：1~8，1在最左边
	* @param  y 选择列显示的数据 范围：1~8，1在最下边，1为亮，0为灭
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char x, unsigned char y)
{
	_74HC595_WriteByte(y);
	MATRIX_LED_PORT=~0x80>>(x-1);
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}