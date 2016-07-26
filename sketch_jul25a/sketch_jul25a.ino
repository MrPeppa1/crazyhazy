#include <dht.h>

dht DHT1;
dht DHT2;

#define DHT11_PIN1 7
#define DHT11_PIN2 6
#define DHT11_PIN3 5

void setup(){
  Serial.begin(9600);
  pinMode(DHT11_PIN3, OUTPUT);
}

void loop()
{
  int chk1 = DHT1.read11(DHT11_PIN1);
  int chk2 = DHT2.read11(DHT11_PIN2);
  Serial.print("Temperatur  = ");
  Serial.print(DHT1.temperature);  
  Serial.print(" - ");
  Serial.println(DHT2.temperature);
  Serial.print("Feuchtigkeit  = ");
  Serial.print(DHT1.humidity);
  Serial.print(" - ");
  Serial.println(DHT2.humidity);
    if(DHT2.humidity>36){
      digitalWrite(DHT11_PIN3,1);
    }
    else if(DHT2.humidity<36){
      digitalWrite(DHT11_PIN3,0);
      }
      else{
        digitalWrite(DHT11_PIN3,1);
        }
  delay(1000);
}

