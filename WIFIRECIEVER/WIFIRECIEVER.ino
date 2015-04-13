#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>

#include <SPI.h>
#define CE_PIN   9
#define CSN_PIN 10
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
long test[2];  // 2 element array holding Joystick readings

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    while (!done)
    {
      // Fetch the data payload
      done = radio.read( test, sizeof(test) );
      Serial.print("X = ");
      Serial.print(test[0]);
      Serial.print(" Y = ");      
      Serial.println(test[1]);
    }
  }
  else
  {    
      Serial.println("No radio available");
  }

}
