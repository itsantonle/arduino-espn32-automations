#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ECHO_PIN 3
#define TRIGGER_PIN 4
#define SDA_PIN A4
#define SCL_PIN A5

#define RED_LED_PIN 12
#define GREEN_LED_PIN 11



unsigned long timeBegin = micros();  
unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long triggerDebounceInterval = 100; 
unsigned long lastledBlink = millis(); 
unsigned long ledBlinkInterval = 500; 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void blinkLED(int pin){ 
  unsigned long timeNow = millis(); 
  if (timeNow - lastledBlink > ledBlinkInterval){
    lastledBlink += ledBlinkInterval;
    if (digitalRead(pin) == LOW){
      digitalWrite(pin, HIGH); 
    } else {
      digitalWrite(pin, LOW);  
    }
  }

}
void triggerUltrasonicSensor(){
  digitalWrite(TRIGGER_PIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW); 
}

double getUltrasonicDistance(){
  unsigned long timeNowMicro = micros();
  double durationMicros = pulseIn(ECHO_PIN, HIGH);  
  unsigned long startPulsetime = timeBegin - timeNowMicro; 
  double distanceCenti = durationMicros / 58.0;  // if inch, d/148.0
  return distanceCenti; 

}

void setupPins(){
  
pinMode(ECHO_PIN, INPUT); 
pinMode(RED_LED_PIN , OUTPUT); 
pinMode(GREEN_LED_PIN , OUTPUT); 
digitalWrite(RED_LED_PIN, LOW);
digitalWrite(GREEN_LED_PIN, LOW);
pinMode(TRIGGER_PIN, OUTPUT); 
digitalWrite(GREEN_LED_PIN, HIGH);
delay(1000);
digitalWrite(GREEN_LED_PIN, LOW);

}
void setupLCD(){
  lcd.init();          
  lcd.backlight();     
  lcd.setCursor(0, 0); // column 0, row 0
  lcd.print("Distance: ");
  lcd.setCursor(0, 1); // column 0, row 1
  lcd.print("0");
  lcd.print(" cm"); 

}

void setup() {
  setupPins();
  setupLCD(); 
  delay(1000);
  Serial.begin(115200);
  
 
}

void setDistancetoLCD(double distance){
  lcd.setCursor(0, 1);         
  lcd.print("                "); // Clear full line (16 spaces)
  lcd.setCursor(0, 1);
  lcd.print(String(distance, 2)); // Format to 2 decimal places
  lcd.print(" cm");
}



void loop() {
  unsigned long timeNow = millis(); 
  blinkLED(GREEN_LED_PIN); 
  if (timeNow - lastTimeUltrasonicTrigger > triggerDebounceInterval ){
    lastTimeUltrasonicTrigger += triggerDebounceInterval; 
    //trigger sensor 
    triggerUltrasonicSensor();
    // read pulse on echo pin
    setDistancetoLCD(getUltrasonicDistance());
    // Serial.println("\nDistance: ");
    // Serial.print(getUltrasonicDistance());
  }
}
