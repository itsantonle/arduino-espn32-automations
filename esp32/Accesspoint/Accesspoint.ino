#include <WiFi.h>
#include <WiFiClient.h> 
// use the esp32 as an access point if no router 
#include <WiFiAP.h> 


const char *ssid = "esp32AP"
const char *password = "password"

WiFiServer server(80); 

void setUpConfig(){
 Serial.println();
  // password is optional for access pionts
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("IP ADDRESS:");
  Serial.println(myIP);
  server.begin();
}
void setup(){
  Serial.begin(115200);
  setUpConfig();
 
}

void loop(){
  //handle clients that connect to the AP

  WiFiClient client = server.available();
  if(client){
    Serial.println("Connected to AP");
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/plain");
    client.println();
    client.print("Hello World");
    client.println();
    client.stop();
    Serial.println("Disconnected from AP");
  }
}