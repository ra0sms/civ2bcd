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
    static uint8_t state = 0;  // 0 = §à§Ø§Ú§Õ§Ñ§ß§Ú§Ö FE, 1 = §à§Ø§Ú§Õ§Ñ§ß§Ú§Ö §Ó§ä§à§â§à§Ô§à FE, 2 = §á§â§Ú§×§Þ §ä§Ö§Ý§Ñ §á§Ñ§Ü§Ö§ä§Ñ
    const uint8_t byte = USART_ReceiveData(USART1);

    switch (state) {
        case 0: // §°§Ø§Ú§Õ§Ñ§Ö§Þ §á§Ö§â§Ó§í§Û 0xFE
            if (byte == 0xFE) {
                state = 1;
                TRXData[0] = 0xFE;
                i = 1;
            }
            break;

        case 1: // §°§Ø§Ú§Õ§Ñ§Ö§Þ §Ó§ä§à§â§à§Û 0xFE
            if (byte == 0xFE) {
                TRXData[1] = 0xFE;
                i = 2;
                state = 2;
            } else {
                state = 0; // §ã§Ò§â§à§ã ¡ª §ß§Ö FE, §ß§Ñ§é§Ú§ß§Ñ§Ö§Þ §Ù§Ñ§ß§à§Ó§à
            }
            break;

        case 2: // §±§â§Ú§×§Þ §ä§Ö§Ý§Ñ §á§Ñ§Ü§Ö§ä§Ñ
            if (i < sizeof(TRXData)) {
                TRXData[i++] = byte;
            } else {
                state = 0; // §á§Ö§â§Ö§á§à§Ý§ß§Ö§ß§Ú§Ö ¡ª §ã§Ò§â§à§ã
                break;
            }

            if (byte == 0xFD) { // §Ü§à§ß§Ö§è §á§Ñ§Ü§Ö§ä§Ñ
                // §±§Ñ§Ü§Ö§ä §á§â§Ú§ß§ñ§ä: TRXData[0..i-1], §Õ§Ý§Ú§ß§Ñ = i
                flag_band = Decode_band();
                state = 0; // §Ô§à§ä§à§Ó§í §Ü §ã§Ý§Ö§Õ§å§ð§ë§Ö§Þ§å §á§Ñ§Ü§Ö§ä§å
            }
            break;

        default:
            state = 0;
    }

    USART_ClearITPendingBit(USART1, USART_IT_RXNE);
}


