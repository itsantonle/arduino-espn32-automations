#include <WiFi.h>
#include <ESPmDNS.h> 
//UDP allow OTA(over the air) happenings
#include <WiFiUDP.h> 
// allow arduino IDE to connect to ESP OTA (no USB) 
// if over the internet compile to binary and host it on a server
// alwyas include OTA code otherwise connection is severed
#include <ArduinoOTA.h>
#include <WiFiManager.h>

const char *ssid = "esp32AP";
const char *password = "password";

void setup() {
  // put your setup code here, to run once:
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
  ArduinoOTA.setPassword("admin");
  ArduinoOTA.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  ArduinoOTA.handle();

}
