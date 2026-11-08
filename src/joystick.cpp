#include <Arduino.h>
#include "joystick.h"

#define BUTTON_PIN 13
#define JOY_Y 14

int lastButtonState = HIGH; // Regular variable to remember button state

void initJoystick() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

bool checkButton() {
  int currentButton = digitalRead(BUTTON_PIN);
  bool clicked = false;

  if (lastButtonState == HIGH && currentButton == LOW) {
    clicked = true;
    delay(50); // Simple debounce delay
  }
  
  lastButtonState = currentButton;
  return clicked;
}

int readJoystickY() {
  return analogRead(JOY_Y);
}