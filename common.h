/**
 * @file        common.h
 * @brief       Common defines
 * @author      (C) Peter Ivanov, 2007
 * 
 * Created:     2007-05-19 11:29:32
 * Last modify: 2014-02-15 08:08:14 ivanovp {Time-stamp}
 * Licence:     GPL
 */
#ifndef __INCLUDE_COMMON_H
#define __INCLUDE_COMMON_H

#define VER_MAJOR           0
#define VER_MINOR           1

#if 0
#define LED_OUT             P1OUT
#define GREEN_LED           (BIT5)            // GREEN LED - P1.5
#define GREEN_LED_ON()      LED_OUT |= GREEN_LED
#define GREEN_LED_OFF()     LED_OUT &= ~GREEN_LED
#define GREEN_LED_TOGGLE()  LED_OUT ^= GREEN_LED
#endif

#ifndef bool_t
typedef char bool_t;
#endif
#ifndef TRUE
#define TRUE                1
#endif
#ifndef FALSE
#define FALSE               0
#endif

#define XSTR(x)             #x
#define TOSTR(x)            XSTR(x)

#endif // __INCLUDE_COMMON_H
