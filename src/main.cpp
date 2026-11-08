#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <SPI.h>
#include "sensor.h"
#include "screen.h"

// Define the pin for the joystick Y-axis
#define JOYS_Y 14
#define JOY_SW 13
// Initialize Adafruit ST7789 library (using hardware SPI)
//Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
//GFXcanvas16 canvas(240, 320); // Create a canvas for drawing

int menuselect = 1;  // Variable to track the selected menu item
int page = 0;      // PAGE NR 0-menu, 1-pressure pha, 2-pressure mbar, 3-temperature
int lastPage = -1;   // Track page changes to clear screen properly

void setup() {
 Serial.begin(115200);

initDisplay();
initSensor();

 pinMode(JOYS_Y, INPUT); // Set joystick Y-axis pin as input
 pinMode(JOY_SW, INPUT_PULLUP); // Set joystick switch pin as input with pull-up resistor

 Drawmenu(menuselect);
}

void loop() {

bool button = digitalRead(JOY_SW); // Read the state of the joystick button
//open the page
if(button == LOW){
   if (page == 0) {
 page = menuselect;
 float val = 0.0;
      if (page == 3) {
        val = readTemp();
      } else {
        val = readPressure();
      }
      drawPage(page, val);
} else {
 page = 0; // Return to the main menu
 Drawmenu(menuselect);
}delay(200);
}
// Main Menu logic
 int val_y = analogRead(JOYS_Y); // Read the joystick Y-axis value
if (val_y > 3000){
 menuselect++;    // Move to the next menu option
 if (menuselect > 3) {
 menuselect = 1; // Wrap around to the first menu item
 }
Drawmenu(menuselect);
 delay(300);
} 
else if (val_y < 1000){
 menuselect--;
 if (menuselect < 1) {
 menuselect = 3; // Wrap around to the last menu item
 }
  Drawmenu(menuselect);
 delay(300);

} 
 
}
