#include <Arduino.h>

#define BUTTON_PIN 5
#define CAP_PIN 11

#define CAP_PULSE_TIME 1 // ms
#define LED_ADDITIONAL_TIME 100 // ms

int readIntFromSerial();

void setup() {
    pinMode(CAP_PIN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    Serial.begin(115200);
    Serial.println("abc");
}

void loop() {

    // Ask for the time
    Serial.println("Please input pulse time in ms");
    int d = readIntFromSerial();
    Serial.print("Time is ");
    Serial.println(d);
    Serial.println("Press button to boom");

    // Wait for the button to be pressed
    while(digitalRead(BUTTON_PIN));

    // Activate cap for CAP_PULSE_TIME us
    Serial.println(d);
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(CAP_PIN, HIGH);
    delay(d);
    digitalWrite(CAP_PIN, LOW);
    delay(LED_ADDITIONAL_TIME);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.println("Boom done");

    // Wait for the button to be released
    delay(10);
    while(!digitalRead(BUTTON_PIN));
    delay(10);
}

int readIntFromSerial() {
    // Wait for data to be available in the serial buffer
    while(!Serial.available());

    int receivedInt = 0;
    bool isNegative = false;
    char incomingChar;

    bool end = false; 

    while(!end) {
        incomingChar = Serial.read();

        if(incomingChar == '-') {
            isNegative = true;
        } else if(incomingChar >= '0' && incomingChar <= '9') {
            receivedInt = receivedInt * 10 + (incomingChar - '0');
        } else if(incomingChar == '\n') {
            end = true;
        }
    }

    if(isNegative) {
        receivedInt = -receivedInt;
    }

    return receivedInt;
}