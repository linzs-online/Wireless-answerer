#ifndef _USART_H_   
#define _USART_H_  

#include "stm32f10x.h"



void usart_send(char ch);
void printf(char *p);
void UART_Send_int(int16_t Data);
void UART_Send_float(float Data);
void UART1_ReportIMU(int ax,int ay,int az,int gx,int gy,int gz,int hx,int hy,int hz,int yaw,int pitch,int roll);
void USART1_Config(void);

#endif 
