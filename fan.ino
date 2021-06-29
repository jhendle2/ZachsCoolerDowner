#include <fan.hpp>

static void set_fan_to_angle(int angle){
	if(angle<fan_high) current_fan_level = fan_off;
}

void set_fan_to_off();
void set_fan_to_low();
void set_fan_to_med();
void set_fan_to_high();

void turn_on_fan_to_180_deg_and_turn_off_led();