#include <IRremote.h>
#define IR_RECIEVER_PIN 5
#define PHOTORESISTOR_PIN A0

IRrecv irrecv(IR_RECIEVER_PIN); 
// this is an older struct
decode_results results; 

void setup() {
  Serial.begin(115200);
  // enable input from IR
  irrecv.enableIRIn();

}

void loop() {
  // & get me the memory addres  *- got to the memory address and get the value
  // & create pointer, *dereference pointer 
  // put your main code here, to run repeatedly:
  if(irrecv.decode_old(&results)){
    irrecv.resume();
    Serial.println(results.value, HEX); 

  }

}
