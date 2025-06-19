#include <ch32v00x_it.h>

uint8_t TRXData[15];
extern int flag_band;

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

int Decode_band(void)
{
    if ((TRXData[0] != 0xFE) || (TRXData[1] != 0xFE) || 
        (TRXData[4] != 0x00 && TRXData[4] != 0x03)) {
        return 0;
    }
    switch (TRXData[8]) {
        case 0x01:
        case 0x02:   return 160; // 160m (1000-2999 kHz)
        case 0x03:
        case 0x04:   return 80;  // 80m (3000-4999 kHz)
        case 0x05:   return 60;  // 60m (5000-5999 kHz)
        case 0x07:   return 40;  // 40m (7000-7999 kHz)
        case 0x10:   return 30;  // 30m (10000-10999 kHz)
        case 0x14:   return 20;  // 20m (14000-14999 kHz)
        case 0x18:   return 17;  // 17m (18000-18999 kHz)
        case 0x21:   return 15;  // 15m (21000-21999 kHz)
        case 0x24:   return 12;  // 12m (24000-24999 kHz)
        case 0x28:
        case 0x29:   return 10;  // 10m (28000-29999 kHz)
        case 0x50:   return 6;   // 6m (50000-50999 kHz)
        default:     return 0;  // Unknown
    }
}

void NMI_Handler(void)
{
  while (1)
  {
  }
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}

__attribute__((interrupt("WCH-Interrupt-fast")))
void TIM2_IRQHandler(void)
{
    static u8 j = 0;
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        GPIO_WriteBit(GPIOC, GPIO_Pin_7, (j == 0) ? (j = Bit_SET) : (j = Bit_RESET));
    }
}

__attribute__((interrupt("WCH-Interrupt-fast")))
void USART1_IRQHandler(void)
{
    if (USART_GetITStatus(USART1, USART_IT_RXNE) == RESET)
        return;
    
    static uint8_t i = 0;
    const uint8_t letter = USART_ReceiveData(USART1);
    
    if (letter == 0xFD) {
        TRXData[i] = letter;
        i = 0;
        flag_band = Decode_band();
    } else {
        TRXData[i++] = letter;
        i %= 15;
    }
    
    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}


