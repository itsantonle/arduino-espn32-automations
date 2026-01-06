#include <IRremote.h>
#define IR_RECEIVER_PIN 5 
//map buttons
#define IR_BTN_0 22
#define IR_BTN_1 12
#define IR_BTN_2 24
#define IR_BTN_PLAY 64

void setup() {
  Serial.being(115200);
  IrReciever.begin(IR_RECEIVER_PIN);

}

void loop() {
    if (IrReceiver.decode()) {
    // Print raw decoded data
//     Serial.print("Protocol: ");
//     Serial.println(IrReceiver.decodedIRData.protocol);
//     Serial.print("Command: ");
//     Serial.println(IrReceiver.decodedIRData.command);
//     Serial.print("Address: ");
//     Serial.println(IrReceiver.decodedIRData.address);

// Serial.println(IrReceiver.decodedIRData.decodedRawData,HEX);
int command = IrReceiver.decodedIRData.command;

switch(command){
  case IR_BTN_0: {
    Serial.println("Button 0 was pressed"); 
    break; 
  }
  case IR_BTN_1: {
   Serial.println("Button 1 was pressed"); 
    break;
  }
  case IR_BTN_2: {
   Serial.println("Button 2 was pressed"); 
    break;
  }
  default: {
    Serial.println("Press another button")
  }
}
// Resume listening for next signal
    IrReceiver.resume();
  }
}
