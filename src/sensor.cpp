#include <Adafruit_BMP280.h>
#include <Wire.h>
#include "sensor.h"

Adafruit_BMP280 bmp;

void initSensor() {  // initialise the BMP280 sensor
  Wire.begin(8, 9);
  bmp.begin(0x76);
}
// Function to read temperature 
float readTemp() {
  return bmp.readTemperature();
}
// Function to read pressure 
float readPressure() {
  return bmp.readPressure() / 100.0; // Convert to hPa
}