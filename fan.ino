#include "fan.hpp"
#include "servo_controller.hpp"

/*****************************/
static set_fan_to(enum fan_level level){
	current_fan_level = level;
	set_servo_angle(level);
}

/*****************************/
void init_fan(){
	init_servo();
}

void set_fan_to_off(){
	set_fan_to(fan_off);
}

void set_fan_to_low(){
	set_fan_to(fan_low);
}

void set_fan_to_med(){
	set_fan_to(fan_med);
}

void set_fan_to_high(){
	set_fan_to(fan_high);
}

void set_fan_lower(){
	if(current_fan_level > fan_off)
		current_fan_level--;
	set_fan_to(current_fan_level);
}

void set_fan_higher(){
	if(current_fan_level < fan_high)
		current_fan_level++;
	set_fan_to(current_fan_level);
}