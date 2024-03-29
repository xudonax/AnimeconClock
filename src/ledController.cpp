#include <Arduino.h>
#include <FastLED.h>
#include "pinDefinitions.h"

CRGB *initFastLED(CRGB leds[], int ledCount)
{
    FastLED.addLeds<NEOPIXEL, LEDS_PIN>(leds, ledCount);

    for (int i = 0; i < ledCount; i++)
    {
        leds[i] = CRGB::Black;
    }

    return leds;
}