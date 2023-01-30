#pragma once

#include <stdio.h>
#include <stdbool.h>


typedef struct{
	int StartIndex;
	int EndIndex;
	int NumOfReadingsInRange;
}RangeReading;

extern int numberofContinuousRange( int *ChargingCurrentReadings, int numOfCCReadings);
extern bool validateCurrentReadingInputSequence(int *InputSequence , int length);
extern void sortInputSeq(int *InputSequence , int length);
RangeReading detectCurrentReadingAndFormatOutputInCSVFormat( int min, int max, int numberInRange);
void printOutputInCSV(char  ChargingCurrentReadings);

