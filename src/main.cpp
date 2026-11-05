#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Use I2C interface

void setup() {
  Serial.begin(115200);

 Wire.begin();
 bmp.begin(0x76);
}

void loop() {
    Serial.print(F("Temperature = "));
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");

    Serial.print(F("Pressure = "));
    Serial.print(bmp.readPressure() / 100); // Convert Pa to hPa
    Serial.println(" hPa");
    delay(2000);
}