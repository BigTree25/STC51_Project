#ifndef __MATRIX_LED_H_
#define __MATRIX_LED_H_

void MatrixLED_Init();

void _74HC595_WriteByte(unsigned char a);

void MatrixLED_ShowColumn(unsigned char x, unsigned char y);

#endif