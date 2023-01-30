#include "ADCSensorReading.h"

int maxAnalogToDigitalConversion(int ADC_Resolution)
{
	return (pow(2,ADC_Resolution) - 2);
}

void currentSenseAtoDConversion(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentConversionValues)
{	
	float currentValue, analogToDigitalCoversionValue;
	
	for (int i=0; i< numberOfSamples; i++)
	{
		analogToDigitalCoversionValue = (ADCValues[i]) / (maxAnalogToDigitalConversion(ADC_Resolution));
		currentValue = (maxCurrentValue * analogToDigitalCoversionValue) / (maxAnalogToDigitalConversion(ADC_Resolution));
		currentConversionValues[i] = round(currentValue);
		if(currentConversionValues[i] < 0)
			currentConversionValues[i] = abs(currentConversionValues[i]);
	}	
}

void ChargingCurrentSenseValue(int ADCValues[], int numberOfSamples, int ADC_Resolution, int maxCurrentValue, int* currentSenseValues)
{
	int errorValue;
	errorValue = (pow(2,ADC_Resolution) - 1);
	for (int i=0; i< numberOfSamples; i++)
	{
		if(ADCValues[i] != errorValue)
		{
			currentSenseAtoDConversion(ADCValues, numberOfSamples, ADC_Resolution, maxCurrentValue,currentSenseValues);
		}
	}
	
}
