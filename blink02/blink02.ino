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
}

// the loop routine runs over and over again forever:
void loop() {
   int onPeriod = 2000; 
   for(int i = 1; i<9; i=i+1){
     digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
     delay(onPeriod);               // wait for a period (getting shorter each time)
     digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
     delay(onPeriod/2);        // wait for a half on period
     onPeriod = onPeriod/2;
   };//end for
};//end loop
