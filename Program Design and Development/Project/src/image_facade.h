#ifndef IMAGE_FACADE_H
#define IMAGE_FACADE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "image.h"
#include "color.h"
#include "filter.h"
#include "blob_detect.h"
#include "color_threshold.h"
#include "canny_edge_detect.h"
#include "greyscale_filter.h"
#include "gaussian-blur.h"
#include "sobel.h"
#include "non_max_suppression.h"
#include "double_threshold.h"
#include "hysteresis_filter.h"
#include <string>
#include <vector>
#include <cmath>

using namespace std;
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the facade class for the Image filters
 */ 
class facade
{
    public:
        /**
        * @brief This is the constructor.
        *
        * @return No return.
        */
        facade();
        /**
        * @brief This is the deconstructor.
        *
        * @return No return.
        */
        ~facade();
        /**
        * @brief This is the funtion that apply filter on image.
        *
        * @return No return.
        */
        void ApplyFilter(Filter *filter,vector<Image*> &original, vector<Image*> &filtered); 
};

#endif
