/**
ESP8266 To Node-Red Transmission
--------------------------------
Gets data from the Arduino through Serial port and sends it to Node-red via wifi
LED at D8 is ON when module is connected to wifi
To be uploaded in the ESP8266 module
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
#include<SoftwareSerial.h>

SoftwareSerial mySUART(4, 5);

const char* ssid = "espFI";
const char* pswd = "espwifi678";

#define LPIN D8

void setup()
{
  WiFi.softAP(ssid, pswd);
  Serial.begin(9600);
  mySUART.begin(9600);
  pinMode(LPIN, OUTPUT);
  delay(1000);
  if(WiFi.softAPConfig(IPAddress(192, 168, 4, 1), IPAddress(192, 168, 4, 1), IPAddress(255, 255, 255, 0))){
    digitalWrite(LPIN, HIGH);
    Serial.println(WiFi.softAPIP());
  } else {
    Serial.println("not deployed");
  }
}

int once = 0;

void loop()
{
  if (mySUART.available()){
    Serial.print((char)mySUART.read());
  }

  if (Serial.available()){
    mySUART.write((char)Serial.read());
  }
}