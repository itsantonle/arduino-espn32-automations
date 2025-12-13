// #define POTENTIONMETER_PIN A2
#define BTN_PIN 9
#define RED_LED_PIN 12
int RED_BLINKSPEED = 800;
#define GREEN_LED_PIN 11
int GREEN_BLINKSPEED = 1000;
#define YELLOW_LED_PIN 10
#define LED_PIN_ARRAY_SIZE 3
unsigned long previousRedBlinkInterval = millis();
unsigned long previousGreenBlinkInterval = millis();

byte LED_PINS[LED_PIN_ARRAY_SIZE] = {RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN};

void setup() {
  setupLEDS();
  Serial.begin(115200);
 
  
}

void setupLEDS(){
  pinMode(BTN_PIN, INPUT);
  for(int i=0; i < LED_PIN_ARRAY_SIZE; i++){
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }

}
void blinkRed(unsigned long timeNow){
  if (timeNow - previousRedBlinkInterval > RED_BLINKSPEED){
    if(digitalRead(RED_LED_PIN) == LOW){
      digitalWrite(RED_LED_PIN, HIGH);
    } else {
      digitalWrite(RED_LED_PIN, LOW);
    }

  previousRedBlinkInterval += RED_BLINKSPEED;
  }

}

void blinkGreen(unsigned long timeNow){
  if (timeNow - previousGreenBlinkInterval > GREEN_BLINKSPEED){
    if(digitalRead(GREEN_LED_PIN) == LOW){
      digitalWrite(GREEN_LED_PIN, HIGH);
    } else {
      digitalWrite(GREEN_LED_PIN, LOW);
    }
  previousGreenBlinkInterval += GREEN_BLINKSPEED;
  }

}
void checkButtonInput(){
  if(digitalRead(BTN_PIN) == HIGH){
    digitalWrite(YELLOW_LED_PIN, HIGH);
  }else{
   digitalWrite(YELLOW_LED_PIN, LOW); 
  }
}

void loop() {
unsigned long timeNow = millis();
blinkRed(timeNow);
blinkGreen(timeNow);
checkButtonInput();


}
