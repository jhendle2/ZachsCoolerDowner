#include <OneWire.h>
#include <DallasTemperature.h>

#define TEMPERATURE_PIN 2

OneWire oneWire(TEMPERATURE_PIN);

DallasTemperature sensors(&oneWire);

void setup(void){
	Serial.begin(9600);
	sensors.begin();
}

void loop(void){
	sennsors.requestTemperatures();
	float tempF = sensors.getTempCByIndex(0) * (9.0/5.0) + 32;
	
	if(tempF != DEVICE_DISCONNECTED_C){
		Serial.println(tempF);
	}
	else{
		Serial.println("Could not read temperature data");
	}
}