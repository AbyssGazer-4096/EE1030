#include <Arduino.h>
#define sensor A0

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
}

void loop()
{
  float volt = 5*(float)analogRead(sensor)/1024;
  Serial.println(volt);
  delay(200);
}
