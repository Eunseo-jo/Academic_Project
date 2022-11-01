/**
 * @file threshold_filter.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "threshold_filter.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
ThresholdFilter::ThresholdFilter() {}

ThresholdFilter::ThresholdFilter(float thresholdVal)
{
	threshold = thresholdVal;
}

void ThresholdFilter::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{
	*Filtered[0] = *Original[0];

	int width = Filtered[0]->GetWidth();
	int height = Filtered[0]->GetHeight();
	
	Color black = Color (0.0, 0.0, 0.0, 1.0);
	Color white = Color (1.0, 1.0, 1.0, 1.0);
	
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			Color pixelColor = Filtered[0]->GetPixel(i, j);
			
			float luminance = pixelColor.GetLuminance();
			
			if (luminance < threshold )
			{
				Filtered[0]->SetPixel(i,j, black);
			}
			else
			{
				Filtered[0]->SetPixel(i,j, white);
			}
				
		}
	}
}
