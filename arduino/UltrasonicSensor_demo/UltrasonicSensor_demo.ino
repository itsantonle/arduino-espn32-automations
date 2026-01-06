
#define ECHO_PIN 3
#define TRIGGER_PIN 4



unsigned long timeBegin = micros();  
unsigned long lastTimeUltrasonicTrigger = millis();
unsigned long triggerDebounceInterval = 100; 


void triggerUltrasonicSensor(){
  // send a pulse by triggering HIGH for a duaration LOW HIGH LOW with high must be at least 10microsec
  digitalWrite(TRIGGER_PIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW); 
}

double getUltrasonicDistance(){
  // get using the pulse in (PIN, MODE (High if high in 10micros))
  // distance = duration(t) * speed (of air = 340m/s) t * d/t = d 
  unsigned long timeNowMicro = micros();
  double durationMicros = pulseIn(ECHO_PIN, HIGH);  
  unsigned long startPulsetime = timeBegin - timeNowMicro; 
  Serial.println("Duration"); 
  Serial.print(startPulsetime);
  double distanceCenti = durationMicros / 58.0;  // if inch, d/148.0
  return distanceCenti; 

}

void setup() {
// echo pin is to read frompin
pinMode(ECHO_PIN, INPUT); 
// trigger pin as an output - to trigger stufff
pinMode(TRIGGER_PIN, OUTPUT); 

Serial.begin(115200);
}


void loop() {
  // do action 
  // trigger every 100 milisecond 
  unsigned long timeNow = millis(); 
  if (timeNow - lastTimeUltrasonicTrigger > triggerDebounceInterval ){
    lastTimeUltrasonicTrigger += triggerDebounceInterval; 
    //trigger sensor 
    triggerUltrasonicSensor();
    // read pulse on echo pin
    Serial.println(getUltrasonicDistance());
  }
  


}