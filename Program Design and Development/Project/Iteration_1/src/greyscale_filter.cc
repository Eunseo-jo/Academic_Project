/**
 * @file greyscale_filter.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "greyscale_filter.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
GreyScaleFilter::GreyScaleFilter() {}

void GreyScaleFilter::Apply (vector<Image*> &Original, vector<Image*> &Filtered)
{
	*Filtered[0] = *Original[0];

	int width = Filtered[0]->GetWidth();
	int height = Filtered[0]->GetHeight();
	
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			Color pixelColor = Filtered[0]->GetPixel(i, j);
			float L = pixelColor.GetLuminance();
			Color greyColored = Color (L, L, L, 1.0);
			Filtered[0]->SetPixel(i,j, greyColored);
			
		}
	}
}
