#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

const int soilMoisturePin = A0;
const int pumpPin = D1;
const int moistureThreshold = 300;

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);
  
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  server.on("/", handleRoot);
  server.on("/togglePump", handleTogglePump);
  server.begin();
}

void loop() {
  server.handleClient();
  
  int soilMoistureValue = analogRead(soilMoisturePin);
  
  if (soilMoistureValue < moistureThreshold) {
    digitalWrite(pumpPin, HIGH);
  } else {
    digitalWrite(pumpPin, LOW);
  }
  
  delay(1000);
}

void handleRoot() {
  int soilMoistureValue = analogRead(soilMoisturePin);
  String html = "<html><body><h1>Smart Irrigation System</h1>";
  html += "<p>Soil Moisture: " + String(soilMoistureValue) + "</p>";
  html += "<a href='/togglePump'>Toggle Pump</a>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleTogglePump() {
  static bool pumpState = false;
  pumpState = !pumpState;
  digitalWrite(pumpPin, pumpState ? HIGH : LOW);
  server.send(200, "text/html", "Pump toggled. <a href='/'>Go back</a>");
}
