### Weather Monitoring 
# Introduction
A menu-driven weather station powered by an ESP32S3 microcontroller, sharing live environmental data through the use of a BMP280 sensor, graphical display ST7789 TFT, and a JOYSTICK CONTROLLER for physical navigation.
# Hardware specifications & pinout 
- ST7789 TFT, uses SPI, Pins: CS, DC, RST, SDA(MOSI), SCL(SCK).
- BMP280, uses I2C, Pins: SDA, SCL.
- Joystick, uses Analog/Digital pins
# Library used
- 'Adafruit GFX Library'
- 'Adafruit ST7789 Library'
- 'Adafruit BMP280 Library'
# Project Steps
- TFT Display: Setup and verify communicatioin.
- BMP280 Sensor: Interface the BMP280 sensor via I2C for real time pressure and temperature.
- Joystick: Read analog for coordinates and digital for the click iplementation.
- Menu system: Make the menu panel and enable navigation between options.
- Schematic and PCB: Translate the breadboard prototype into a printed circuit board. 
