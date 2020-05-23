/*
  Read Light Levels
  Read light level, report to PC
 
  This example code is in the public domain.
 */
 
int ledPin = 11; // port LED connected to
int lightLevel;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as an output.
  pinMode(ledPin, OUTPUT);
  
  // initialize serial comms
  Serial.begin(38400);
} // end setup

// the loop routine runs over and over again forever:
void loop() {
  lightLevel = analogRead(A0);
  Serial.print("Light level: ");
  Serial.println(lightLevel, DEC);
  digitalWrite(ledPin, HIGH);
  delay(lightLevel);
  digitalWrite(ledPin, LOW);
  delay(lightLevel);
  
} // end loop
