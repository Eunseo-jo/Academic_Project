/**
 * @file sobel.cc
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include "color.h"
#include "sobel.h"
#include "kernel.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Sobel::Sobel() {}

void Sobel::Apply(std::vector<Image*> &Original, std::vector<Image*> &Filtered)
{
    // Set Filtered image to Original
    *Filtered[0] = *Original[0];
    *Filtered[1] = *Original[0];
    
    // Filtered.push_back(Original[0]);
    
    // Assign width and height of the image
    int width  = Original[0]->GetWidth();
    int height = Original[0]->GetHeight();

    // int kernel_size = 3;
    int size = 3;

    // Assign kernel_x, amd kernel_y
    float kernel_x[3][3] = {1.0, 2.0, 1.0, 0.0, 0.0, 0.0, -1.0, -2.0, -1.0};
    float kernel_y[3][3] = {1.0, 0.0, -1.0, 2.0, 0.0, -2.0, 1.0, 0.0, -1.0};
    
    // Initialize Sobel Kernel and set kernel size
    Kernel SobelKernel_X;
    Kernel SobelKernel_Y;
    
    SobelKernel_X.SetSize(size);
    SobelKernel_Y.SetSize(size);

    // Set kernel value
    for (int x = 0; x < size; x ++){
        for(int y = 0; y < size; y++)
        {
            SobelKernel_X.SetValue(x, y, kernel_x[x][y]);
            SobelKernel_Y.SetValue(x, y, kernel_y[x][y]);
        }
    }

    // Initialize image
    Image Ix = *Original[0];
    Image Iy = *Original[0];

    // Apply kernel x and y to image
    SobelKernel_X.ApplyKernel(*Original[0], Ix);
    SobelKernel_Y.ApplyKernel(*Original[0], Iy);

    //Ix.SaveAs("data/statue_Ix.png");
    //Iy.SaveAs("data/statue_Iy.png");
     
    // Set pixel
    for (int i = 0 ; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // Calcultate sqrt(x^2 + y^2)
            // hypot(Ix, Iy)
            float red   = sqrt(Ix.GetPixel(i, j).red()   * Ix.GetPixel(i, j).red()   + Iy.GetPixel(i, j).red()   * Iy.GetPixel(i, j).red());
            float green = sqrt(Ix.GetPixel(i, j).green() * Ix.GetPixel(i, j).green() + Iy.GetPixel(i, j).green() * Iy.GetPixel(i, j).green());
            float blue  = sqrt(Ix.GetPixel(i, j).blue()  * Ix.GetPixel(i, j).blue()  + Iy.GetPixel(i, j).blue()  * Iy.GetPixel(i, j).blue());
            float alpha = sqrt(Ix.GetPixel(i, j).alpha() * Ix.GetPixel(i, j).alpha() + Iy.GetPixel(i, j).alpha() * Iy.GetPixel(i, j).alpha());

            if (alpha < 0.0 || alpha > 1.0)
            {
                alpha = 1.0;
            }

            // Apply new pixel to Filtered image
            Color sobel(red, green, blue, alpha);
            Filtered[0]->SetPixel(i, j, sobel);

            // Calcultate arctan2(Iy, Ix)
            float Ared   = atan2(Iy.GetPixel(i, j).red()  , Ix.GetPixel(i, j).red());
            float Agreen = atan2(Iy.GetPixel(i, j).green(), Ix.GetPixel(i, j).green());
            float Ablue  = atan2(Iy.GetPixel(i, j).blue() , Ix.GetPixel(i, j).blue());
            float Aalpha = atan2(Iy.GetPixel(i, j).alpha(), Ix.GetPixel(i, j).alpha());

            // Apply new pixel to Filtered image
            Color sobelAtan(Ared, Agreen, Ablue, Aalpha);
            Filtered[1]->SetPixel(i, j, sobelAtan);
        }
    }
    
    //Filtered[0]->SaveAs("data/sobel_intensity.png");
    //Filtered[1]->SaveAs("data/sobel_direction.png");
}
