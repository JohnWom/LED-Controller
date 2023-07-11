#include <Arduino.h>
#include "Operator.h"

#define LED_PIN 26
#define NUM_LEDS 300
#define AUDIO_PIN 28

Adafruit_NeoPixel pixels(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

Operator Op(new SerialReader(), &pixels, NUM_LEDS);
void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    pinMode(AUDIO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);

    pixels.begin();
    pixels.setBrightness(50);
}

void loop()
{
    Op.main();

}