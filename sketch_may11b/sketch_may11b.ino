/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/
#include <Arduino.h>

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
  WiFiMulti.addAP("fantastic", "singhrai");

}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;
    long n = 458766;
    
    
    //String str = "http://niedc.com/msit.php?t1="+t1+"&t2="+t2;
    String str = "http://skrstv.000webhostapp.com/rcv.php?lvl="+(String)x;
    String got="http://skrstv.000webhostapp.com/onoff.txt";
    x++;
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
          String paylo = http.getString();
          Serial.println(paylo);
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

}
