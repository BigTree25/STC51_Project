#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__
#include <REGX52.H>

unsigned char OneWire_Init();
void OneWire_SendBit(unsigned char Bit);
unsigned char OneWire_ReceiveBit();
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveByte();


#endif