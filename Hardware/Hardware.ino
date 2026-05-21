#include <WiFi.h>
#include <WebServer.h>

// Replace with your WiFi credentials
const char* ssid = "*********";
const char* password = "123456789";

WebServer server(80);

// Pins
#define PUMP_PIN 4
#define LED_PIN 2
#define BUZZER_PIN 14
#define RAIN_PIN 18

// -------------------- HANDLERS --------------------

// Pump
void handlePumpOn() {
  digitalWrite(PUMP_PIN, LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "Pump ON");
}

void handlePumpOff() {
  digitalWrite(PUMP_PIN, HIGH);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "Pump OFF");
}

// LED
void handleLedOn() {
  digitalWrite(LED_PIN, HIGH);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "LED ON");
}

void handleLedOff() {
  digitalWrite(LED_PIN, LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "LED OFF");
}

// Buzzer
void handleBuzzerOn() {
  digitalWrite(BUZZER_PIN, HIGH);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "Buzzer ON");
}

void handleBuzzerOff() {
  digitalWrite(BUZZER_PIN, LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "Buzzer OFF");
}

// Rain Sensor
void handleRain() {
  int rainValue = digitalRead(RAIN_PIN);

  server.sendHeader("Access-Control-Allow-Origin", "*");

  if (rainValue == LOW) {
    server.send(200, "text/plain", "RAIN=1");  // Rain
  } else {
    server.send(200, "text/plain", "RAIN=0");  // No rain
  }
}

// Test
void handleTest() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", "ESP32 Server Working");
}

// -------------------- SETUP --------------------

void setup() {
  Serial.begin(115200);

  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RAIN_PIN, INPUT);

  // Default states
  digitalWrite(PUMP_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);

  // WiFi connect
  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Routes
  server.on("/test", handleTest);

  server.on("/pump/on", handlePumpOn);
  server.on("/pump/off", handlePumpOff);

  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);

  server.on("/buzzer/on", handleBuzzerOn);
  server.on("/buzzer/off", handleBuzzerOff);

  server.on("/rain", handleRain);

  server.begin();
  Serial.println("Server started");
}

// -------------------- LOOP --------------------

void loop() {
  server.handleClient();
}