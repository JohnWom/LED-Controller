#include <Arduino.h>
#include "Operator.h"

#define LED_PIN 26
#define NUM_LEDS 300
#define AUDIO_PIN 28

CRGB leds[NUM_LEDS];

Operator Op(new SerialReader(), leds, NUM_LEDS);
void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    pinMode(AUDIO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 2000);
    FastLED.setBrightness(100);
}

void loop()
{
    Op.main();
}