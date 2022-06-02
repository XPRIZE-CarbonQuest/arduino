//constants, no imports

#define RELAY_PIN 2
#define OFFSET -2
#define SENSOR_PIN A0
#define TARGET 6
#define DEADZONE 0.5

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

Relay relay;
double current_ph;

bool check_ph(double ph) {
    if (abs(ph - TARGET)<=DEADZONE) {
        relay.toggle();
        return 0;
    }
}

 class PHSensor {
    private:
        int pin;
        double offset;
    public:
        PHSensor() {}
        PHSensor(int pin) {
            this->pin = pin;
            offset = 0;
        }

        PHSensor(int pin, double offset) {
            this->pin = pin;
            this->offset = offset;
        }

        double read() {
            int buf[10]; //buffer for read analog
            for(int i=0;i<10;i++) {
                buf[i]=analogRead(this->pin); delay(10); }
                for(int i=0;i<9;i++) {
                    for(int j=i+1;j<10;j++) {
                        if(buf[i]>buf[j]) {
                            int temp=buf[i];
                            buf[i]=buf[j];
                            buf[j]=temp; 
                        }
                    } 
                }

            int avgValue=0; 
            for(int i=2;i<8;i++) {
                avgValue+=buf[i];
            }
            double phValue = (double)avgValue*5.0/1024/6; //convert the analog into millivolt
            phValue = 3.5 * phValue + this->offset;
            Serial.println(phValue,2); 
            digitalWrite(13, HIGH); 
            delay(800); 
            digitalWrite(13, LOW);

            current_ph = phValue;
            check_ph(current_ph);
        }
};

PHSensor carbon_sensor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  relay = Relay(RELAY_PIN);
  carbon_sensor = PHSensor(SENSOR_PIN, OFFSET);
  relay.toggle();
}


void loop() {
  carbon_sensor.read();
}
