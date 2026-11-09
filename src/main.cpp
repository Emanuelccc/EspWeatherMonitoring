#include <Arduino.h>
#include "sensor.h"
#include "screen.h"

//The pins for the joystick Y-axis & SW 
#define JOYS_Y 14
#define JOY_SW 13


int menuselect = 1;  // Variable to track the selected menu item
int page = 0;      // PAGE 0-menu, 1-pressure pha, 2-pressure mbar, 3-temperature


void setup() {


initDisplay();
initSensor();

 pinMode(JOYS_Y, INPUT); // Set joystick Y-axis pin as input
 pinMode(JOY_SW, INPUT_PULLUP); // Set joystick switch pin as input with pull-up resistor

 Drawmenu(menuselect);   // initially draw the main menu
}

void loop() {

bool button = digitalRead(JOY_SW); // Read the state of the joystick button
//open the page
if(button == LOW){
   if (page == 0) {
 page = menuselect;
} else {
 page = 0; // Return to the main menu
 Drawmenu(menuselect);
}delay(200);    
}
// Main Menu logic
if (page == 0) {
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
 
} else { // = if page != 0 if a page is selected, then read values. 
    float val = 0.0;
    if (page == 3) {
      val = readTemp();
    } else {
      val = readPressure();
    }
    
    drawPage(page, val);
  }
}
