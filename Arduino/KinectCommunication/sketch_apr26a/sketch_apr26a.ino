#include <servo.h>
int incomingByte = 0;   // for incoming serial data
Servo stand;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stand.attach(4);
}

void rotateServo(int val){
	//servo rotates from 0 to 180
	double percent = val / 10.0;
	double degrees = percent * 180;
	stand.write(degrees);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
          // read the incoming byte:
          incomingByte = Serial.read();

          // say what you got:
          Serial.print("I received: ");
          Serial.println(incomingByte, DEC);

          int val = incomingByte - '0'
          rotateServo(val);
    }
}
