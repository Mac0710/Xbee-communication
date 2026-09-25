#include <SoftwareSerial.h>

SoftwareSerial XBee(2, 3);  // RX = Pin 2, TX = Pin 3

void setup() {
  Serial.begin(9600);
  XBee.begin(9600);

  Serial.println("XBee communication started");
}

void loop() {

  /*
  XBee.write("Hello from Arduino!");
  */

  // PC → Arduino → XBee
  if (Serial.available()) {
    XBee.write(Serial.read());
  }

  // XBee → Arduino → PC
  if (XBee.available()) {
    Serial.write(XBee.read());
  }
}