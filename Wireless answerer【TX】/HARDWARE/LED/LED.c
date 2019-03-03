#include "LED.h"
#include "delay.h"
/**
  * @brief  LED初始化
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)   
{          
      GPIO_InitTypeDef GPIO_InitStructure;
	
      RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
      
	    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11|GPIO_Pin_12 | GPIO_Pin_0 | GPIO_Pin_2;          
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;             
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;  	    	
	    GPIO_Init(GPIOA, &GPIO_InitStructure);  
	    
	    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_1|GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;          
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;             
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;  	    	
	    GPIO_Init(GPIOB, &GPIO_InitStructure);  
	  
	    LED1(OFF);
	    LED2(OFF);
	    LED3(OFF);
	    LED4(OFF);
	    LED5(OFF);
	    LED6(OFF);
	    LED7(OFF);
	    LED8(OFF);
}   
/**
  * @brief  按键初始化
  * @param  无
  * @retval 无
  */
void KEY_GPIO_Config(void)   
{          
      GPIO_InitTypeDef GPIO_InitStructure;
	
      RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3  ;          
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPD;             
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;  
	   // GPIO_ResetBits(GPIOA,GPIO_Pin_3);
      
	    GPIO_Init(GPIOA, &GPIO_InitStructure);  
	
}
/**
  * @brief  蜂鸣器初始化
  * @param  无
  * @retval 无
  */
void BUZZER_GPIO_Config(void)   
{          
      GPIO_InitTypeDef GPIO_InitStructure;
	
      RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);
      GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5  ;          
      GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;             
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;  
	    GPIO_SetBits(GPIOA,GPIO_Pin_5);
      
	    GPIO_Init(GPIOA, &GPIO_InitStructure);  
	
} 
/**
  * @brief  获取按键值
  * @param  无
  * @retval 无
  */
int KEY_Scan(void)
{
   if( KEY == 1)		
	 {
		 delay_ms(10);
		 if( KEY == 1)
			 return 1;
		 else 
			 return 0;
	 }
	 else 
		 return 0;

}
