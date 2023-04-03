#include <REGX52.H>
#include "I2C.h"

#define SLAVE_ADDRESS 0xa0
/**
  * @brief  在地址写入一个字节
  * @param  WordAddress 写入的地址 ，Data 写入的数据 0~255
  * @retval 无
  */
void AT24C02_WriteByte(unsigned char WordAddress,Data)
{
	I2C_Start();
	I2C_SendByte(SLAVE_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	I2C_Stop();
}
/**
  * @brief  读取地址的数据
  * @param  WordAddress 读取的数据的地址
	* @retval Data 读取到的数据
  */
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2C_Start();
	I2C_SendByte(SLAVE_ADDRESS);
	I2C_ReceiveAck();
	I2C_SendByte(WordAddress);
	I2C_ReceiveAck();
	I2C_Start();
	I2C_SendByte(SLAVE_ADDRESS|0x01);
	I2C_ReceiveAck();
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	
	return Data;
}