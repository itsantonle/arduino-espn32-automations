#define POTENTIONMETER_PIN A2
#define BTN_PIN 9
#define RED_LED_PIN 12
#define GREEN_LED_PIN 11
#define YELLOW_LED_PIN 10

int LED_BLINK_STATE = 1;


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
  if (digitalRead(BTN_PIN) == LOW) {
    if (LED_BLINK_STATE == 1){
      digitalWrite(RED_LED_PIN, HIGH);
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);
      LED_BLINK_STATE = 2;

    } else{
      digitalWrite(RED_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(YELLOW_LED_PIN, LOW);
      LED_BLINK_STATE = 1;
    }

      delay(300);
  }
}
