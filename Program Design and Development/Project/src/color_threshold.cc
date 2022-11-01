/**
 * @file color_threshold.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "color_threshold.h"
#include <cmath>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
ColorThresholdFilter::ColorThresholdFilter() {}

void ColorThresholdFilter::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{
    // Set filtered image to original
    *Filtered[0] = *Original[0];

    int width  = Original[0]->GetWidth();
    int height = Original[0]->GetHeight();

    // Color threshold: orange
    // Margins of error
    Color orange  = Color((219.0/255.0), (150.0/255.0), (35.0/255.0), 1.0);

    // Color to set pixel for new image
    Color white = Color(1.0, 1.0, 1.0, 1.0);
    Color black = Color(0.0, 0.0, 0.0, 1.0);

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            Color pixel = Original[0]->GetPixel(i, j);
            // find the margin of color
            float dist = sqrt((orange.red() - pixel.red()) * (orange.red() - pixel.red())
                            + (orange.blue() - pixel.blue()) * (orange.blue() - pixel.blue())
                            + (orange.green() - pixel.green()) * (orange.green() - pixel.green()));
            
            // 0.2 is the threshold
            if(dist < 0.2)
            {
                Filtered[0]->SetPixel(i, j, white);
            }
            else
            {
                Filtered[0]->SetPixel(i, j, black);
            }
        }
    }
}
