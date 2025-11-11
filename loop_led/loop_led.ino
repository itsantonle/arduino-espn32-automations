#define POTENTIONMETER_PIN A2
#define BTN_PIN 9
#define RED_LED_PIN 12
#define GREEN_LED_PIN 11
#define YELLOW_LED_PIN 10
#define LED_PIN_ARRAY_SIZE 3

int LEDBlinkState = 1;
// type of pins is actually a byte
byte LEDPinArray[LED_PIN_ARRAY_SIZE] = 
  {RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN}; 

void setLEDPinMode(){
  for (int i = 0 ; i < LED_PIN_ARRAY_SIZE; i++){
    pinMode(LEDPinArray[i], OUTPUT);
  }
}

void turnOffAllLEDS(){
  for (int i = 0; i < LED_PIN_ARRAY_SIZE; i++){
    digitalWrite(LEDPinArray[i], LOW);
  }
}

void toggleLEDS(){

  if (LEDBlinkState == 1){
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);
      LEDBlinkState = 2;

    } else{
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(YELLOW_LED_PIN, LOW);
      LEDBlinkState = 1;
    }

      


}
void setup() {
  setLEDPinMode();
  turnOffAllLEDS();
  Serial.begin(9600);
 
}

void loop() {
  if (digitalRead(BTN_PIN) == LOW) {
    toggleLEDS();
    delay(300);
  }
}
