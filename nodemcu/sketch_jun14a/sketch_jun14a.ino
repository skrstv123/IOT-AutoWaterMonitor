/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/
#include <Arduino.h>
  int trig=5;
  int echo=0;
  int led =12;


int x=0;
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

#define DHTPIN D0
#define DHTTYPE DHT11
String str;

ESP8266WiFiMulti WiFiMulti;
int humi,temp;
void setup() {
  
    pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
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
  WiFiMulti.addAP("Sreeparna", "Sree@1491999");

}

void loop() {
  
  
   
  long distance,duration;
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration/2)/29.1;
  Serial.println((String)distance+"cm");
  delay(10);
    
    int mx=35;
int level=mx-distance;
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;
    long n = 458766;
    
    
    //String str = "http://niedc.com/msit.php?t1="+t1+"&t2="+t2;
    String str = "http://skrstv.000webhostapp.com/rcv.php?lvl="+(String)level;
    String got="http://skrstv.000webhostapp.com/onoff.txt";
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

  delay(10000);
  if(level>=(mx-5)){
    digitalWrite(led,HIGH);
    Serial.println("relay is off");}
  else if(distance<(mx-25) && x==1){
    digitalWrite(led,LOW);
    Serial.println("relay is on");}
    

}
