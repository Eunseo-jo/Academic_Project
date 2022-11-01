#ifndef KERNEL_H_
#define KERNEL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "color.h"
#include "image.h"

#include <string>
#include <cmath>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Kernel Class is used by many filters to get a small set of pixels surronding any given pixel
 */ 

class Kernel {
	public:
		/**
		* @brief Constructor for the kernel class, does nothing
		*
		* @return none
		*/ 
		Kernel();
		/**
		* @brief Destructor for the kernel class, deletes the kernel pointer
		*
		* @return none
		*/ 
		~Kernel();
		/**
		* @brief Function to set the size of the kernel all kernels must be Y by Y in size where Y is an odd number
		*
		* @return void
		*/ 
		void SetSize(int size);
		/**
		* @brief Function to find the value for the (x,y) spot of the kernel
		*
		* @return floating point value of the kernel at that spot
		*/ 
		float GetValue(int x, int y) const;
		/**
		* @brief Function to set the floating point value of the kernel at the (x, y) spot
		*
		* @return void
		*/ 
		void SetValue(int x, int y, float value);
		/**
		* @brief Function will iterate over an image and set the color of each pixel to the values of that pixels kernel object as described by the filter
		*
		* @return none, image's pixels are directly set through pointers 
		*/ 
		void ApplyKernel(const Image& original, Image& filtered) const;
		/**
		* @brief Function to set the size of the Gaussian-kernel that must be size by size
		*
		* @return none - void
		*/
		void GaussianKernel(int size);

	private:
		int size;
		float* kernel;
};

#endif
