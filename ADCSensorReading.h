#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxAnalogToDigitalConversion(int ADC_Resolution);
int stdAnalogToDigitalConvertedValue(int ADC_Resolution);
void currentSenseAtoDConversion(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentConversionValues);
void ignoreError(void);
void ChargingCurrentSenseValue(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentSenseValues);