/**
 * @file median_blur.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "median_blur.h"

#include <iostream>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
MedianBlur::MedianBlur() {}

void MedianBlur::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{
	*Filtered[0] = *Original[0];

	int width = Filtered[0]->GetWidth();
	int height = Filtered[0]->GetHeight();
	int size = 3;
	int max_array_val = size*size -1;
	int middle = size *size /2;

	for (int a = 0 ; a <width; a++)
	{
		for (int b = 0; b <height; b++)
		{	
			float pixelValuesRed[size*size];
			float pixelValuesGreen[size*size];
			float pixelValuesBlue[size*size];
			float pixelValuesAlpha[size*size];	
			
			int begin = -size/2;
			int end = size/2;
			int index = 0;

			for (int i = begin; i <= end; i++)
			{
				for (int j = begin; j <= end; j++)
				{		
					pixelValuesRed[index]   = Original[0]->GetPixel(a+i, b+j).red();
					pixelValuesGreen[index] = Original[0]->GetPixel(a+i, b+j).green();
					pixelValuesBlue[index]  = Original[0]->GetPixel(a+i, b+j).blue();
					pixelValuesAlpha[index] = Original[0]->GetPixel(a+i, b+j).alpha();
					index++;	
				}
			}

			quickSort(pixelValuesRed, 0, max_array_val);
			float medianRed = pixelValuesRed[middle];

			quickSort(pixelValuesGreen, 0, max_array_val);
			float medianGreen = pixelValuesGreen[middle];
			
			quickSort(pixelValuesBlue, 0, max_array_val);
			float medianBlue = pixelValuesBlue[middle];
			
			quickSort(pixelValuesRed, 0, max_array_val);
			float medianAlpha = pixelValuesAlpha[middle]; 
			
			Color medianColor = Color (medianRed, medianGreen, medianBlue, medianAlpha);
			
			Filtered[0]->SetPixel(a,b, medianColor);
		}
	}
}

void MedianBlur::quickSort(float array[], int low, int high)
{
	if (low < high) 
    {
        int partition_index = partition(array, low, high); 

        quickSort(array, low, partition_index-1); 
        quickSort(array, partition_index+1, high); 
    } 
}

void MedianBlur::swap(float* a, float* b)
{
	float temp = *a;
	*a = *b;
	*b = temp;
}

int MedianBlur::partition(float array[], int low, int high) 
{ 
    float pivot = array[high]; 
    int i = (low-1); 
  
    for (int j = low; j < high; j++) 
    {
        if (array[j] < pivot) 
        { 
            i++;
            swap(&array[i], &array[j]); 
        } 
    } 
    
	swap(&array[i+1], &array[high]); 
    
	return (i+1); 
} 

