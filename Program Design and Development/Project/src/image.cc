/**
 * @file image.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "image.h"
#include "color.h"

#include <iostream>
#include <string>
#include <cstring>

// Needed for reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Image::Image()
{
	width = 0;
	height = 0;
	components = 4;
	pixels = NULL;
}

Image::Image(int w, int h) 
{
	width = w;
	height = h;
	components = 4;
	pixels = new unsigned char[width*height*components];
}

Image::Image(string filename)
{
	unsigned char *loadedImage = stbi_load(filename.c_str(), &width, &height, &components, STBI_rgb_alpha);
	components = 4;
	pixels = new unsigned char[width*height*components];
	copy(loadedImage, loadedImage + width*height*components, pixels); // copy allows us to copy one byte array to another
	stbi_image_free(loadedImage);
}

Image::Image(const Image &image) 
{
	pixels = NULL; 
    *this = image;
}

void Image::operator=(const Image &image) 
{
    if (pixels) 
    {
        delete[] pixels;
    }
    width = image.width;
    height = image.height;
	components = 4;
    pixels = new unsigned char[width*height*components];
    copy(image.pixels, image.pixels+width*height*components, pixels);
}

Image::~Image() 
{
    delete[] pixels;
}

void Image::SetPixel(int x, int y, Color newColor)
{
	unsigned char* pixel = &pixels[(x + width*y)*components];

    pixel[0] = newColor.red()   * 255.0;
    pixel[1] = newColor.green() * 255.0;
    pixel[2] = newColor.blue()  * 255.0;
    pixel[3] = newColor.alpha() * 255.0;
   
}

void Image::SaveAs(string filename) const
{
	stbi_write_png(filename.c_str(), width, height, components, pixels, width*components);
}

Color Image::GetPixel(int x, int y) const
{
	if (x < 0) { x = 0; }
	if (y < 0) { y = 0; }
	if (x >= width) { x = width-1; }
	if (y >= height) { y = height-1; }

    unsigned char* pixel = &pixels[(x + width*y)*components];
    
	float red   = 1.0 * pixel[0] / 255.0; // r value converted to a fraction of 255
    float green = 1.0 * pixel[1] / 255.0;
    float blue  = 1.0 * pixel[2] / 255.0;
    float alpha = 1.0 * pixel[3] / 255.0;
    
	Color pixelcolor(red, green, blue, alpha);
    
	return pixelcolor;
}

int Image::GetHeight() const
{
	return height;
}
	
int Image::GetWidth() const
{
	return width;
}

int Image::GetComponentNum() const
{
	return components;
}
