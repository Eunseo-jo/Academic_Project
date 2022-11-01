/**
 * @file hysteresis_filter.cc
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hysteresis_filter.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
HysteresisFilter::HysteresisFilter() {}

void HysteresisFilter::Apply (vector<Image*> &Original, vector<Image*> &Filtered)
{
    // Set Filtered image to Original
    *Filtered[0] = *Original[0];

    // Assign width and height of the image
	int width = Filtered[0]->GetWidth();
	int height = Filtered[0]->GetHeight();
    
    // Set weak and strong pixel colors
    Color weak = Color ((25.0/255.0), (25.0/255.0), (25.0/255.0), 1.0); //change alpha value?
    Color strong = Color (1.0, 1.0, 1.0, 1.0);
    Color black = Color (0.0, 0.0, 0.0, 1.0);
    
    // Loop through each pixel
    for (int i = 0; i < width; i++)
    {
		for (int j = 0; j < height; j++)
        {
            // Get pixel color
            Color pixelColor = Filtered[0]->GetPixel(i, j);

            if (pixelColor == weak)
            {
                // Get surrounding pixel colors
                Color pixelColor1 = Filtered[0]->GetPixel(i+1, j-1);
                Color pixelColor2 = Filtered[0]->GetPixel(i+1, j);
                Color pixelColor3 = Filtered[0]->GetPixel(i+1, j+1);
                Color pixelColor4 = Filtered[0]->GetPixel(i, j-1);
                Color pixelColor5 = Filtered[0]->GetPixel(i, j+1);
                Color pixelColor6 = Filtered[0]->GetPixel(i-1, j-1);
                Color pixelColor7 = Filtered[0]->GetPixel(i-1, j);
                Color pixelColor8 = Filtered[0]->GetPixel(i-1, j+1);
                // Check if surrounding pixels are strong
                if (pixelColor1 == strong || pixelColor2 == strong
                 || pixelColor3 == strong || pixelColor4 == strong
                 || pixelColor5 == strong || pixelColor6 == strong 
                 || pixelColor7 == strong || pixelColor8 == strong)
                {
                    // Set pixel color to strong
                    Filtered[0]->SetPixel(i,j, strong);
                }
                else
                {
                    // Set pixel color to black
                    Filtered[0]->SetPixel(i,j, black);
                }
            }
        }
    }
}
