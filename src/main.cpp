#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <SPI.h>
#include "sensor.h"

// Define the pins for the TFT display 
#define TFT_CS 4    // Chip select pin
#define TFT_RST  6  // Reset pin 
#define TFT_DC 5  // Data/Command pin 
// Define the pin for the joystick Y-axis
#define JOYS_Y 14
#define JOY_SW 13
// Initialize Adafruit ST7789 library (using hardware SPI)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
GFXcanvas16 canvas(240, 320); // Create a canvas for drawing

int menuselect = 1;  // Variable to track the selected menu item
int page = 0;      // PAGE NR 0-menu, 1-pressure pha, 2-pressure mbar, 3-temperature
int lastPage = -1;   // Track page changes to clear screen properly

void Drawmenu();
void drawPage(int state);

void setup() {
 Serial.begin(115200);

// Initialize the display
 tft.init(240, 320); 
 tft.setRotation(0); // Adjust rotation
 
// Clear the screen to black
tft.fillScreen(ST77XX_BLACK);

 pinMode(JOYS_Y, INPUT); // Set joystick Y-axis pin as input
 pinMode(JOY_SW, INPUT_PULLUP); // Set joystick switch pin as input with pull-up resistor

 Drawmenu();
}

void loop() {

bool button = digitalRead(JOY_SW); // Read the state of the joystick button
//open the page
if(button == LOW){
   if (page == 0) {
 page = menuselect;
 drawPage(page);
} else {
 page = 0; // Return to the main menu
 Drawmenu();
}delay(200);
}
// Main Menu logic
 int val_y = analogRead(JOYS_Y); // Read the joystick Y-axis value
if (val_y > 3000){
 menuselect++;    // Move to the next menu option
 if (menuselect > 3) {
 menuselect = 1; // Wrap around to the first menu item
 }
Drawmenu();
 delay(300);
} 
else if (val_y < 1000){
 menuselect--;
 if (menuselect < 1) {
 menuselect = 3; // Wrap around to the last menu item
 }
  Drawmenu();
 delay(300);
} 
 

}

void Drawmenu(){
canvas.fillScreen(ST77XX_BLACK);

if (page == 0) {
// Print a basic menu startup 
 canvas.setCursor(20, 25);
 canvas.setTextColor(ST77XX_CYAN);
 canvas.setTextSize(3);
 canvas.println("MAIN MENU");
 
 canvas.setCursor(20, 65);
    canvas.setTextColor(0x8410); 
    canvas.setTextSize(1);
    canvas.print("ESP32-S3 Weather System");

 if (menuselect == 1) {
canvas.drawRect(20, 95, 200, 45, ST77XX_RED); // Draw a rectangle around the text
canvas.setTextColor(ST77XX_RED); // Highlight selected menu item in red
 } else {
 canvas.drawRect(20, 95, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text
 canvas.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
 canvas.setCursor(30, 110);
 canvas.setTextSize(2);
 canvas.println("Pressure (hPa)");

 if (menuselect == 2) {
canvas.drawRect(20, 155, 200, 45, ST77XX_RED); // Draw a rectangle around the text
canvas.setTextColor(ST77XX_RED); // Highlight selected menu item in red
} else {
canvas.drawRect(20, 155, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text;
canvas.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
canvas.setCursor(30, 170);
 canvas.setTextSize(2);
 canvas.println("Pressure (mbar)");

if (menuselect == 3) {
canvas.drawRect(20, 215, 200, 45, ST77XX_RED); // Draw a rectangle around the text
canvas.setTextColor(ST77XX_RED); // Highlight selected menu item in red
 } else {
 canvas.drawRect(20, 215, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text;
 canvas.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
 canvas.setCursor(30, 230);
 canvas.setTextSize(2);
 canvas.println("Temperature");

 // Footer instructions
    canvas.setCursor(20, 280);
    canvas.setTextSize(1);
    canvas.setTextColor(0x8410);
    canvas.print("Scroll Y | Click to Select");

tft.drawRGBBitmap(0,0, canvas.getBuffer(),240, 320); // Draw the canvas to the display
}}

void drawPage(int state) { 

tft.fillScreen(ST77XX_BLACK);

  tft.setCursor(20, 30);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_GREEN);
  tft.print("WEATHER STATION");

  tft.setCursor(20, 110);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  
  if (state == 3) {
    tft.print("Temperature:");
  } else {
    tft.print("Pressure:");
  }

  tft.setCursor(20, 160);
  tft.setTextSize(4);
  tft.setTextColor(ST77XX_RED);
  //tft.print(value, 1);

  tft.setCursor(20, 275);
  tft.setTextSize(1);
  tft.setTextColor(0x8410);
  tft.print("Click button to return");
}
