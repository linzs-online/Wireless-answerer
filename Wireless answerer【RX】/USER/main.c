#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include "led.h"
#include "usart.h"
#include "SPI.h"
#include "24l01.h"
#include "delay.h"
#include "core_cm3.h"

u8 rate = 0;
u8 RX_buff[1];

int main(void)   
{	
	delay_init();
	KEY_GPIO_Config();
	LED_GPIO_Config();
	uart_init(115200);//���ڳ�ʼ��
	NRF24L01_Init();   	//��ʼ��NRF24L01 
	
    NRF24L01_RX_Mode(0);
//	NRF24L01_TX_Mode(0);
//	  	LED1(ON);
//	    LED2(ON);
//	    LED3(ON);
//	    LED4(ON);
//	    LED5(ON);
//	    LED6(ON);
//	    LED7(ON);
//	    LED8(ON);
	printf("��ʼ����\r\n");
	while(1)
	{	
		if(NRF24L01_RxPacket(RX_buff) == 0)
		{ 
			//printf("����ѡ��:%x��ѡ��", RX_buff[0]);
			if(RX_buff[0] == 0x01 )	
			 {	
				 printf("����ѡ��:%d��ѡ��\r\n", RX_buff[0]);
				 NRF24L01_RX_Mode(100);
			//	 RX_buff[0] = 0xff;
			//	 NRF24L01_TxPacket(RX_buff); 
				 while(1){printf("����ѡ��:%x��ѡ��\r\n", RX_buff[0]);};
			 }
			else if(RX_buff[0] == 0x02 )	
			 {	
				 printf("����ѡ��:%d��ѡ��\r\n", RX_buff[0]);
				 NRF24L01_RX_Mode(100);
			//	 RX_buff[0] = 0xff;
				// NRF24L01_TxPacket(RX_buff);
				 while(1){printf("����ѡ��:%x��ѡ��\r\n", RX_buff[0]);};
			 }		 
			else if(RX_buff[0] == 0x03 )	
			 {	
				 printf("����ѡ��:%d��ѡ��\r\n", RX_buff[0]);
				 NRF24L01_RX_Mode(100);
				// RX_buff[0] = 0xff;
				// NRF24L01_TxPacket(RX_buff);
				while(1){printf("����ѡ��:%x��ѡ��\r\n", RX_buff[0]);};
			 }
			else if(RX_buff[0] == 0x04 )	
			 {	
				 printf("����ѡ��:%d��ѡ��\r\n", RX_buff[0]);
				 NRF24L01_RX_Mode(100);
			//	 RX_buff[0] = 0xff;
				// NRF24L01_TxPacket(RX_buff);
				while(1){printf("����ѡ��:%x��ѡ��\r\n", RX_buff[0]);};
			 }
			 else if(RX_buff[0] == 0x05 )	
			 {	
				 printf("����ѡ��:%d��ѡ��\r\n", RX_buff[0]);
				 NRF24L01_RX_Mode(100);
				// RX_buff[0] = 0xff;
			//	 NRF24L01_TxPacket(RX_buff);
				 while(1){printf("����ѡ��:%x��ѡ��\r\n", RX_buff[0]);};
			 }
			 else if(RX_buff[0] == 0x06 )	
			 {	
				 printf("����ѡ��:%d��ѡ��\r\n", RX_buff[0]);
				 NRF24L01_RX_Mode(100);
				// RX_buff[0] = 0xff;
			//	 NRF24L01_TxPacket(RX_buff);
				 while(1){printf("����ѡ��:%x��ѡ��\r\n", RX_buff[0]);}; 
			 }
			 else if(RX_buff[0] == 0x07 )	
			 {	
				 printf("����ѡ��:%d��ѡ��\r\n", RX_buff[0]);
				 NRF24L01_RX_Mode(100);
			//	 RX_buff[0] = 0xff;
			//	 NRF24L01_TxPacket(RX_buff);
				while(1){printf("����ѡ��:%x��ѡ��\r\n", RX_buff[0]);};
			 }
	   }
		else 
			printf("�ȴ�����\r\n");
		if(rate > 70 )
		{
			rate = 0;
		}		
	  rate += 10;
		NRF24L01_RX_Mode(rate);
    delay_ms(3);
  }	
 
}	

  

	
