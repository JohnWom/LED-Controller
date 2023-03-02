#include "AudioProcessor.h"

AudioProcessor::AudioProcessor()
{
  FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);
}

void AudioProcessor::followBeat()
{

}

void AudioProcessor::threeBand()
{

}

void AudioProcessor::fiveBand()
{

}

void AudioProcessor::volume()
{

}

void AudioProcessor::readAudio()
{
  unsigned long newTime;
  for (int i = 0; i < SAMPLES; i++){
        newTime=micros();
        vReal[i] = analogRead(AUDIO_IN_PIN);
        vImag[i] = 0;
        while ((micros()-newTime) < 22) {/* Do Nothing */}   // time between samples, 44.1kHz rate
    }
}

void AudioProcessor::runFFT()
{
  FFT.DCRemoval();                                      // Noise Removal Function
  FFT.Windowing(FFT_WIN_TYP_FLT_TOP, FFT_FORWARD);      // Windowing Function
  FFT.Compute(FFT_FORWARD);                             // Performing FFT
  FFT.ComplexToMagnitude();                             // Calculating Magnitudes
}