#include "DHT.h"
int DHTPIN = 2;
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DHTPIN,INPUT);
}
int dd=1;
void loop() {
  // put your main code here, to run repeatedly:
  if(dd){
    dd=0;
  delay(2500);
  }
  float t,h;
  t=dht.readTemperature();
  h=dht.readHumidity();
  Serial.println("TEMPERATURE IS: " +(String) t);
  Serial.println("HUMIDITY IS: " + (String) h);
  
  delay(1000);
  Serial.println();
  
  
  
}
