#include <Arduino.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include "sensor.h"

Adafruit_BMP280 bmp;

void initSensor() {
  Wire.begin(8, 9);
  bmp.begin(0x76);
}

float readTemp() {
  return bmp.readTemperature();
}

float readPressure() {
  return bmp.readPressure() / 100.0; // Convert to hPa
}