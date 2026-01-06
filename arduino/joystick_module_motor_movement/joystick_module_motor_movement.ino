#include <Servo.h>

#define SERVO_PIN 9
#define VRy A1   // Joystick Y-axis connected to A1

Servo servo_9;

void setup() {
  servo_9.attach(SERVO_PIN, 500, 2500); // pin, min pulse, max pulse
}

void loop() {
  int yValue = analogRead(VRy);             
  int angle = map(yValue, 0, 1023, 0, 180); 

  servo_9.write(angle);                     
  delay(15);                                
}
