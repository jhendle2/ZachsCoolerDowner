#ifndef FAN_HPP
#define FAN_HPP

	#define FAN_OFF 0
	#define FAN_LOW 270
	#define FAN_MED 180
	#define FAN_HIGH 90

	extern enum fan_level{
		fan_off = FAN_OFF,
		fan_low = FAN_LOW,
		fan_med = FAN_MED,
		fan_high = FAN_HIGH
	} current_fan_level;

	void init_fan();
	void set_fan_to_off();
	void set_fan_to_low();
	void set_fan_to_med();
	void set_fan_to_high();
	
	void set_fan_lower();
	void set_fan_higher();

#endif