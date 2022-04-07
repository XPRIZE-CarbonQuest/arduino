#define RELAY 7

class Electrolysis {
  private:
    int pin;
    bool state;
  public:
    Electrolysis(int pin) {
      this->pin = pin;
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }
     //ajdjsakljdklasjkl

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



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  
}
