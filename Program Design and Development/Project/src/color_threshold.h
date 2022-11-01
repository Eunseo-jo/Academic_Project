#ifndef COLOR_THRESHOLD_H
#define COLOR_THRESHOLD_H

/*******************************************************************************
* Includes
******************************************************************************/
#include "filter.h"
#include "color.h"
#include <vector>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the color threshold filter.
 */

class ColorThresholdFilter : public Filter
{
    public:
    /**
    * @brief This is the constructor.
    *
    * @return No return.
    */
        ColorThresholdFilter();
    /**
    * @brief This is the color threshold version of the Apply function.
    *
    * @return Return is void.
    */
        virtual void Apply(vector<Image*> &Original, vector<Image*> &Filtered);
};

#endif
