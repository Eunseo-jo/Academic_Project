#ifndef IMAGE_H_
#define IMAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "color.h"

#include <string>
#include <cstring>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Image class, used for creating image objects which have heights, widths, and an array of pixels
 */ 

class Image
{
	private:
		int height;
		int width; 
		int components; // num components in pixel (rgba)
		unsigned char* pixels; // array of pixels in the image each pixel has 4 vaules, rgba

	public:
		/**
		* @brief Default Constructor for the image class, creates a 0x0 image
		*
		* @return none
		*/ 
		Image(); // default constructor makes 0x0 image
		/**
		* @brief Constructor for the that takes in a filename and creates an image based on the file given
		*
		* @return none
		*/ 
		Image(string filename); // constructor for importing an image from a file
		/**
		* @brief Constructor for the image class, creates a blank image with the provided height and width
		* 
		* @return none
		*/ 
		Image(int w, int h); // constructor for image of width and height
		/**
		* @brief Copy Constructor for the image class
		* 
		* @return none
		*/ 
		Image(const Image &image); // copy constructor
		/**
		* @brief Destructor for the image class, erases the pixel array from the heap
		* 
		* @return none
		*/ 
		~Image(); // destructor 
		/**
		* @brief Equals operator overload, part of big 3 for images
		* 
		* @return void
		*/ 
		void operator=(const Image &image); // copy assignment
		/**
		* @brief Function will save the current image object to the provided filename
		* 
		* @return void
		*/ 
		void SaveAs(string filename) const; // saves image to given file
		/**
		* @brief Function  takes a 2D pixel postion (x,y) and a color object for the pixel to be changed to and changes the rgba color vaules of that pixel to the newColor values
		* 
		* @return void
		*/ 
		void SetPixel(int x, int y, Color newColor); // sets a given pixel in the image to the value of pixel
		/**
		* @brief Function will return the Color object class of the pixel at (x,y) for the image. Color class has rgba values for the pixel
		* 
		* @return new Color object for the pixel
		*/ 
		Color GetPixel(int x, int y) const; // returns the rgba color class of the given pixel
		/**
		* @brief Funtion will find the value of the total height of image object
		* 
		* @return integer value of the height of the image
		*/ 
		int GetHeight() const; // returns height of the image
		/**
		* @brief Funtion will find the value of the total width of image object
		* 
		* @return integer value of the width of the image
		*/
		int GetWidth() const; // returns width of the image
		/**
		* @brief Funtion will find the number of components in image currently hard coded to 4 for all images (components are rgba)
		* 
		* @return integer value of the number of components in the image (4)
		*/
		int GetComponentNum() const; // returns num of components in the image rgba (currently always 4)
		//Image operator[] (int index) const;
};

#endif
