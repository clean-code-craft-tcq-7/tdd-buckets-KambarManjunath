#include "CurrentReading.h"
int NumberofContRange = 0;

int count = 1;

bool validateCurrentReadingInputSequence(int *InputSequence , int length)
{
	int i;
	for(i= 0; i < length; i++)
	{
		if(InputSequence[i] >= 0)
		{
			sortInputSeq(InputSequence, length);			
			return true;
		}	
		else
		{
			return false;
		}
	}

}
void sortInputSeq(int *InputSequence , int length)
{
	int i , j , temp ;
	for(i=0; i< length; i++)
	{
		for(j=i+1; j< length; j++)
		{
			if(InputSequence[i] > InputSequence[j])
			{
				temp = InputSequence[i];
				InputSequence[i] = InputSequence[j];
				InputSequence[j] = temp; 
			}
		}	
	}
}

int numberofContinuousRange(int *ChargingCurrentReadings, int numOfCCReadings)
{
    int i, j, curRead;
    if(validateCurrentReadingInputSequence(ChargingCurrentReadings, numOfCCReadings) == true)
    {
	    for(i = 0; i < numOfCCReadings; i++)
	    {
		curRead = (ChargingCurrentReadings[i+1] -  ChargingCurrentReadings[i]);
		if((curRead == 0) || (curRead == 1))
		{
			count++;
		}
		
	    }
	   return count;
    }
}

RangeReading detectCurrentReadingAndFormatOutputInCSVFormat( int min, int max, int numberInRange)
{
	RangeReading rangeReading;
	char ChargingCurrentReadings;
	rangeReading.StartIndex=min;
	rangeReading.EndIndex= max;
	rangeReading.NumOfReadingsInRange= numberInRange;
	printf( " %d - %d , %d",  min, max , numberInRange); 

	return rangeReading;
}

