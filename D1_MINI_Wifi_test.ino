/**
ESP8266 Wi-Fi Test
-------------------
Connects the module to a wifi hotspot
If is connected, lights up the LED connected to D8
**/

#include <ArduinoWiFiServer.h>
#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiGratuitous.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

#define LPIN D8

String ssid = "RASFI";
String pswd = "RASFI678";

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pswd);
  pinMode(LPIN, OUTPUT);

  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("Wifi connected!");
  Serial.println(WiFi.localIP());
}

int once = 0;

void loop() {
  if (WiFi.status() == WL_CONNECTED){
    if (once == 1){
      Serial.println("Connected");
      Serial.println(WiFi.localIP());
      once = 0;
    }
    digitalWrite(LPIN, HIGH);
  } else {
    if (once == 0){
      Serial.println("Disconnected");
      once = 1;
    }
    digitalWrite(LPIN, LOW);
  }
}
