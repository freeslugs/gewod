int incomingByte = 0;   // for incoming serial data
int pin_0 = 2;
int pin_1 = 3;
int pin_2 = 4;
int pin_3 = 5;
int pin_4 = 6;
int pin_5 = 7;
int pin_6 = 8;
int pin_7 = 9;

int[] pinArray = [2, 3, 4, 5, 6, 7, 8, 9];

void setup() {
        Serial.begin(9600);
        pinMode(pin_0, OUTPUT);
        pinMode(pin_1, OUTPUT);
        pinMode(pin_2, OUTPUT);
        pinMode(pin_3, OUTPUT);
        pinMode(pin_4, OUTPUT);
        pinMode(pin_5, OUTPUT);
        pinMode(pin_6, OUTPUT);
	pinMode(pin_7, OUTPUT);
        
        pinMode(pin_0, LOW);
        pinMode(pin_1, LOW);
        pinMode(pin_2, LOW);
        pinMode(pin_3, LOW);
        pinMode(pin_4, LOW);
        pinMode(pin_5, LOW);
        pinMode(pin_6, LOW);
	pinMode(pin_7, LOW);
}

void loop() {

        // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
                
                for (int i = 0; i < 9; ++i){
                        pinMode(pinArray[i], LOW);
                }

                if (incomingByte == '0') {
                        digitalWrite(pin_0, HIGH);
                } else if (incomingByte == '1') {
                        digitalWrite(pin_1, HIGH);
                } else if (incomingByte == '2') {
                        digitalWrite(pin_2, HIGH);
                } else if (incomingByte == '3') {
                        digitalWrite(pin_3, HIGH);
                } else if (incomingByte == '4') {
                        digitalWrite(pin_4, HIGH);
                } else if (incomingByte == '5') {
                        digitalWrite(pin_5, HIGH);
                } else if (incomingByte == '6') {
                        digitalWrite(pin_6, HIGH);
                } else if (incomingByte == '7') {
                        digitalWrite(pin_7, HIGH);
                }                
        }
}
