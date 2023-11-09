/*
* This Arduino Code is to play with the OLED display using I2C.
* The OLED is supposed to display white block.
* 
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); // Create an instance of the OLED display

void setup() {
  // Initialize the OLED display
  if(!display.begin(SCREEN_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the display
  display.clearDisplay();
  display.display();
}

void loop() {
  // Draw a block on the screen
  display.fillRect(10, 10, 20, 20, SSD1306_WHITE);
  display.display();
  delay(1000); // Delay for 1 second
  display.clearDisplay();
  display.display();
  delay(1000); // Delay for 1 second
}
