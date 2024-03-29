#include <Arduino.h>
#include <FastLED.h>
#include <climits>
#include "main.h"

CRGB leds[NUM_LEDS];

unsigned int theTime;
boolean pinState = HIGH;
String timeString = String();

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    Serial.println("Starting up, setting time to 0");
    theTime = 10;

    Serial.println("Initializing on-board LED...");
    pinMode(BLINK_PIN, OUTPUT);

    Serial.println("Setting on-board LED to ON...");
    digitalWrite(BLINK_PIN, pinState);
    pinState = !pinState;

    Serial.println("Initializing FastLED library...");
    initFastLED(leds, NUM_LEDS);
}

void loop()
{
    // put your main code here, to run repeatedly:
    Serial.println(theTime);
    
    if (theTime > 0)
        theTime -= 1;

    readTime();

    digitalWrite(BLINK_PIN, pinState);
    pinState = !pinState;

    delay(1000);
}

void readTime()
{
    while (Serial.available() > 0)
    {
        char c = Serial.read();
        if (isDigit(c))
        {
            timeString += c;
        }
    }

    if (timeString.length() > 0)
    {
        theTime = timeString.toInt();
        timeString.clear();
    }
}