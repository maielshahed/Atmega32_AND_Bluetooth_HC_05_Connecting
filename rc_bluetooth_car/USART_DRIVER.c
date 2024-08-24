/*
 * USART_DRIVER.c
 *
 * Created: 7/17/2024 2:30:37 AM
 *  Author: Mai El Shahed
 */ 



#define F_CPU 1000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "std_macros.h"

#include "USART_DRIVER.h"



void USART_Init(unsigned long BAUDRATE)				/* USART initialize function */
{
	#ifdef DOUBLE_SPEED_MODE
	UCSRA |=(1 << U2X);
	#endif
	UCSRB |= (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);	/* Enable USART transmitter and receiver */
	UCSRC |= (1 << URSEL)| (1 << UCSZ0) | (1 << UCSZ1);	/* Write USCRC for 8 bit data and 1 stop bit */
	UBRRL = BAUD_PRESCALE;							/* Load UBRRL with lower 8 bit of prescale value */
	UBRRH = (BAUD_PRESCALE >> 8);					/* Load UBRRH with upper 8 bit of prescale value */
}

char USART_RxChar()									/* Data receiving function */
{
	while (!(UCSRA & (1 << RXC)));					/* Wait until new data receive */
	return(UDR);									/* Get and return received data */
}

void USART_TxChar(char data)						/* Data transmitting function */
{
	UDR = data;										/* Write data to be transmitting in UDR */
	while (!(UCSRA & (1<<UDRE)));					/* Wait until data transmit and buffer get empty */
}

void USART_SendString(char *str)					/* Send string of USART data function */
{
	int i=0;
	while (str[i]!=0)
	{
		USART_TxChar(str[i]);						/* Send each char of string till the NULL */
		i++;
	}
}
/*

void uart_vinit(unsigned long baud)
{
	//1 - Choose baud rate that will be used by sender and receiver by writing to UBRRL/UBRRH
	unsigned short UBRR ;//16 bit
	
	UBRR=(F_CPU/(16*baud))-1 ;//Asynchronous  Normal  Mode

	UBRRH=(unsigned char)(UBRR>>8);//first 
	UBRRL=(unsigned char)UBRR;
	
	// - Enable USART Sender & Receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	// - Choose number of data bits to be sent,disabled parity 0 and 0 stop bits from UCSRC
	, We will work with 8 bits data,1 stop bit and no parity bits
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}
*/
/*
void uart_vsenddata(char data)
{
	//Wait for UDR transmit buffer to be empty
	transmit buffer TXR--->data------UDRE==1 empty TXR
	while(READ_BIT(UCSRA,UDRE)==0);
	//Put data to UDR transmit buffer transmit
	UDR=data ;//TXR
}
*/
/*
char uart_receivedata(void)
{
	//Wait for UDR receive buffer RXR to be filled with data--> RXR
	RXC==1--->RXR==DATA 
	
	
	while(READ_BIT(UCSRA,RXC)==0);
	//Receive data from UDR receive buffer
	return UDR ;
}

*/


/*

void uart_vsendstring( char *ptr)
{
	while(*ptr!=0)
	{
		uart_vsenddata(*ptr);
		ptr++;
		_delay_ms(100);
	}
}

*/