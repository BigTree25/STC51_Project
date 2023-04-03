#include <REGX52.H>

sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;

/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
	
}
/**
  * @brief  I2C结束
  * @param  无
  * @retval 无
  */
void I2C_Stop()
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
	
}
/**
  * @brief  I2C发送一个字节数据
  * @param  Byte 发送的字节数据 范围：0~255
  * @retval 无
  */
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}
/**
  * @brief  I2C接受一个字节数据
  * @param  无
  * @retval Byte 接受的字节数据 范围：0~255
  */
unsigned char I2C_ReceiveByte()
{
	unsigned char i,Byte=0x00;
	for(i=0;i<8;i++)
	{
		I2C_SDA=1;	
		I2C_SCL=1;
		if(I2C_SDA){Byte|=(0x80>>i);}
		I2C_SCL=0;
		
	}
	return Byte;
}
/**
	* @brief  I2C发送应答
	* @param  AckBit 发送应答位，0为应答，1为非应答
  * @retval 无
  */
void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}
/**
	* @brief  I2C接受应答
  * @param  无
	* @retval AckBit 接收应答位，0为应答，1为非应答
  */
unsigned char I2C_ReceiveAck()
{
	unsigned char AckBit;
	I2C_SDA=1;
	I2C_SCL=1;
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return AckBit;
}