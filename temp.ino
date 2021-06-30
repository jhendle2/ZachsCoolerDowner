#include <OneWire.h>
#include <DallasTemperature.h>
#include <stdbool.h>

#include "pins.hpp"
#include "temp.hpp"

OneWire oneWire(TEMPERATURE_PIN);
DallasTemperature sensors(&oneWire);

void init_temperature(){
	sensors.begin();
}

// Returns a bool to determine if the reading was a success
bool sense_temperature_F(float* temp){
	sensors.requestTemperatures();
	float tempF = sensors.getTempCByIndex(0) * (9.0/5.0) + 32;
	
	if(tempF != DEVICE_DISCONNECTED_C){
		*temp = 0.0;
		return false;
	}
	else{
		*temp = tempF;
		return true;
	}
}