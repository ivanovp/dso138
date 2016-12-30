/**
 * @file        main.c
 * @brief       Entry point
 * @author      Copyright (C) Peter Ivanov, 2016-2017
 *
 * Created:     2016-12-29 11:58:45
 * Last modify: 2016-12-30 19:44:50 ivanovp {Time-stamp}
 * Licence:     GPLv2
 */
#include "stm32f10x.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "common.h"
#include "usart.h"

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    USART_init();

    USART_puts("\r\nFirmware for DS138 Digital Oscilloscope version " TOSTR(VER_MAJOR) "." TOSTR(VER_MINOR) "\r\n");
    USART_puts("Copyright (C) Peter Ivanov, 2016\r\n");
    USART_puts("License: GPLv2\r\n");
    USART_puts("Compiled on " __DATE__ " " __TIME__ "\r\n");
#ifdef _DEBUG
    USART_puts("*** DEBUG version ***\r\n");
#endif

    while (1)
    {
    }
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
    USART_printf("Wrong parameters value: file %s on line %d\r\n", file, line);

    /* Infinite loop */
    while (1)
    {
    }
}

#endif
