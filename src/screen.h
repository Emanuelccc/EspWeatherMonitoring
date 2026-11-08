#ifndef SCREEN_H
#define SCREEN_H

// Define the pins for the TFT display 
#define TFT_CS 4    // Chip select pin
#define TFT_RST  6  // Reset pin 
#define TFT_DC 5  // Data/Command pin 


void initDisplay();
void Drawmenu( int ms);
void drawPage(int state, float value);


#endif