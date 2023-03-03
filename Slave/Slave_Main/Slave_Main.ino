#include "Operator.h"

#define LED_PIN D0
#define NumLeds 300
#define AUDIO_PIN A2

// Set Up =================================================================================
// Static Class Initialization Procedures. Thread requires static functions
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

// Create Operator Object. Only non-static class currently in system
Operator Op;
//=========================================================================================

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial1.begin(115200);

  // Set up pins
  pinMode(AUDIO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  //Start LEDS
  pixels.begin();
  pixels.setBrightness(50);
}

void loop() {
  // Main Thread - Simply Reading Serial Port
  // Side (Pattern) Thread is spawned by main thread whenever changes occur
  Op.readSerial();
}


