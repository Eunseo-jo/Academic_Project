#ifndef CANNY_EDGE_DETECT_H_
#define CANNY_EDGE_DETECT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include "color.h"
#include "greyscale_filter.h"
#include "gaussian-blur.h"
#include "sobel.h"
#include "non_max_suppression.h"
#include "double_threshold.h"
#include "hysteresis_filter.h"

#include <string>
#include <vector>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the canny edge detect filter
 */

class CannyEdgeDetect:public Filter
{
    public:
    /**
	 * @brief Creates a canny edge detect object
	 * 
	 * @return Nothing
	 */
    	CannyEdgeDetect();
    /**
	 * @brief The canny edge detect version of apply
	 * 
	 * @return Void
	 */
    	void Apply (vector<Image*> &Original, vector<Image*> &Filtered);
};

#endif