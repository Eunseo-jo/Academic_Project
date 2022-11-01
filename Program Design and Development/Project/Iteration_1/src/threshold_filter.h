#ifndef THRESHOLD_FILTER_H_
#define THRESHOLD_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "filter.h"
#include "color.h"

#include <string>
#include <vector> 

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Threshold Filter sets each pixel to black or white based on the given threshold value                      
 */ 

class ThresholdFilter : public Filter
{
	private:
		float threshold;
	
	public:
		/**
		  * @brief Constructor for the Threshold class, does nothing
		  *
		  * @return none
		*/ 
		ThresholdFilter();
		/**
		* @brief Constructor for the Threshold class, that sets the threshold value to the provided input
		*
		* @return none
		*/ 
		ThresholdFilter(float thresholdVal);
		/**
		* @brief Apply function; creates an new image with the greyscale filter on the original image
		*
		* @return void (image saved within the apply function)
		*/
		void Apply(vector<Image*> &Original, vector<Image*> &Filtered);
};

#endif
