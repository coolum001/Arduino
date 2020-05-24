// Libraries

#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>
#include <DHT.h>

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

// pin used to blink activity LED
int led = 8;

// Constants for Temp / Hum sensor

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE); // create sensor object

int chk;
float hum;  // humidty sensor value
float tmp;  // temperature sensor value

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

    dht.begin(); // initialize sensor

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

// count not yet used
int count = 0;

// character buffers for formatted sensor readings
static char outstrTemp[7] = "      ";
static char outstrHumd[6] = "     ";

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
  lcd.print("Temp &  Humidity");

  lcd.setCursor(0, 1);

  // read sensor
  hum = dht.readHumidity();
  tmp = dht.readTemperature();

  // format readings (temp can be -ve, humidity always positive (?)
  // sign +3 digit temp + . + digit = 6 characters 
  dtostrf(tmp, 6, 1, outstrTemp);
   // 3 digit humidity + . + digit = 5 chars
  dtostrf(hum, 5, 1, outstrHumd);

  // write to lcd display, line 1 (of 0, 1. so bottom line)
  lcd.print(outstrTemp);
  lcd.print("C ");
  lcd.print(outstrHumd);
  lcd.print("%");
  
  delay(500);

  digitalWrite(led, LOW);
  delay(500);
  
} // loop()
