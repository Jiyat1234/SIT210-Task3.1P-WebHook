#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include "DHT.h"

char name[] = "bhardwaj";         
char passw[] = "airtelxstream";     
unsigned long channelId = 2241051;   
const char *APIkey = "N38OAM95O0HSC2ZZ";

WiFiClient client;
DHT dht(2, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(wifi_name);
    WiFi.begin(wifi_name, password);
    delay(1000);
  }

  Serial.println("connection succesfull");

  ThingSpeak.begin(client);

}


void loop() {
  // put your main code here, to run repeatedly:
  float temp = dht.readTemperature();
  Serial.print("Temprraature = ");
  Serial.print(temp);
  Serial.println("C");

  ThingSpeak.writeField(channelId, 1, temp, APIkey);
  Serial.print("Data sent.");
  
  delay(30000);  
}
