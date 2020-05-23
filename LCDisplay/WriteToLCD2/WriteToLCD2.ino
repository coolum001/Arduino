/*
  Display test on LCD Display
  
  This example code is in the public domain.
 */
 
 #include <LiquidCrystal.h>
 
 LiquidCrystal lcd(12,11,5,4,3,2);
 
 int updateDelay = 1000;
 
 // 12 -> D/I Select
 // 11 -> Signal Enable
 
 // 5,3,4,2 -> Data Bus Line
 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as an output.
  lcd.begin(16, 2);
  lcd.print("Hello World");
  
} // end setup

// the loop routine runs over and over again forever:
void loop() {
  for (int i=1; i< 1000; i=i+1){
    lcd.setCursor(0,1);
    lcd.print(i, DEC);
    delay(updateDelay);
  } // end for
} // end loop
