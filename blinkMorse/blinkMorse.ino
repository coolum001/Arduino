/*
   Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 This example code is in the public domain.
 */

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);    
  int serialBaud = 9600; 
  Serial.begin(serialBaud);
}

// the loop routine runs over and over again forever:
void loop() {
  int dotPeriod  =  500; 
  int dashPeriod = 2000;
  int offPeriod  =  200;
  int eowPeriod  = 3000;
  // send sos in morse code
  for (int i=0;i<3;i=i+1){ 
    digitalWrite(led, HIGH);   // turn the LED on 
    delay(dotPeriod);          // wait for a period 
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(offPeriod);          // wait 
  };//end for
  for (int i=0;i<3;i=i+1){ 
    digitalWrite(led, HIGH);   // turn the LED on 
    delay(dashPeriod);         // wait for a period 
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(offPeriod);          // wait 
  };//end for   
  for (int i=0;i<3;i=i+1){ 
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(dotPeriod);          // wait for a period 
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(offPeriod);          // wait 
  };//end for
  delay(eowPeriod); 
  Serial.println(" SOS sent");
};//end loop

