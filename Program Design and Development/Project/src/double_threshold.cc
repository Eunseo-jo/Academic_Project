/**
 * @file double_threshold.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "double_threshold.h"

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
DoubleThresholdFilter::DoubleThresholdFilter() {}

void DoubleThresholdFilter::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{
    // Set filtered image to original
    *Filtered[0] = *Original[0];

    int width  = Original[0]->GetWidth();
    int height = Original[0]->GetHeight();

    Color lowThreshold   = Color(0.1, 0.1, 0.1, 0.1);
    Color highThreshold  = Color(0.5, 0.5, 0.5, 0.5);

    Color weak   = Color((25.0/255.0), (25.0/255.0), (25.0/255.0), 1.0);
    Color strong = Color(1.0, 1.0, 1.0, 1.0);
    Color black  = Color(0.0, 0.0, 0.0, 1.0);

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            Color pixel = Original[0]->GetPixel(i, j);

            if(pixel > highThreshold)
            {
                Filtered[0]->SetPixel(i, j, strong);
            }
            else if(pixel < lowThreshold)
            {
                Filtered[0]->SetPixel(i, j, black);
            }
            else if(pixel <= highThreshold && pixel >= lowThreshold)
            {
                Filtered[0]->SetPixel(i, j, weak);
            }
        }
    }
}
