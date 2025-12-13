// #define POTENTIONMETER_PIN A2
// #define BTN_PIN 9
#define RED_LED_PIN 12
int BLINKSPEED = 800;
// #define GREEN_LED_PIN 11
// #define YELLOW_LED_PIN 10
// #define LED_PIN_ARRAY_SIZE 3


void setup() {

  pinMode(RED_LED_PIN,OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
  Serial.begin(9600);

  Serial.setTimeout(100);
  delay(100);
 
}

void blink(int value){
  digitalWrite(RED_LED_PIN, HIGH);
  delay(value);
   digitalWrite(RED_LED_PIN, LOW);
}

void loop() {
blink(BLINKSPEED);

  if(Serial.availableForWrite() > 0){
      int pause = Serial.parseInt();
      if (pause >= 100){
         BLINKSPEED = pause;
      }
      
    }
  
}
