/*
 * direction_speed.h
 *
 * Created: 8/3/2024 5:21:59 PM
 *  Author: RS3
 */ 


#ifndef DIRECTION_SPEED_H_
#define DIRECTION_SPEED_H_


// Define motor control pins
#define MOTOR_1_PIN PB3  // OC0 pin for PWM
#define MOTOR_2_PIN PD7  // OC2 pin for PWM
#define MOTOR_3_PIN PD4  // OC1B pin for PWM
#define MOTOR_4_PIN PD5  // OC1A pin for PWM

void motor_vinti();
	void motor_forword(int speed);
			void motor_backword(int speed2);
			
			
			void turn_left(int left);
			void stop_motor();
			void turn_right(int right);
			
			
void left_forword(int speed);
void left_backword(int speed2);
void right_forword(int speed);
void right_backword(int speed2);
 
void PWM_init();
	void set_motor_speed(unsigned char motor, unsigned char speed);
	void turn_right_slow(int rslow);
void turn_left_slow(int slow);

void loop();

#endif /* DIRECTION_SPEED_H_ */