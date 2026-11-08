#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include "screen.h"

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
GFXcanvas16 canvas(240, 320); // Create a canvas for drawing


void initDisplay() {
  tft.init(240, 320);
  tft.setRotation(0);
  tft.fillScreen(ST77XX_BLACK);
}

void Drawmenu( int ms){
canvas.fillScreen(ST77XX_BLACK);

// Print a basic menu startup 
 canvas.setCursor(20, 25);
 canvas.setTextColor(ST77XX_CYAN);
 canvas.setTextSize(3);
 canvas.println("MAIN MENU");
 
 canvas.setCursor(20, 65);
    canvas.setTextColor(0x8410); 
    canvas.setTextSize(1);
    canvas.print("ESP32-S3 Weather System");

 if (ms == 1) {
canvas.drawRect(20, 95, 200, 45, ST77XX_RED); // Draw a rectangle around the text
canvas.setTextColor(ST77XX_RED); // Highlight selected menu item in red
 } else {
 canvas.drawRect(20, 95, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text
 canvas.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
 canvas.setCursor(30, 110);
 canvas.setTextSize(2);
 canvas.println("Pressure (hPa)");

 if (ms == 2) {
canvas.drawRect(20, 155, 200, 45, ST77XX_RED); // Draw a rectangle around the text
canvas.setTextColor(ST77XX_RED); // Highlight selected menu item in red
} else {
canvas.drawRect(20, 155, 200, 45, ST77XX_WHITE); // Draw a rectangle around the text;
canvas.setTextColor(ST77XX_WHITE); // Non-selected items in white
 }
canvas.setCursor(30, 170);
 canvas.setTextSize(2);
 canvas.println("Pressure (mbar)");

if (ms == 3) {
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
}

//void showData(int state, float value) {
 void drawPage(int state, float value) { 

canvas.fillScreen(ST77XX_BLACK);

  canvas.setCursor(20, 30);
  canvas.setTextSize(2);
  canvas.setTextColor(ST77XX_GREEN);
  canvas.print("WEATHER STATION");

  canvas.setCursor(20, 110);
  canvas.setTextSize(2);
  canvas.setTextColor(ST77XX_WHITE);
  
  if (state == 3) {
    canvas.print("Temperature:");
  } else {
    canvas.print("Pressure:");
  }

  canvas.setCursor(20, 160);
  canvas.setTextSize(4);
  canvas.setTextColor(ST77XX_RED);
  canvas.print(value, 1);

  canvas.setCursor(10, 200);
  canvas.setTextSize(2);
  canvas.setTextColor(0x8410);

if (state == 1){
  canvas.print(" hPa");
} else if (state == 2){
  canvas.print(" mbar");
} else if (state == 3){
  canvas.print(" C"); }

  canvas.setCursor(20, 275);
  canvas.setTextSize(1);
  canvas.setTextColor(0x8410);
  canvas.print("Click button to return");

  tft.drawRGBBitmap(0, 0, canvas.getBuffer(), 240, 320);
}