/* 1 - GND
   2 - VCC 3.3V !!! NOT 5V
   3 - CE to Arduino pin 9
   4 - CSN to Arduino pin 10
   5 - SCK to Arduino pin 13
   6 - MOSI to Arduino pin 11
   7 - MISO to Arduino pin 12
   8 - UNUSED
*/
#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>

#include <SPI.h>

#define CE_PIN   9
#define CSN_PIN 10
const int TRIG_PIN = 4;
const int ECHO_PIN = 7;
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
long test[2];
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
}

void loop() {
   digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN,HIGH);
  long distancecm = duration / 29.1 / 2 ;
  // put your main code here, to run repeatedly:
  test[0]=0;
  test[1]=distancecm;
  radio.write( test, sizeof(test));
}
