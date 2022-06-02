class Relay {
  private:
    int pin;
    bool state;
  public:
    Relay() {}
    
    Relay(int pin) {
      this->pin = pin;
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