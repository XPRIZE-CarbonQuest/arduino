#define OFFSET -2

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

        }
};

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
