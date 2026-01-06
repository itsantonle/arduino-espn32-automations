#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

// Pin definitions
#define LED_GREEN 5
#define LED_RED   17

// WiFi credentials
const char* ssid     = "";
const char* password = "";

// LED array for setup convenience
byte boardLEDS[] = {LED_GREEN, LED_RED};

// Initialize server on port 80
WebServer server(80);

// ---------------- Controllers ----------------

void handleRoute() {
  // Main UI with toggle links
  String html = "<html><body>"
                "<h2>ESP32 LED Toggle UI</h2>"
                "<p><a href='/toggle?ledColor=red&ledState=on'>Red ON</a></p>"
                "<p><a href='/toggle?ledColor=red&ledState=off'>Red OFF</a></p>"
                "<p><a href='/toggle?ledColor=green&ledState=on'>Green ON</a></p>"
                "<p><a href='/toggle?ledColor=green&ledState=off'>Green OFF</a></p>"
                "</body></html>";

  server.send(200, "text/html", html);
}

void handleToggle() {
  String ledColor = server.arg("ledColor");
  String ledState = server.arg("ledState");
  String status   = "";

  //only allow "red"/"green" and "on"/"off"
  if (ledColor.equals("red") || ledColor.equals("green")) {
    if (ledState.equals("on") || ledState.equals("off")) {
      int pin = (ledColor.equals("red")) ? LED_RED : LED_GREEN;
      int value = (ledState.equals("on")) ? HIGH : LOW;

      digitalWrite(pin, value);
      status = ledColor + " LED " + ledState;
    } else {
      status = "Invalid ledState (use 'on' or 'off')";
      Serial.println(status);
    }
  } else {
    status = "Invalid ledColor (use 'red' or 'green')";
    Serial.println(status);
  }

  server.send(200, "text/plain", status);
}

// ---------------- Routers ----------------

void setupRoutes() {
  server.on("/", handleRoute);
  server.on("/toggle", handleToggle);
}

// ---------------- Helpers ----------------

void setupLEDs() {
  for (byte i = 0; i < sizeof(boardLEDS) / sizeof(boardLEDS[0]); i++) {
    pinMode(boardLEDS[i], OUTPUT);
    digitalWrite(boardLEDS[i], LOW); // ensure LEDs start OFF
  }
}

// ---------------- Setup ----------------

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("antonesp")) {
    Serial.println("MDNS responder started: http://antonesp.local");
  }

  setupLEDs();
  setupRoutes();
  server.begin();
  Serial.println("HTTP server started");
}

// ---------------- Loop ----------------

void loop() {
  server.handleClient();
  delay(2);
}
