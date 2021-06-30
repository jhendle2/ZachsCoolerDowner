#include <Servo.h>

#include "pins.hpp"
#include "servo_controller.hpp"

Servo MG995_Servo;

void init_servo(){
	MG995_Servo.attach(Servo_PWM);
}

void set_servo_angle(uint8_t angle){
	MG995_Servo.write(angle);
}

