#include "stm32f10x.h"
#include <stdio.h>
#include <stdarg.h>

#define CONSOLE_USART USART1
#define USART_PRINTF_BUF_SIZE 128

USART_InitTypeDef USART_InitStructure;

/* Private function prototypes -----------------------------------------------*/

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
  
/* Private functions ---------------------------------------------------------*/

/**
 * Read one byte from serial port. It waits for the data.
 *
 * @return The received character.
 */
unsigned char USART_getc (void)
{
    while (USART_GetFlagStatus(CONSOLE_USART, USART_FLAG_RXNE) == SET)
    {
    }
    /* Return the data */
    return USART_ReceiveData(CONSOLE_USART);
}

/**
 * Write one byte to the serial port.
 *
 * @param data Byte to send.
 */
void USART_putc (unsigned char data)
{
    USART_SendData(CONSOLE_USART, (uint8_t) data);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(CONSOLE_USART, USART_FLAG_TC) == RESET)
    {
    }
}

/**
 * Write a null-terminated string to the serial port.
 *
 * @param data String to send.
 */
void USART_puts (const char *data)
{
    while (*data)
    {
        USART_putc (*data);
        data++;
    }
}

/**
 * Printf function which uses UART interface to send.
 * Example:
<pre>
UART_printf ("Number: %02i\r\n", number);
</pre>
 *
 * @param fmt Printf format string. Example: "Value: %02i\r\n"
 */
void USART_printf (const char *fmt, ...)
{
    static va_list valist;
    char buf[USART_PRINTF_BUF_SIZE];

    va_start (valist, fmt);
    vsnprintf (buf, sizeof (buf), fmt, valist);
    va_end (valist);
    USART_puts (buf);
}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    GPIO_InitTypeDef  GPIO_InitStruct;
    USART_InitTypeDef USART_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_9;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    USART_DeInit(CONSOLE_USART);
    USART_InitStructure.USART_BaudRate            = 115200;
    USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits            = USART_StopBits_1;
    USART_InitStructure.USART_Parity              = USART_Parity_No;
    USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init(CONSOLE_USART, &USART_InitStructure);

    USART_Cmd(CONSOLE_USART, ENABLE);

    USART_putc('!');
    USART_puts("\r\nUSART test!\r\n");
    /* Output a message on Hyperterminal using printf function */
    USART_printf("\n\rUSART printf test\n\r");

    while (1)
    {
    }
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
    USART_SendData(CONSOLE_USART, (uint8_t) ch);

    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(CONSOLE_USART, USART_FLAG_TC) == RESET)
    {
    }

    return ch;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}

#endif
