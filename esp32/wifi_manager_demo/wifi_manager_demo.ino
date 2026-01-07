#include <WiFiManager.h>

const char *ssid = "esp32AP";
const char *password = "password";

void setup() {
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  WiFiManager wm;
  bool response; 
  response = wm.autoConnect(ssid, password);
  if(!response){
    Serial.println("Not Connected")
  }else{
    Serial.println("Connect to wifi")
  }


}

void loop() {
  // put your main code here, to run repeatedly:

}
