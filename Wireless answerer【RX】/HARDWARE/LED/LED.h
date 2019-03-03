#ifndef _LED_H_  
#define _LED_H_   
  	
#include "stm32f10x.h"   
 
#define ON    0
#define OFF   1 
 
 
#define LED1(a) if (a) GPIO_SetBits(GPIOA,GPIO_Pin_11);  else  GPIO_ResetBits(GPIOA,GPIO_Pin_11);
#define LED2(a) if (a) GPIO_SetBits(GPIOA,GPIO_Pin_12);  else  GPIO_ResetBits(GPIOA,GPIO_Pin_12);
#define LED3(a) if (a) GPIO_SetBits(GPIOB,GPIO_Pin_2);  else  GPIO_ResetBits(GPIOB,GPIO_Pin_2);
#define LED4(a) if (a) GPIO_SetBits(GPIOB,GPIO_Pin_1);  else  GPIO_ResetBits(GPIOB,GPIO_Pin_1);
#define LED5(a) if (a) GPIO_SetBits(GPIOA,GPIO_Pin_0);  else  GPIO_ResetBits(GPIOA,GPIO_Pin_0);
#define LED6(a) if (a) GPIO_SetBits(GPIOA,GPIO_Pin_2);  else  GPIO_ResetBits(GPIOA,GPIO_Pin_2);
#define LED7(a) if (a) GPIO_SetBits(GPIOB,GPIO_Pin_3);  else  GPIO_ResetBits(GPIOB,GPIO_Pin_3);
#define LED8(a) if (a) GPIO_SetBits(GPIOB,GPIO_Pin_4);  else  GPIO_ResetBits(GPIOB,GPIO_Pin_4);

#define KEY PAin(3) 


void LED_GPIO_Config(void);
void KEY_GPIO_Config(void); 


#endif 
