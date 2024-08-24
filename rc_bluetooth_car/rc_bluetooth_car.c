/*
 * rc_bluetooth_car.c
 *
 * Created: 8/17/2024 7:22:44 PM
 *  Author: Mai El Shahed
 */ 


#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>

#include "Dio.h"
#include "direction_speed.h"
#include "USART_DRIVER.h"


int main(void)
{
	char val;
	// OUTPUT LED RED      
	DIO_vsetpindir('D',2,1);
	DIO_vsetpindir('D',3,1);
	// OUTPUT LED BLUE  A PIN 2-3
	//uart_vinit(9600);
USART_Init(9600);		
	
	 motor_vinti();
	 PWM_init();
    while(1)
    {
        //TODO:: Please write your application code 
		//val=uart_receivedata();
		val= USART_RxChar()	;
		
		switch(val){
			
			case 'F':
			motor_forword(200);
			break;
			
			case 'B':
			motor_backword(200);
			break;
			
			case 'G':
			turn_left(200);
			break;
			case 'R':
			turn_right(200);
			break;
			case 'I':
			turn_right(200);
			break;
			
			case 'L':
			turn_left(200);
			break;
			
			case 'S':
			stop_motor();
			break;
			
			case 'W':
			DIO_vwrite('A',2,1);
			DIO_vwrite('A',3,1);
			break;
			
			case 'w':
			DIO_vwrite('A',2,0);
			DIO_vwrite('A',3,0);
			break;
			
			case 'U':
			DIO_vwrite('D',2,1);
			DIO_vwrite('D',3,1);
			break;
			
			case 'u':
			DIO_vwrite('D',2,0);
			DIO_vwrite('D',3,0);
			break;
		}
		
		
    }
}