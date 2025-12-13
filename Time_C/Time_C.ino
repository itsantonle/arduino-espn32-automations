// #define POTENTIONMETER_PIN A2
// #define BTN_PIN 9
#define RED_LED_PIN 12
int BLINKSPEED = 800;
// #define GREEN_LED_PIN 11
// #define YELLOW_LED_PIN 10
// #define LED_PIN_ARRAY_SIZE 3
unsigned long previousActionTime = millis();
unsigned long timeInterruptInterval = 3000;

void setup() {

  pinMode(RED_LED_PIN,OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
  Serial.begin(115200);
  // time the program started in milis - unsigned start only at positive 
  
}

unsigned long getActionDuration(unsigned long start, unsigned long end){
  return end-start;
}

void blink(int value){
  digitalWrite(RED_LED_PIN, HIGH);
  delay(value);
   digitalWrite(RED_LED_PIN, LOW);
}

void loop() {
unsigned long timeNow = millis();
if (timeNow - previousActionTime > timeInterruptInterval){
  Serial.println("Hello");
  Serial.println(millis());
  previousActionTime += timeInterruptInterval ;
}
// blink(BLINKSPEED);

//   if(Serial.availableForWrite() > 0){
//       int pause = Serial.parseInt();
//       if (pause >= 100){
//          BLINKSPEED = pause;
//       }
      
//     }
  
}
