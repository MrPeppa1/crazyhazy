#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char WiFiAPPSK[] = "sparkfun";
WiFiServer server(80);

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 12

// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  setupWiFi();
  server.begin();
  sensors.begin();
}


void loop(void)
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
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
  // 0 refers to the first IC on the wire

}

void setupWiFi()
{
  WiFi.mode(WIFI_AP);

  // Do a little work to get a unique-ish name. Append the
  // last two bytes of the MAC (HEX'd) to "Thing-":
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX) +
                 String(mac[WL_MAC_ADDR_LENGTH - 1], HEX);
  macID.toUpperCase();
  String AP_NameString = "ESP8266 Thing " + macID;

  char AP_NameChar[AP_NameString.length() + 1];
  memset(AP_NameChar, 0, AP_NameString.length() + 1);

  for (int i=0; i<AP_NameString.length(); i++)
    AP_NameChar[i] = AP_NameString.charAt(i);

  WiFi.softAP(AP_NameChar, WiFiAPPSK);
      Serial.println(macID);

}



