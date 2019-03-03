#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "led.h"
#include "usart.h"
#include "SPI.h"
#include "24l01.h"
#include "delay.h"

int ok;

u8 TX_buff[1];
u8 RX_buff[1];

int main(void)   
{	
	delay_init();
	KEY_GPIO_Config();
	LED_GPIO_Config();
	BUZZER_GPIO_Config();
	uart_init(115200);//串口初始化
	NRF24L01_Init();   	//初始化NRF24L01 
	
  NRF24L01_TX_Mode(50);   //频道设置

	TX_buff[0] = 0x05;      //从机编号
	

	while(1)
	{

 		
 if( KEY_Scan() == 1)	
  {					 
		if(	 NRF24L01_TxPacket(TX_buff) == TX_OK )
		{	
      BUZZER(ON);	 	
			LED1(ON);     
	    LED2(ON);
	    LED3(ON);    
	    LED4(ON);    
	    LED5(ON);
	    LED6(ON);
	    LED7(ON);
	    LED8(ON);
			 delay_ms(500);
			 BUZZER(OFF);
			LED1(OFF);     
	    LED2(OFF);
	    LED3(OFF);    
	    LED4(OFF);    
	    LED5(OFF);
	    LED6(OFF);
	    LED7(OFF);
	    LED8(OFF);
			delay_ms(500);			
			for(int i = 0;i < 5 ;i++)
			{
			LED1(ON);     
	    LED2(ON);
	    LED3(ON);    
	    LED4(ON);    
	    LED5(ON);
	    LED6(ON);
	    LED7(ON);
	    LED8(ON);
		  delay_ms(500);
			LED1(OFF);     
	    LED2(OFF);
	    LED3(OFF);    
	    LED4(OFF);    
	    LED5(OFF);
	    LED6(OFF);
	    LED7(OFF);
	    LED8(OFF);
			delay_ms(500);
			
//			 if( KEY == 1)
//			 {
//				  delay_ms(1000);
//		      if( KEY == 1)
//			    {
//				     delay_ms(1000);
//              if( KEY == 1)
//			        { 
//								delay_ms(1000);
//				        if( KEY == 1)
//			          { 
//									 BUZZER(ON);
//				           delay_ms(250);
//									 BUZZER(OFF);
//									 delay_ms(250);
//									 BUZZER(ON);
//									 delay_ms(250);
//									 BUZZER(OFF);
//									 delay_ms(250);
//									 BUZZER(ON);
//				           delay_ms(250);
//									 BUZZER(OFF);
//									 delay_ms(250);
//									 BUZZER(ON);
//									 delay_ms(250);
//									 BUZZER(OFF);
//									 delay_ms(250);
//			       									 
//										__set_FAULTMASK(1); // 关闭所有中断
//				            NVIC_SystemReset(); // 复位	
//			             
//		             }
//							 }
//	         }
//        }
		  }
//			for(int j = 0;j < 10 ;j++)
//			{
//			BUZZER(ON);
//			LED1(ON);     
//	    LED2(ON);
//	    LED3(ON);    
//	    LED4(ON);    
//	    LED5(ON);
//	    LED6(ON);
//	    LED7(ON);
//	    LED8(ON);
//			delay_ms(250);
//			LED1(OFF);     
//	    LED2(OFF);
//	    LED3(OFF);    
//	    LED4(OFF);    
//	    LED5(OFF);
//	    LED6(OFF);
//	    LED7(OFF);
//	    LED8(OFF);
//			delay_ms(250);
//		  BUZZER(OFF);
//			LED1(ON);     
//	    LED2(ON);
//	    LED3(ON);    
//	    LED4(ON);    
//	    LED5(ON);
//	    LED6(ON);
//	    LED7(ON);
//	    LED8(ON);
//			delay_ms(250);
//			LED1(OFF);     
//	    LED2(OFF);
//	    LED3(OFF);    
//	    LED4(OFF);    
//	    LED5(OFF);
//	    LED6(OFF);
//	    LED7(OFF);
//	    LED8(OFF);
//			delay_ms(250);
//		 }	
			
	 }
  }		
 }
}	

	
