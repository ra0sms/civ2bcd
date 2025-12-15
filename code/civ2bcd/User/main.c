#include "main.h"

int flag_band=0;

void Set_Outputs()
{
    switch(flag_band) {
        case 160: 
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_SET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_RESET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_RESET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_SET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_RESET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_RESET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 80:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_RESET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_SET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_RESET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_RESET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_SET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_RESET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 60:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_RESET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_RESET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_RESET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_RESET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_RESET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_RESET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 40:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_SET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_SET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_RESET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_SET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_SET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_RESET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 30:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_RESET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_RESET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_SET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_RESET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_RESET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_SET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 20: 
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_SET); 
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_RESET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_SET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_SET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_RESET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_SET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 17:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_RESET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_SET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_SET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_RESET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_SET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_SET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 15: 
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_SET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_SET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_SET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_RESET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_SET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_SET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_SET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_RESET);
            break;
            
        case 12:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_RESET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_RESET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_RESET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_SET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_RESET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_RESET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_RESET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_SET);
            break;
            
        case 10:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_SET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_RESET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_RESET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_SET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_SET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_RESET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_RESET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_SET);
            break;
            
        case 6:  
            GPIO_WriteBit(OUT_A1_Port, OUT_A1, Bit_RESET);
            GPIO_WriteBit(OUT_B1_Port, OUT_B1, Bit_SET);
            GPIO_WriteBit(OUT_C1_Port, OUT_C1, Bit_RESET);
            GPIO_WriteBit(OUT_D1_Port, OUT_D1, Bit_SET);
            GPIO_WriteBit(OUT_A2_Port, OUT_A2, Bit_RESET);
            GPIO_WriteBit(OUT_B2_Port, OUT_B2, Bit_SET);
            GPIO_WriteBit(OUT_C2_Port, OUT_C2, Bit_RESET);
            GPIO_WriteBit(OUT_D2_Port, OUT_D2, Bit_SET);
            break;
            
        default:
            break;
    }
}

void Timer2_INIT(u16 arr, u16 psc)
{
    TIM_TimeBaseInitTypeDef TIMBase_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    TIMBase_InitStruct.TIM_Period = arr;
    TIMBase_InitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIMBase_InitStruct.TIM_Prescaler = psc;
    TIMBase_InitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM2, &TIMBase_InitStruct);

    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 5;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
    TIM_Cmd(TIM2, ENABLE);
}

void GPIO_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    struct {
        GPIO_TypeDef* port;
        uint16_t pin;
    } pins[] = {
        {LED_GPIO_Port, LED_Pin},
        {OUT_A1_Port, OUT_A1},
        {OUT_B1_Port, OUT_B1},
        {OUT_C1_Port, OUT_C1},
        {OUT_D1_Port, OUT_D1},
        {OUT_A2_Port, OUT_A2},
        {OUT_B2_Port, OUT_B2},
        {OUT_C2_Port, OUT_C2},
        {OUT_D2_Port, OUT_D2}
    };
    
    for (size_t i = 0; i < sizeof(pins)/sizeof(pins[0]); i++) {
        GPIO_InitStructure.GPIO_Pin = pins[i].pin;
        GPIO_Init(pins[i].port, &GPIO_InitStructure);
    }
    
    Delay_Ms(200);
    
    // §µ§ã§ä§Ñ§ß§à§Ó§Ü§Ñ §Ó§ã§Ö§ç §Ó§í§ç§à§Õ§à§Ó §Ó §è§Ú§Ü§Ý§Ö
    for (size_t i = 1; i < sizeof(pins)/sizeof(pins[0]); i++) { 
        GPIO_WriteBit(pins[i].port, pins[i].pin, Bit_SET);
    }
}

void USARTx_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

    /* USART1 TX-->D.5   RX-->D.6 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = BAUD_RATE;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &USART_InitStructure);
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_Cmd(USART1, ENABLE);
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    GPIO_INIT();
    USARTx_CFG();
    Timer2_INIT(499, 7999);
    while(1)
    {
        Set_Outputs();
    	Delay_Ms(10);
    }
}
