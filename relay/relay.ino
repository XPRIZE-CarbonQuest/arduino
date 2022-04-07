#include "Relay.h"
#define RELAY_PIN 7

Relay relay;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  relay = Relay(RELAY_PIN);
}

void loop() {
  delay(5000);
  Serial.write("TOGGLE \n");
  relay.toggle();
}
