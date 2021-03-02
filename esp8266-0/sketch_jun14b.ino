/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/
#include <Arduino.h>
  //int trig=16;

  int led =14;
#include "DHT.h"

int x=0;
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

#define DHTPIN 16
#define DHTTYPE DHT11
String str;
DHT dht(DHTPIN,DHTTYPE);
ESP8266WiFiMulti WiFiMulti;
int humi,temp;
void setup() {
  
    //pinMode(trig,);
  //pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
  
  Serial.begin(9600);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Redmi", "shivam99");

}

void loop() {
  
  float t=dht.readTemperature();  
  delay(2000);
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;
    long n = 458766;
    
    
    //String str = "http://niedc.com/msit.php?t1="+t1+"&t2="+t2;
    String str = "http://exegetical-transfor.000webhostapp.com/rcv.php?tmp="+(String)t;
    String got="http://exegetical-transfor.000webhostapp.com/onoff.txt";
    //x++;
    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, str)) {  // HTTP

  
      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();
      Serial.println("sent");
      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  
  //===============================receiving============================================
      Serial.print("[HTTP] begin...receiving phase\n");
    if (http.begin(client, got)) {  // HTTP

  
      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();
      Serial.println("sent");
      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String paylod = http.getString();
      if(paylod=="0")
        x=0;
      else if(paylod="1")
        x=1;
          Serial.println(paylod);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
  
  
  }

  delay(8000);
  if(t>=29 && x==1){
    digitalWrite(led,LOW);
    Serial.println("relay set to on");}
   if(t>=29 && x==0){
    digitalWrite(led,HIGH);
    Serial.println("relay set to off");}
  else if(t<=15){
    digitalWrite(led,HIGH);
    Serial.println("relay set to off");}
    

}
