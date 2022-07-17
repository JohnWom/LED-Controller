#include "audio-processing.h"

int sampling_period_us = round(1000000 * (1/SAMPLING_FREQ));

unsigned long newTime;

double vReal[SAMPLES];
double vImag[SAMPLES];

arduinoFFT FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);

 int analyzed[8];

void sampler() {
    for (int i = 0; i < SAMPLES; i++){
        newTime=micros();
        vReal[i] = analogRead(AUDIO_IN_PIN);
        vImag[i] = 0;
        while ((micros()-newTime) < sampling_period_us ) {/* Do Nothing */}
    }

    //Reset Band Values
    for (int i = 0; i < 8; i++) {
      analyzed[i] = 0;
    }
}

void FourierFunction() {
    FFT.DCRemoval();
    FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(FFT_FORWARD); // Frequency Bin Size 39 Hz
    FFT.ComplexToMagnitude();
    Serial.print("FFTed Data:  ");
    for (int i=1; i < 20; i++){
      Serial.print(vReal[i]);
      Serial.print(", ");
    }
   Serial.println(' ');
}

void audio_analyzer() {
  
  for (int i = 0; i < (SAMPLES/2); i++) {
    if (vReal[i] > 500) {
      if (i<=3 )           {analyzed[0]  += (int)vReal[i]; continue;}
      if (i>3   && i<=6  ) {analyzed[1]  += (int)vReal[i]; continue;}
      if (i>6   && i<=13 ) {analyzed[2]  += (int)vReal[i]; continue;}
      if (i>13  && i<=27 ) {analyzed[3]  += (int)vReal[i]; continue;}
      if (i>27  && i<=55 ) {analyzed[4]  += (int)vReal[i]; continue;}
      if (i>55  && i<=112) {analyzed[5]  += (int)vReal[i]; continue;}
      if (i>112 && i<=229) {analyzed[6]  += (int)vReal[i]; continue;}
      if (i>229          ) {analyzed[7]  += (int)vReal[i]; continue;}
    }
  }

  for (int i = 0; i < 8; i++) {
    Serial.print(analyzed[i]);
    Serial.print(" | ");
  }
  Serial.println(" ");
}
