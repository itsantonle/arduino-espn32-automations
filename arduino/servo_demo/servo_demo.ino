#include <Servo.h>
#define SERVO_PIN 9
int pos = 0;

Servo servo_9;

void setup()
{
  // pin, min pulse width, max pulse width 
  
  servo_9.attach(SERVO_PIN, 500, 2500);
}

void loop()
{
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 180; pos += 5) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(30); // Wait for 15 millisecond(s)
  }
  for (pos = 180; pos >= 0; pos -= 5) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    // wait 15 ms for servo to reach the position
    delay(30); // Wait for 15 millisecond(s)
  }
}