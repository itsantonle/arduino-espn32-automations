#define POTENTIONMETER_PIN A2
#define BTN_PIN 9
#define RED_LED_PIN 12
#define GREEN_LED_PIN 11
#define YELLOW_LED_PIN 10



void setup() { 
pinMode(RED_LED_PIN, OUTPUT);
pinMode(GREEN_LED_PIN, OUTPUT);
pinMode(YELLOW_LED_PIN, OUTPUT);

Serial.begin(9600);
digitalWrite(RED_LED_PIN, LOW);
digitalWrite(GREEN_LED_PIN, LOW);
digitalWrite(YELLOW_LED_PIN, LOW);
}

void loop() {
 if (digitalRead(BTN_PIN) == HIGH){
  Serial.println("Pressed");
 } else{
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, HIGH);
  delay(300);
   digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(YELLOW_LED_PIN, LOW);
   delay(300);
 }

}
