/*
  BlinkFourLeds
  Turns on an LED on , then the next , repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledCount = 8;
int period = 50;

int LEDPins[] = {10, 11, 12, 13};

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as an output.
  for (int i = 10; i<14; i=i+1){
    
    pinMode(i, OUTPUT);
  }; // end for    
}

// the loop routine runs over and over again forever:
void loop() {
  for( int i = 10; i< 14; i=i+1){
    digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(period);               // wait 
    digitalWrite(i, LOW);
  };//end for

}
