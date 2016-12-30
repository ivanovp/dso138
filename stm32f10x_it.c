/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

#ifdef _DEBUG
extern void USART_putc (unsigned char data);

void _print (char * s)
{
    while (*s)
    {
        USART_putc((uint8_t)*s++);
    }
}

static const char  hexChars[] = "0123456789ABCDEF";

void _printHex32 (uint32_t aNum)
{
    int  i = 8;

    while (i-- > 0)
    {
        USART_putc(hexChars[(aNum >> 28) & 0xF]);
        aNum <<= 4;
    }
}

void _printHex16 (uint16_t aNum)
{
    int  i = 4;

    while (i-- > 0)
    {
        USART_putc(hexChars[(aNum >> 12) & 0xF]);
        aNum <<= 4;
    }
}

void _printHex8 (uint8_t aNum)
{
    USART_putc(hexChars[(aNum >> 4) & 0xF]);
    USART_putc(hexChars[aNum & 0xF]);
}

void HardFault_Handler (void)
{
    uint8_t   end = 0;
    uint32_t  ccr = *((volatile uint32_t *)0xE000ED14);
    uint32_t  cfsr = *((volatile uint32_t *)0xE000ED28);
    uint32_t  hfsr = *((volatile uint32_t *)0xE000ED2C);
    uint32_t  mmfar = *((volatile uint32_t *)0xE000ED34);
    uint32_t  bfar = *((volatile uint32_t *)0xE000ED38);
    uint32_t  afsr = *((volatile uint32_t *)0xE000ED3C);
    uint32_t  dfsr = *((volatile uint32_t *)0xE000ED30);
    uint16_t  ufsr = cfsr >> 16;
    uint8_t   mmfsr = cfsr & 0xFF;
    uint8_t   bfsr = (cfsr >> 8) & 0xFF;

    _print("\r\n\r\nHardFault exception!\r\n");
    _print("CCR:   0x");
    _printHex32(ccr);

    _print("\r\nCFSR:  0x");
    _printHex32(cfsr);

    _print("\r\nUFSR:  0x");
    _printHex16(ufsr);
    if (ufsr & 0x0100)
    {
        _print(" Unaligned access!");
    }

    if (ufsr & 0x0200)
    {
        _print(" Division by zero!");
    }

    _print("\r\nHFSR:  0x");
    _printHex32(hfsr);

    _print("\r\nMMFSR: 0x");
    _printHex8(mmfsr);

    _print("\r\nMMFAR: 0x");
    _printHex32(mmfar);

    _print("\r\nBFSR:  0x");
    _printHex8(bfsr);

    _print("\r\nBFAR:  0x");
    _printHex32(bfar);

    _print("\r\nAFSR:  0x");
    _printHex32(afsr);

    _print("\r\nDFSR:  0x");
    _printHex32(dfsr);

    _print("\r\n");

    if (CoreDebug->DHCSR & 1)
    {
//        __breakpoint (0);
    }

    while (!end)
    {
    }
}
#else
void HardFault_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}
#endif

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
