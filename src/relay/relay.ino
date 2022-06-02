#define RELAY_PIN 2

class Relay {
  private:
    int pin;
    bool state;
  public:
    Relay() {}
    
    Relay(int pin, double ph_target) {
      this->pin = pin;
      this->ph_target = ph_target;
      
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }

    void on() {
      digitalWrite(pin, HIGH);
      state = HIGH;
    }

    void off() {
      digitalWrite(pin, LOW);
      state = LOW;
    }

    void toggle() {
      state = !state;
      digitalWrite(pin, state);
    }

    void power(bool state) {
      this->state = state;
      digitalWrite(pin, state);
    }
};


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
