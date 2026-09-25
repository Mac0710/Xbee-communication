#include <SoftwareSerial.h>

SoftwareSerial XBee(2, 3);  // RX = 2, TX = 3

void setup() {
  Serial.begin(9600);
  XBee.begin(9600);

  Serial.println("Arduino B ready");
}

void loop() {

  // Arduino B → XBee → Arduino A
  if (Serial.available()) {
    XBee.write(Serial.read());
  }

  // Arduino A → XBee → Arduino B
  if (XBee.available()) {
    Serial.write(XBee.read());
  }
}