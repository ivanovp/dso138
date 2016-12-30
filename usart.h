/**
 * @file        usart.h
 * @brief       Serial interface functions header
 * @author      Copyright (C) Peter Ivanov, 2010-2017
 *
 * Created:     2010-08-07 11:58:45
 * Last modify: 2011-09-03 09:15:50 ivanovp {Time-stamp}
 * Licence:     GPLv2
 */
#ifndef __INCLUDE_USART_H
#define __INCLUDE_USART_H

extern void USART_init (void);
extern unsigned char USART_getc (void);
extern void USART_putc (unsigned char data);
extern void USART_puts (const char *data);
extern void USART_printf (const char *fmt, ...);
extern void USART_printHexByte (char n);

#endif // __INCLUDE_USART_H
