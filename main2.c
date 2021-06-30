#include <stdbool.h>

#include "temp.hpp"
#include "fan.hpp"

#define temp_delta1 2.0 // Difference between temps before we change modes
#define temp_delta2 5.0

enum mode_state{
	st_Idle,
	st_Sense_Temp,
	st_Raise_Fan,
	st_Lower_Fan,
	st_Wait
};

void mode_select(){
	static enum mode_state current_state = st_Idle;
	static float current_temp = 0.0;
	static float last_temp = 0.0;
	
	switch(current_state){
		default:
		case st_Idle:
			current_state = st_Sense_Temp;
			break;
		
		case st_Sense_Temp:
			bool temp_read_success = sense_temperature(&current_temp);
			
			if(last_temp == 0.0){ // if no last_temp set
				last_temp = current_temp;
				break;
			}
			
			if(!temp_read_success){
				Serial.println("Error reading temp...");
				current_state = st_Init;
				break;
			}
			
			float temp_delta = current_temp - last_temp;
			
			if(temp_delta == 0.0){ // do nothing
				current_state = st_Wait;
			}
			else if(temp_delta <= -temp_delta1){ // too cold
				current_state = st_Lower_Fan;
			}
			else if(temp_delta >= temp_delta1){ // too hot
				current_state = st_Raise_Fan;
			}
			else{
				Serial.println("Unexpected temp_delta");
				Serial.print(last_temp);
				Serial.print(" ");
				Serial.print(current_temp);
				Serial.print(" ");
				Serial.println(temp_delta);
				break;
			}
			
			break;
		
		case st_Raise_Fan:
			set_fan_higher();
			current_state = st_Wait;
			break;
		
		case st_Lower_Fan:
			set_fan_lower();
			current_state = st_Wait;
			break;
		
		case st_Wait:
			current_state = st_Idle;
			break;
		
	}
}

/*****************************/
void setup(void){
	Serial.begin(9600);
	init_fan();
	init_temperature();
}

void loop(void){
	
}