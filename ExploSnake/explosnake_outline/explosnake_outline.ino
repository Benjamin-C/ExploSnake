/*
* The purpose of this code is to outline the snake game into the OLED screen.
* *** NOTE: This is just an outline for it. The game itself still need to be created.***
*/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define snake properties
int snakeX, snakeY;
int foodX, foodY;
int direction; // 0: up, 1: right, 2: down, 3: left
int snakeLength;
int snakeXArray[100], snakeYArray[100];

// Define button pins
const int upButtonPin = 2;
const int downButtonPin = 3;
const int leftButtonPin = 4;
const int rightButtonPin = 5;

// Timing variables
unsigned long previousMillis = 0;
const long interval = 100; // Update interval in milliseconds (adjust as needed)

void setup() {
  // Initialize OLED display
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.display();
  delay(2000);  // Pause for 2 seconds

  // Initialize buttons
  pinMode(upButtonPin, INPUT_PULLUP);
  pinMode(downButtonPin, INPUT_PULLUP);
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);

  // Initialize game variables
  snakeX = SCREEN_WIDTH / 2;
  snakeY = SCREEN_HEIGHT / 2;
  generateFood();
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if it's time to update the game
  if (currentMillis - previousMillis >= interval) {
    // Update the game at the specified interval
    previousMillis = currentMillis;

    // Check button inputs and update snake direction
    checkButtons();

    // Move the snake
    moveSnake();

    // Check for collisions with food or boundaries
    checkCollisions();

    // Draw the game on the OLED display
    drawGame();
  }
}

void checkButtons() {
  // Implement button logic to set the 'direction' variable
  // based on which button is pressed.
}

void moveSnake() {
  // Update the snake's position based on the current direction.
  // Also, update the snake's tail positions in the arrays.
}

void checkCollisions() {
  // Check for collisions with the food or boundaries.
  // Update the game state accordingly.
}

void drawGame() {
  // Clear the display
  display.clearDisplay();

  // Draw the snake and food on the display
  // Use display.drawPixel() or display.drawRect() to draw pixels or rectangles.

  // Update the display
  display.display();
}

void generateFood() {
  // Generate random coordinates for the food within the screen boundaries.
  // Update the 'foodX' and 'foodY' variables.
}