#include <PHSensor.h>
#define OFFSET 

PHSensor carbon_sensor;

void setup() {
  // put your setup code here, to run once:
  carbon_sensor = PHSensor(A0, OFFSET);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  carbon_sensor.read();
  
  
  
}