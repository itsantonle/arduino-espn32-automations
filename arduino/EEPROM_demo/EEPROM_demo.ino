#include <EEPROM.h>
#define LED_PIN 10
#define POTEN_PIN A0
int MADDRESS = 1;

// EEPROM only has 1000 write cycles per memory address which is 0-1023 for UNO and more for MEGA, some bards don't have EEPROM
// avaoid using loops with writes. MEMORY can store 1 byte 
void setup()
{
  byte defValue = EEPROM.read(MADDRESS);
  Serial.begin(115200); 
  pinMode(LED_PIN, OUTPUT); 
  analogWrite(LED_PIN, defValue); 
  Serial.println(defValue);
}

void loop()
{
  // check for availability 
  if(Serial.available() > 0){
    int nMaxB = Serial.parseInt(); 
    EEPROM.write(MADDRESS, nMaxB); 
    // analogWrite(LED_PIN, EEPROM.read(MADDRESS));
  }
//  byte pValue = analogRead(POTEN_PIN);

}