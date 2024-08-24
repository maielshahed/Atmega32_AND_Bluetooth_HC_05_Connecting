/*
 * USART_DRIVER.h
 *
 * Created: 7/17/2024 2:30:16 AM
 *  Author: RS3
 */ 


#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_


#define F_CPU 1000000UL					/* Define CPU clock Frequency */
#include <avr/io.h>							/* Include AVR std. library file */
#include <math.h>

#define DOUBLE_SPEED_MODE

#ifdef DOUBLE_SPEED_MODE
#define BAUD_PRESCALE (int)round(((((double)F_CPU / ((double)BAUDRATE * 8.0))) - 1.0))	/* Define prescale value */
#else
#define BAUD_PRESCALE (int)round(((((double)F_CPU / ((double)BAUDRATE * 16.0))) - 1.0))	/* Define prescale value */
#endif

void USART_Init(unsigned long);				/* USART initialize function */
char USART_RxChar();						/* Data receiving function */
void USART_TxChar(char);					/* Data transmitting function */
void USART_SendString(char*);				/* Send string of USART data function */


/*
void uart_vinit(unsigned long baud);

void uart_vsenddata(char data);
char uart_receivedata(void);
void uart_vsendstring( char *ptr);
*/
#endif /* USART_DRIVER_H_ */