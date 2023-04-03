#ifndef __IR_H__
#define __IR_H__

#define IR_Vol_

void IR_Init();
unsigned char IR_GetDataFlag();
unsigned char IR_GetRepeatFlag();
unsigned char IR_GetAddress();
unsigned char IR_GetCommand();

#endif