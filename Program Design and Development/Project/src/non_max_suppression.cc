#define _USE_MATH_DEFINES

/**
 * @file non_max_suppression.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "non_max_suppression.h"

#include <cmath>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
NonMaxSuppressionFilter::NonMaxSuppressionFilter() {}

void NonMaxSuppressionFilter::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{
    // Set filtered image to original images
    *Filtered[0] = *Original[0];
    
    // Set width and height for loop
    int width  = Original[0]->GetWidth();
    int height = Original[0]->GetHeight();

    // Set 0 and 180 angles
    Color zero = Color(0.0, 0.0, 0.0, 0.0);
    Color black = Color(0.0, 0.0, 0.0, 1.0);
    Color oneEighty = Color(180, 180, 180, 180);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Get pixel from intensity image (will use later)
            Color intensity = Original[0]->GetPixel(i, j);
            // Get pixel from direction image
            Color direction = Original[1]->GetPixel(i, j);
            
            // Determine angle of pixel by multiplying 180 and dividing pi
            Color angle = direction * 180 / M_PI;
            // if the angle is less than zero add 180
            if (angle < zero) { angle = angle + oneEighty; }

            // Placeholders for angles aside from current pixel
            Color q = Color(1.0, 1.0, 1.0, 1.0);
            Color r = Color(1.0, 1.0, 1.0, 1.0);
            
            // angle 0
            if ((angle >= zero && angle < Color(22.5, 22.5, 22.5, 22.5))
            || (angle >= Color(157.5, 157.5, 157.5, 157.5) && angle <= oneEighty))
            {
                q = Original[0]->GetPixel(i, j+1);
                r = Original[0]->GetPixel(i, j-1);
            }
            
            // angle 45
            else if (angle >= Color(22.5, 22.5, 22.5, 22.5) && angle < Color(67.5, 67.5, 67.5, 67.5))
            {
                q = Original[0]->GetPixel(i+1, j-1);
                r = Original[0]->GetPixel(i-1, j+1);
            }
            
            // angle 90
            else if (angle >= Color(67.5, 67.5, 67.5, 67.5) && angle < Color(112.5, 112.5, 112.5, 112.5))
            {
                q = Original[0]->GetPixel(i+1, j);
                r = Original[0]->GetPixel(i-1, j);
            }
            
            // angle 135
            else if (angle >= Color(112.5, 112.5, 112.5, 112.5) && angle < Color(157.5, 157.5, 157.5, 157.5))
            {
                q = Original[0]->GetPixel(i-1, j-1);
                r = Original[0]->GetPixel(i+1, j+1);
            }

            if (intensity >= q && intensity >= r)
            {
                Filtered[0]->SetPixel(i, j, intensity);
            }
            else
            {
                Filtered[0]->SetPixel(i, j, black);
            }
        }
    }
}
