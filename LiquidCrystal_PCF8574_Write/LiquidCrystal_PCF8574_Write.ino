#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

// pin used to blink activity LED
int led = 8;

void setup()
{
  // used for activity signal
  pinMode(led, OUTPUT);

  // Defer writing to Serial Line in this version of program
//  int error;
//
//  Serial.begin(115200);
//  Serial.println("LCD...");
//
//  // wait on Serial to be available on Leonardo
//  while (!Serial)
//    ;
//
//  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner how to test for a I2C device.

  int error;  // holds I2C response
  
  Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();

  if (error == 0) {
    // LCD Found
    lcd.begin(16, 2); // initialize the lcd

  } else {
    //Serial.println(": LCD not found.");
    // rapidly flash LED to show error
    while( true){
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
    };//end while
  
  } // if

} // setup()

int count = 0;
void loop()
{ 
  count = count+1;
  // set activity LED high
  digitalWrite(led, HIGH);

  // make backlight bright
  lcd.setBacklight(255);
  lcd.home();
  // display line 1
  lcd.clear();
  lcd.print("Temp & Humidty");

  lcd.setCursor(0, 1);
  lcd.print(count);
  delay(500);

  digitalWrite(led, LOW);
  delay(500);
  
} // loop()
