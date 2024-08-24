/*
 * direction_speed.c
 *
 * Created: 8/3/2024 5:21:25 PM
 *  Author: Mai El Shahed
 */ 

#include <avr/io.h>

#include "Dio.h"
#include "Std_macros.h"

#include "direction_speed.h"


void motor_vinti(){
DDRB=0XFF;//output motor  left

DDRA=0XFF;// motor output right
/*
//L293D Pin 1 -> En1 -> motor 1

SET_BIT(PORTA,2);
//L293D Pin 9 -> En2 -> motor 2
SET_BIT(PORTA,3);
//L293D Pin 1 -> En1 -> motor 3
SET_BIT(PORTB,2);
//L293D Pin 1 -> En2 -> motor 4
SET_BIT(PORTB,6);
*/

//L293D Pin 1 -> En1 -> motor 1


}

		

void left_forword(int speed){
	//left ROTAT MOTOR3-4 CLOCKWISE

	set_motor_speed(3,speed * 0.92);
	set_motor_speed(4,speed * 0.92);
	
	DIO_vwrite('B',0,1);
	DIO_vwrite('B',1,0);
	DIO_vwrite('B',4,0);
	DIO_vwrite('B',5,1);
}


	void right_forword(int speed){
		//right ROTAT MOTOR 1-2 CLOCKWISE
		set_motor_speed(1,speed);
		set_motor_speed(2,speed);
	
		DIO_vwrite('A',0,1);
		DIO_vwrite('A',1,0);
	DIO_vwrite('A',4,0);
	DIO_vwrite('A',5,1);
		
	}

	void motor_forword(int speed){
		
		left_forword(speed);
		right_forword(speed);

		
	}


	void right_backword(int speed2){
		
		// left ROTAT MOTOR1-2 ANTI-CLOCKWISE
		
	set_motor_speed(1,speed2);
	set_motor_speed(2,speed2);
	
	DIO_vwrite('A',0,0);
	DIO_vwrite('A',1,1);
	DIO_vwrite('A',4,1);
	DIO_vwrite('A',5,0);
		
		
	}
	
	void left_backword(int speed2){
		
		
		// left ROTAT MOTOR ANTI-CLOCKWISE
		
		set_motor_speed(3,speed2*.92);
		set_motor_speed(4,speed2*.92);
		
		DIO_vwrite('B',0,0);
		DIO_vwrite('B',1,1);
		DIO_vwrite('B',4,1);
		DIO_vwrite('B',5,0);
		
		
	}
	
		void motor_backword(int speed2){
			
			left_backword(speed2);
			right_backword(speed2);
	
			
		}
		
	
	void turn_right(int right){
		left_forword(right);
		right_backword(right);
		
	}
	
	void turn_left(int left){
		left_backword(left);
		right_forword(left);
	}
	
	void stop_motor(){
		
		left_forword(0);
		right_forword(0);
	}
	
	
	// Function to initialize PWM
	void PWM_init() {
		// Set PWM pins as output
		DDRB |= (1 << MOTOR_1_PIN);
		DDRD |= (1 << MOTOR_2_PIN) | (1 << MOTOR_3_PIN) | (1 << MOTOR_4_PIN);
		
		// Configure Timer0 for PWM (Motor 1)
		TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
		
		// Configure Timer2 for PWM (Motor 2)
		TCCR2 = (1 << WGM20) | (1 << WGM21) | (1 << COM21) | (1 << CS21);
		
		

		
		// Configure Timer1 for PWM (Motor 3 and 4)
		TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
		TCCR1B = (1 << WGM12) | (1 << CS11);
	}

	// Function to set motor speed (0-255)
	void set_motor_speed(unsigned char motor, unsigned char speed) {
		switch(motor) {
			case 1:
			OCR0 = speed;
			break;
			case 2:
			OCR2 = speed;
			break;
			case 3:
			OCR1B = speed;
			break;
			case 4:
			OCR1A = speed;
			break;
		}
	}
	
	

void turn_right_slow(int rslow){
right_forword(rslow/2);
	left_forword(rslow);
	
	
	
}

void turn_left_slow(int slow){
	
	left_forword(slow/2);
	right_forword(slow);
}


/*

void line_follower(){
	////if Right Sensor and Left Sensor are at block color then it will call forword function
			
			if (DIO_uread('D',0)==1 && DIO_uread('D',1)==1){
				motor_forword(120);
			}
			
			
			
			//if Right Sensor is White and Left Sensor is Black then it will call turn Left function
	
			if (DIO_uread('D',0)==0 && DIO_uread('D',1)==1){
				turn_left_slow(200);
			}
//if Right Sensor is black and Left Sensor is white then it will call turn Left function
			if (DIO_uread('D',0)==1 &&DIO_uread('D',1)==0){
				turn_right_slow(200);
			}
			
			//if Right Sensor and Left Sensor are at white color then it will call Stop function
			if (DIO_uread('D',0)==0 && DIO_uread('D',1)==0)
			{
				stop_motor();
			}
			
	
}	
*/