#define LED_PIN 11
#define BTN_PIN 2
#define DELAY_RATE 150
void setup() {
  Serial.begin(9600);
pinMode(LED_PIN, OUTPUT);
pinMode(BTN_PIN, INPUT);
}

void loop() {
  if(digitalRead(BTN_PIN) == HIGH){
    Serial.println("BUTTON PRESSED");
    digitalWrite(LED_PIN, HIGH);
    delay(100);
  } else{
    digitalWrite(LED_PIN, LOW);
  }
 

  delay(100);

  

}
