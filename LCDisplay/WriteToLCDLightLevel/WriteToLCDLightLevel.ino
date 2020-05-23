/*
  Display Light Levels on LCD Display
  
  This example code is in the public domain.
 */
 
 #include <LiquidCrystal.h>
 
 LiquidCrystal lcd(12,11,5,4,3,2);
 
 // 12 -> D/I Select
 // 11 -> Signal Enable
 
 // 5,3,4,2 -> Data Bus Line

 int updateDelay = 1000;  // update display every second
 
 int lightLevel;  // hold light level read from sensor
 int blinkLed = 8; // Pin used to blink LED when light level read
 int blinkDelay = 100; // period of time Blinking LED is on after light level read
 
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as an output.
  lcd.begin(16, 2);
  lcd.print("Light Sensor");
  
} // end setup

// the loop routine runs over and over again forever:
void loop() {
  for (int i=1; i< 1000; i=i+1){
    
    // read light level
    lightLevel = analogRead(A0);
    // write to line two of LCD display
    lcd.begin(16, 2);
    lcd.print("Light Sensor");
    
    lcd.setCursor(0,1);
    lcd.print(lightLevel, DEC);
    
    // blink LED
    digitalWrite(blinkLed, HIGH);
    delay(blinkDelay);
    digitalWrite(blinkLed, LOW);
    // wait to update display again
    delay(updateDelay-blinkDelay);
  } // end for
} // end loop
