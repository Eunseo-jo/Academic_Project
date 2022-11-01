#ifndef GREYSCALEFILTER_H_
#define GREYSCALEFILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <string>
#include <vector> 

#include "filter.h"
#include "color.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Greyscale filter, uses luminance to grey out an image
 */

class GreyScaleFilter : public Filter
{
	public:
	/**
	  * @brief Constructor for the greyscale filter class, does nothing
	  *
	  * @return none
	*/ 
		GreyScaleFilter();
	
	/**
	  * @brief Apply function; creates an new image with the greyscale filter on the original image
	  *
	  * @return void (image saved within the apply function)
	*/ 
		void Apply (vector<Image*> &Orignial, vector<Image*> &Filtered);
		

};

#endif
