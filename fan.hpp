#ifndef FAN_H
#define FAN_H



extern enum fan_level{
	fan_off = 0,
	fan_low = 180,
	fan_med = 90,
	fan_high = 45
} current_fan_level;


void set_fan_to_off();
void set_fan_to_low();
void set_fan_to_med();
void set_fan_to_high();

#endif