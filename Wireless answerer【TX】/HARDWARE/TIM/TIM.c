#include  "TIM.h"
#include  "usart.h"
#include  "adc.h"
#include "SysTick.h"
#include "LED.h"

/**************************ʵ�ֺ���********************************************
*����ԭ��:		
*��������:1ms�ж�һ��,������Ϊ1000		
*******************************************************************************/
void Tim3_Init(u16 period_num)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_DeInit(TIM3);

	TIM_TimeBaseStructure.TIM_Period        = period_num;   //װ��ֵ	//prescaler is 1200,that is 72000000/72/500=2000Hz;
	TIM_TimeBaseStructure.TIM_Prescaler     = 72-1;         //��Ƶϵ��
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //or TIM_CKD_DIV2 or TIM_CKD_DIV4
	TIM_TimeBaseStructure.TIM_CounterMode   = TIM_CounterMode_Up;
	
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);	
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );   //ʹ��ָ����TIM3�ж�,��������ж�
	
	//�ж����ȼ�NVIC����	
	NVIC_InitStructure.NVIC_IRQChannel                   = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;          //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 3;          //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;     //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx		
}
unsigned int  VCC;
unsigned int  ms;
unsigned int  RX_speed;
unsigned int  TX_speed;

int roll;
int pitch;
int yaw;

int X_g;
int Y_g;
int Z_g;

int X_w;
int Y_w;
int Z_w;

/*void RX_TX_Times(void)
{
	ms++;
	if(ms>=100)
	{
	RX_speed=RX_times;
	RX_times=0;
	TX_speed=TX_times;
	TX_times=0;
	ms=0;
	}
}*/
/*void TME_5ms(void)
{
	
}
void TME_10ms(void)
{
	ADC1_Value();
  RX_TX_Times();
	NRF_TxPacket_AP(TxBuf,16);
	Nrf_Check_Event();

	roll  = NRFRX[0]-10000;
	pitch = NRFRX[1]-10000;
	yaw   = NRFRX[2]-10000;	
	X_g   = NRFRX[3]-10000;
	Y_g   = NRFRX[4]-10000;
	Z_g   = NRFRX[5]-10000;	
  X_w   = NRFRX[6]-10000;
	Y_w   = NRFRX[7]-10000;
	Z_w   = NRFRX[8]-10000;
 
	NRFTX[0] = accelerator;
	NRFTX[1] = Pitch_ta    +30000;
	NRFTX[2] = Roll_ta     +30000;
	NRFTX[3] = Yaw_ta      +30000;
	NRFTX[4] = 1;

//	UART1_ReportIMU(X_g,Y_g,Z_g,X_w,Y_w,Z_w,RX_speed,TX_speed,accelerator,roll,pitch,yaw/10);

}
void TIM3_IRQHandler(void)		
{	
	static u8 ms10 = 0;				//�жϴ���������
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)    //���TIM3�����жϷ������
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );       //���TIMx�����жϱ�־ 
		
		ms10++;
				
		TME_5ms();
		if(ms10==2) 
		{
		ms10=0;					
		TME_10ms();
		}
	}
}*/

