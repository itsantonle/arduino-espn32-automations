#define POTENTIONMETER_PIN A2
#define BTN_PIN 9
#define RED_LED_PIN 12
#define GREEN_LED_PIN 11
#define YELLOW_LED_PIN 10
#define LED_PIN_ARRAY_SIZE 3
//byte 0-255 number
// when clicking on a button check between two states
// byte LED_PINS[LED_PIN_ARRAY_SIZE] = {RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN};
// to remedy the solution of hardware, ignore changes during a state change for a select tiem

unsigned long lastTimeBtnChanged = millis();
unsigned long debounceDelay = 50;

byte btnState = LOW;
void setup() {
 Serial.begin(115200);
 pinMode(BTN_PIN, INPUT);
  
}


void loop() {
  unsigned long timeNow = millis();
  // trying to verify only after debounce TECHNIQUE
  if (timeNow - lastTimeBtnChanged > debounceDelay){

     byte newBtnState= digitalRead(BTN_PIN);
     if(newBtnState != btnState){
        lastTimeBtnChanged = timeNow;
        btnState = newBtnState; 
        // action 
        if(btnState == HIGH){
      Serial.println("Button Pressed");
    }
        else {
       Serial.println("Button Released");
    }
     }
  }



}
