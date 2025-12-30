#define ECHO_PIN 3
#define TRIGGER_PIN 4

unsigned long lastTimeUltrasonicTriggered = millis();
unsigned long ultrasonicDelay = 100; 
volatile unsigned long pulseInTimeBegin; 
volatile unsigned long pulseInTimeEnd; 
volatile bool newDistanceAvailable; 
double previousDistance = 400; 

// Applying filters to distance to reduce wrong data (depends on hardware )


void triggerUltrasonicSensor(){
  // send pulse to trigger sensor
  digitalWrite(TRIGGER_PIN, LOW); 
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW); 

}

double getUltrasonicDistance(){
   double durationMicros = pulseInTimeEnd - pulseInTimeBegin; 
   double distanceCenti = durationMicros/58.0; 
   // add the filters
   if (distanceCenti > 400){
    return previousDistance;
   }
   previousDistance = distanceCenti; 
   return distanceCenti;
}

// in interrupts you need to know if signal is falling or rising
// for change you don't so you check
void ultrasonicSensorInterrupt(){
  // just for flags
  // rising
  // start measuring 
  if(digitalRead(ECHO_PIN) == HIGH){
    pulseInTimeBegin = micros();}
    else{
  //falling
  // stop measuring 
  pulseInTimeEnd = micros(); 
  newDistanceAvailable = true; 

}

  }

void setup() {
 Serial.begin(15200);
 pinMode(ECHO_PIN, INPUT); 
 pinMode(TRIGGER_PIN, OUTPUT); 
 attachInterrupt(digitalPinToInterrupt(ECHO_PIN), ultrasonicSensorInterrupt, CHANGE);

}

void loop() {
  // apply debounce
  unsigned long timeNow = millis();
  if (timeNow - lastTimeUltrasonicTriggered > ultrasonicDelay ){
    // trigger sensor
    triggerUltrasonicSensor();
    // check flag
    if(newDistanceAvailable){
      newDistanceAvailable = false; 
      double distance = getUltrasonicDistance(); 
      Serial.println(distance);
    }
  }

}
