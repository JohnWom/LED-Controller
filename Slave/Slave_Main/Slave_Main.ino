#include "Operator.h"

using namespace rtos;

#define LED_PIN 0
#define NumLeds 300
#define AUDIO_PIN A2

Thread t;

Adafruit_NeoPixel pixels(NumLeds, LED_PIN, NEO_GRB + NEO_KHZ800);

int LED_Controller::num_leds = NumLeds;
Adafruit_NeoPixel* LED_Controller::NeoPix = &pixels;

arduinoFFT AudioProcessor::FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);;
double AudioProcessor::vReal[SAMPLES];
double AudioProcessor::vImag[SAMPLES];

int Patterns::r = 0;
int Patterns::g = 0;
int Patterns::b = 0;

void (*Operator::pattern)(void) = &Patterns::Solid_Color;

Operator Op;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);

  // Set up pins
  pinMode(AUDIO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  //t.start(mbed::callback(Op.runPattern));

}

// Loop not needed
// Threads run in thread1, thread2
void loop() {
  Op.readSerial();
}