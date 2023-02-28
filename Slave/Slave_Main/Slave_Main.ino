#include "Operator.h"

using namespace rtos;

#define LED_PIN 0
#define NumLeds 300
#define AUDIO_PIN A2

Thread t;

Adafruit_NeoPixel pixels(NumLeds, LED_PIN, NEO_GRB + NEO_KHZ800);

LED_Controller leds(&pixels, (int) NumLeds);

AudioProcessor AP;

Patterns P(&leds, &AP);

Operator Op(&t, &P);

void main_thread(void) {
  while (true) {
    // main thread
    Op.readSerial();
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);

  // Set up pins
  pinMode(AUDIO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

}

// Loop not needed
// Threads run in thread1, thread2
void loop() {
  Op.readSerial();
}