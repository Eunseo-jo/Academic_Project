/**
 * @file kernel.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "kernel.h"

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
Kernel::Kernel() 
{
	size = 0;
	kernel = NULL; 
}

Kernel::~Kernel() 
{
    if (kernel)
    {
        delete[] kernel;
    }
}

void Kernel::SetSize(int newSize) {
    size = newSize;
    if (kernel) // delete current kernel and reset with new size
    {
        delete[] kernel;
    }

    kernel = new float[size*size];
}

float Kernel::GetValue(int x, int y) const 
{
    return kernel[x + size*y]; // will return the value at point (x,y)
}

void Kernel::SetValue(int x, int y, float value) 
{
    kernel[x + size*y] = value; // set kernel at (x,y) to value
}

void Kernel::ApplyKernel(const Image& Original, Image& Filtered) const 
{
    int width  = Original.GetWidth();
    int height = Original.GetHeight();
    
    for (int x = 0; x < width; x++) 
    {
        for (int y = 0; y < height; y++) 
        {
            Color pixelColor(0.0, 0.0, 0.0, 1.0);
           
            int beginning = -size/2; //start at the pixel that is half the size value behind the pixel being considered
            int end = size/2; // end at the pixel that is half the size value ahead of the pixel being considered
            for (int i = beginning; i <= end; i++) 
            {
                for (int j = beginning; j <= end; j++) 
                {
                    pixelColor = pixelColor + Original.GetPixel(x+i, y+j) * GetValue(i+size/2, j+size/2); // sum of current kernel values + the pixel * its kernel value
                }
            }

            // check whether each rgb color is less than 0 or greater than 1
            if (pixelColor.red() < 0.0 || pixelColor.red() > 1.0) {
                pixelColor = Color(0.0, pixelColor.green(), pixelColor.blue(), 1.0);
            }
            if (pixelColor.green() < 0.0 || pixelColor.green() > 1.0) {
                pixelColor = Color(pixelColor.red(), 0.0, pixelColor.blue(), 1.0);
            }
            if (pixelColor.blue() < 0.0 || pixelColor.blue() > 1.0) {
                pixelColor = Color(pixelColor.red(), pixelColor.green(), 0.0, 1.0);
            }
            // set alpha value to 1
            pixelColor = Color(pixelColor.red(), pixelColor.green(), pixelColor.blue(), 1.0);

            Filtered.SetPixel(x, y, pixelColor);
        }
    }
}


void Kernel::GaussianKernel(int size) // generating 5x5 kernel
{
    float sigma = 2.0;
    float s = 2.0 * sigma * sigma;

    // sum is for normalization
    float sum = 0.0;
    float kernelValue = 0;
    SetSize(size);
        
    for (int x = 0; x < 5; x++)
    {
        for (int y =  0; y < 5; y++)
        {
            float r = sqrt(x * x + y * y);
            float kernelValue = (exp(-(r * r) / s)) / (M_PI * s);
           
            SetValue(x, y, kernelValue);
            sum = sum + kernelValue;   
        }
    }

    // normalising the Kernel
    for (int x = 0; x < size; x++)
    {
        for (int y =  0; y < size; y++)
        {
            float kValue = GetValue(x, y)/sum;
            SetValue(x, y, kValue);
        }
    }
}
