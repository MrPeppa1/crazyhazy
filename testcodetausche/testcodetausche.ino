#include "ESP8266WiFi.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 12

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

char ssid[] = "TWC-Intern";                     // your network SSID (name)
char key[] = "fegeindeerstdifoaulege";       // your network key
//int status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(115200);
  Serial.println("TemperaturSteuerung");
  sensors.begin();
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(ssid, key);
  delay(5000);

  Serial.println("Setup done");
}

void loop() {

  sensors.requestTemperatures(); // Send the command to get temperatures

  Serial.print("D1= ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("D2= ");
  Serial.print(sensors.getTempCByIndex(1));
  Serial.print("D3= ");
  Serial.print(sensors.getTempCByIndex(2));
  Serial.print("D4= ");
  Serial.print(sensors.getTempCByIndex(3));
  Serial.println("|");
  delay(1000);

  // WiFi.scanNetworks will return the number of networks found
  //int n = WiFi.scanNetworks();
  IPAddress ip = WiFi.localIP();
  // Wait a bit before scanning again
  delay(5000);
}

