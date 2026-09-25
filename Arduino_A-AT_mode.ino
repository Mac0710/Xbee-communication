#include <SoftwareSerial.h>

SoftwareSerial XBee(2, 3);  // RX = 2, TX = 3

void setup() {
  Serial.begin(9600);
  XBee.begin(9600);

  Serial.println("Arduino A ready");
}

void loop() {

  // Arduino A → XBee → Arduino B
  if (Serial.available()) {
    XBee.write(Serial.read());
  }

  // Arduino B → XBee → Arduino A
  if (XBee.available()) {
    Serial.write(XBee.read());
  }
}