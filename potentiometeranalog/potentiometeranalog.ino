#define POTENTIONMETER_PIN A2
#define LED_PIN 11

void setup() {
pinMode(LED_PIN, OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // analog btn 0 to 255 
  // 0 to 1200
 Serial.println(analogRead(POTENTIONMETER_PIN));

 analogWrite(LED_PIN, analogRead(POTENTIONMETER_PIN) / 4);
 delay(100);
}
