#include <SoftwareSerial.h>
#include <ESP8266Wifi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
WiFiUDP ntpUDP;
const long offsetTime = 25200;
NTPClient timeClient(ntpUDP,"pool.ntp.org", offsetTime);
#define SSID        "Thongsongsom_2.4G"
#define PASSWORD    "thongsongsom"
SoftwareSerial mySerial(3, 1); // RX, TX
int secnow,minnow,hrnow;

void setup() {
  WiFi.begin(SSID, PASSWORD);
  mySerial.begin(9600);  // set the baud rate
}

void loop() {
  timeClient.update();
  secnow = timeClient.getSeconds();
  minnow = timeClient.getMinutes();
  hrnow = timeClient.getHours();
  String data = String(hrnow) + "," + String(minnow) + "," + String(secnow);
  mySerial.println(data); // send a message to Arduino

  delay(1000);
}

