#include <Arduino.h>
#include "Operator.h"

#define LED_PIN 26
#define NumLeds 300
#define AUDIO_PIN 28

Adafruit_NeoPixel pixels(NumLeds, LED_PIN, NEO_GRB + NEO_KHZ800);

Operator Op(new SerialReader(), &pixels, NumLeds);
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
    digitalWrite(LED_BUILTIN, HIGH);
    Op.main();
    digitalWrite(LED_BUILTIN, LOW);

    pixels.setPixelColor(11, 255, 0, 0);
    pixels.show();
}