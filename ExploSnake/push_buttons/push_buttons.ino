/*
* The purpose of this code is to test push buttons and display it in an LCD diplay.
* Requirements:
*   Arduino board (e.g., Arduino Uno)
*   4x push buttons
*   4x 10k ohm resistors (for pull-down or pull-up resistors)
*   LCD display (e.g., 16x2 character LCD)
*/
#include <LiquidCrystal.h>

// Define the pins for the buttons and LCD
const int upButtonPin = 2;
const int downButtonPin = 3;
const int leftButtonPin = 4;
const int rightButtonPin = 5;

// Initialize the LCD library
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  // Set up the LCD
  lcd.begin(16, 2);
  
  // Initialize the button pins as INPUT_PULLUP
  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);

  // Clear the LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press a button:");
}

void loop() {
  if (digitalRead(upButtonPin) == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("Up            ");
  } else if (digitalRead(downButtonPin) == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("Down          ");
  } else if (digitalRead(leftButtonPin) == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("Left          ");
  } else if (digitalRead(rightButtonPin) == LOW) {
    lcd.setCursor(0, 1);
    lcd.print("Right         ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("               "); // Clear the second line of the LCD
  }
}
