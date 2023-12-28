
#include "OtaHelper.h"
// Instance of the ConnectOta class
OtaHelper OTA;

int ledPin = 2;
int ledPin2 = 16;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // ssid: Wi-Fi network name
  // password: Wi-Fi network password
  // hostName: Device name on the local network (for mDNS)
  // hostPassword: Password for OTA updates
  // port: Port for OTA updates
  // baudRate: Serial communication speed
  OTA.start("ssid", "password", "hostName", "hostPassword", 3232, 115200);
}

void loop() {
  OTA.handle();

  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(1000); 

  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(1000); 
}
