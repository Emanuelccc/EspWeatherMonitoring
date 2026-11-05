#include <Arduino.h>

#define JOYS_Y 14
#define JOY_SW 13

void setup() {
  Serial.begin(115200);
  pinMode(JOYS_Y, INPUT);
  pinMode(JOY_SW, INPUT_PULLUP); // Internal pull-up for button click
}

void loop() {
  int yValue = analogRead(JOYS_Y);
  bool swState = digitalRead(JOY_SW);
  
  if (swState == LOW) {
    Serial.println("Button Pressed!");
  } else {
    Serial.println("Button Released!");
  }
  if (yValue < 1000) {
    Serial.println("Joystick moved up");
  } else if (yValue > 3000) {
    Serial.println("Joystick moved down");
  }
  delay(200);
}