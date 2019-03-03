#include "usart.h"

/**
  * @brief  ���ڳ�ʼ��
  * @param  ��
  * @retval ��
  */
void USART1_Config(void)   
{   
	GPIO_InitTypeDef   GPIO_InitStructure;   
	USART_InitTypeDef  USART_InitStructure; 
  NVIC_InitTypeDef NVIC_InitStructure;	
	/* config USART1 clock */  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);           
	/* USART1 GPIO config */  
	
	/* Configure USART1 Tx (PA.09) as alternate function pushpull */  
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;   
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;   
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Configure USART1 Rx (PA.10) as input floating */  
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;   
	GPIO_Init(GPIOA, &GPIO_InitStructure);     
	
	/* USART1 mode config */  
	USART_InitStructure.USART_BaudRate 						= 115200;   
	USART_InitStructure.USART_WordLength 					= USART_WordLength_8b;   
	USART_InitStructure.USART_StopBits 						= USART_StopBits_1;   
	USART_InitStructure.USART_Parity 							= USART_Parity_No ;   
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;   
	USART_InitStructure.USART_Mode 								= USART_Mode_Rx | USART_Mode_Tx;   
	USART_Init(USART1, &USART_InitStructure);  

  //Usart1 NVIC ����
  NVIC_InitStructure.NVIC_IRQChannel 										= USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 3;				   //��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority 				= 3;				   //�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd 								= ENABLE;		   //IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);																		   //����ָ���Ĳ�����ʼ��VIC�Ĵ���
   
//  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�����ж�
	USART_Cmd(USART1, ENABLE);   
}

/**
  * @brief  ���ڷ����ֽ�
  * @param  ��
  * @retval ��
  */
void usart_send(char ch)
{
	USART_SendData(USART1, (uint8_t) ch);	
  while( USART_GetFlagStatus(USART1,USART_FLAG_TC)!= SET);
}

/**
  * @brief  ��ӡ�ַ���
  * @param  ��
  * @retval ��
  */
void printf(char *p )
{
  while( *p != '\0' ){
  usart_send(*p);p++;}
}


/**
  * @brief  �������ͱ���
  * @param  ��
  * @retval ��
  */
void UART_Send_int(int16_t Data)
{ 
  if(Data<0)
	{
	usart_send(0x2D);
	Data=-Data;
	}
	usart_send(Data/10000+48);	   
	Data=Data%10000;
	usart_send(Data/1000+48);
	Data=Data%1000;
	usart_send(Data/100+48);
	Data=Data%100;
	usart_send(Data/10+48);
	usart_send(Data%10+48);
}

/**
  * @brief  ����float�ͱ���
  * @param  ��
  * @retval ��
  */
void UART_Send_float( float DATA)
{
  int32_t Data;
	Data=DATA*100;
	if(Data<0)
	{
	usart_send(0x2D);
	Data=-Data;
	}	   
	usart_send(Data/100000+48);
	Data=Data%100000;
	usart_send(Data/10000+48);
	Data=Data%10000;
	usart_send(Data/1000+48);
	Data=Data%1000;
	usart_send(Data/100+48);
	Data=Data%100;
	usart_send(0x2E);
	usart_send(Data/10+48);
	usart_send(Data%10+48);
}

/**
  * @brief  ����1�жϷ���
  * @param  ��
  * @retval ��
  */
void USART1_IRQHandler(void)                	          
{
	uint8_t Res;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)   //�����ж�
  {
	Res =USART_ReceiveData(USART1);                       	//��ȡ���յ�������
	usart_send(Res);
	}
}


unsigned char Uart1_Put_Char( unsigned char Send_Data )
{
	usart_send(Send_Data);
	return Send_Data;
}
unsigned char UART1_Put_int(unsigned int Send_Data )
{
	unsigned char sum = 0;
	sum +=Uart1_Put_Char( Send_Data/256 );
	sum +=Uart1_Put_Char( Send_Data%256 );
	return sum;
}

