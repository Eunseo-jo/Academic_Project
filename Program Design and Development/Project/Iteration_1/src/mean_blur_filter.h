#ifndef MEAN_BLUR_FILTER_H
#define MEAN_BLUR_FILTER_H

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <string>
#include <vector> 

#include "filter.h"
#include "color.h"
#include "kernel.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Mean Blur Filter blurs an image by taking the mean values of a 3x3 kernel for each pixel
 */

class MeanBlurFilter : public Filter
{
	public:
	/**
	  * @brief Constructor for the Mean Blur class, does nothing
	  *
	  * @return none
	*/ 
		MeanBlurFilter();
	/**
	  * @brief Apply function; creates an new image with the threshold filter on the original image
	  *
	  * @return void (image saved within the apply function)
	*/ 
		void Apply (vector<Image*> &Original, vector<Image*> &Filtered);
};

#endif
