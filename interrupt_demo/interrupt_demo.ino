#define LED_PIN 7
#define BTN_PIN 2 
byte LED_STATE = LOW;
volatile bool btnReleased = false;
unsigned long lastTimePressed = millis(); 
unsigned long debounceDelay = 50; 
int counter = 0; 

void toggleLED(){
  if (LED_STATE == LOW){
  	LED_STATE = HIGH; 
  } else {
  	LED_STATE = LOW; 
  }
  digitalWrite(LED_PIN, LED_STATE); 
}

void buttonReleasedInterrupt(){
  // add the debounce here 
  	unsigned long timeNow = millis();
  if (timeNow - lastTimePressed > debounceDelay) {
    btnReleased = true; 
    counter += 1; 
    Serial.println(counter); 
  }
	
}
void setup()
{ Serial.begin(9600); 
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT); 
 
  attachInterrupt(digitalPinToInterrupt(BTN_PIN),buttonReleasedInterrupt, FALLING);

}

void loop()
{
 
  if(btnReleased){
    btnReleased = false; 
    toggleLED(); 
    
  }
  
}