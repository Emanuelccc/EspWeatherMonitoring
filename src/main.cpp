#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <SPI.h>


// Define the pins for the TFT display 
#define TFT_CS 4    // Chip select pin
#define TFT_RST  6  // Reset pin 
#define TFT_DC 5  // Data/Command pin 
// Define the pin for the joystick Y-axis
#define JOYS_Y 14
// Initialize Adafruit ST7789 library (using hardware SPI)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int menuselect = 1;  // Variable to track the selected menu item

void Drawmenu();

void setup() {
 Serial.begin(115200);

// Initialize the display
 tft.init(240, 320); 
 tft.setRotation(0); // Adjust rotation
 
// Clear the screen to black
tft.fillScreen(ST77XX_BLACK);

 pinMode(JOYS_Y, INPUT); // Set joystick Y-axis pin as input
}

void loop() {
// Main Menu logic
 int val_y = analogRead(JOYS_Y); // Read the joystick Y-axis value
if (val_y > 3000){
 menuselect++;    // Move to the next menu option
 if (menuselect > 3) {
 menuselect = 1; // Wrap around to the first menu item
 }
 delay(200);
} 
else if (val_y < 1000){
 menuselect--;
 if (menuselect < 1) {
 menuselect = 3; // Wrap around to the last menu item
 }
 delay(200);
} 
Drawmenu();

}
void Drawmenu(){


// Print a basic menu startup 
 tft.setCursor(20, 25);
 tft.setTextColor(ST77XX_CYAN);
 tft.setTextSize(3);
 tft.println("MAIN MENU");
 
 tft.setCursor(20, 65);
    tft.setTextColor(0x8410); 
    tft.setTextSize(1);
    tft.print("ESP32-S3 Weather System");

 if (menuselect == 1) {
tft.drawRect(20, 95, 200, 45, ST77XX_RED); // Draw a rectangle around the text
tft.setTextColor(ST77XX_RED); // Highlight selected menu item in red
 } else {
 tft.drawRect(20, 95, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text
 tft.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
 tft.setCursor(30, 110);
 tft.setTextSize(2);
 tft.println("Pressure (hPa)");

 if (menuselect == 2) {
tft.drawRect(20, 155, 200, 45, ST77XX_RED); // Draw a rectangle around the text
tft.setTextColor(ST77XX_RED); // Highlight selected menu item in red
} else {
tft.drawRect(20, 155, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text;
tft.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
 tft.setCursor(30, 170);
 tft.setTextSize(2);
 tft.println("Pressure (mbar)");

if (menuselect == 3) {
tft.drawRect(20, 215, 200, 45, ST77XX_RED); // Draw a rectangle around the text
tft.setTextColor(ST77XX_RED); // Highlight selected menu item in red
 } else {
 tft.drawRect(20, 215, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text;
 tft.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
 tft.setCursor(30, 230);
 tft.setTextSize(2);
 tft.println("Temperature");

 // Footer instructions
    tft.setCursor(20, 280);
    tft.setTextSize(1);
    tft.setTextColor(0x8410);
    tft.print("Scroll Y | Click to Select");
}