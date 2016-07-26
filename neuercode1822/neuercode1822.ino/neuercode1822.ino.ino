
#include <ESP8266WiFi.h>
#include <OneWire.h>
#include <DallasTemperature.h>

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
  connectToAP("2muchswag", "gaynille");
  sensors.begin();
}


void loop(void)
{

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
}




