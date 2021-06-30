#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>

Servo MG995_Servo;

#define SERVO_PWM 9
#define TEMPERATURE_PIN 2

OneWire oneWire(TEMPERATURE_PIN);

DallasTemperature sensors(&oneWire);

void setup(void){
	Serial.begin(9600);
	sensors.begin();
	MG995_Servo.attach(Servo_PWM);
}

enum ZachState{
	st_Init,
	st_Sense_Temp,
	st_Raise_Fan,
	st_Lower_Fan,
	st_Wait
};

void ZachFSM(){
	static enum ZachState current = st_Init;
	
	switch(current){
		default:
		case st_Init:
			break;
		
		case st_Sense_Temp:
			break;
		
		case st_Raise_Fan:
			
			break;
		
		case st_Lower_Fan:
			break;
		
		case st_Wait:
			break;
		
	}
}

void loop(void){
	/*sensors.requestTemperatures();
	float tempF = sensors.getTempCByIndex(0) * (9.0/5.0) + 32;
	
	if(tempF != DEVICE_DISCONNECTED_C){
		Serial.println(tempF);
	}
	else{
		Serial.println("Could not read temperature data");
	}*/
	
	
}