#ifndef FILTER_H_
#define FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <string>
#include <vector>

#include "image.h"
#include "color.h"

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The Super Class to all of the filters
 */ 

class Filter
{
	public:
	/**
	  * @brief Virtual Apply function for all filters. This is how the filters are added to the images.
	  *
	  * @return void (image saved within the apply functions)
	*/ 
	virtual void Apply(vector<Image*> &Original, vector<Image*> &Filtered) = 0;
};

#endif
