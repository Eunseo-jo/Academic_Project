#ifndef DOUBLE_THRESHOLD_H_
#define DOUBLE_THRESHOLD_H_

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
 * @brief The main class for the double-threshold filter.
 */

class DoubleThresholdFilter : public Filter
{
    public:
    /**
    * @brief This is the constructor.
    *
    * @return No return.
    */
        DoubleThresholdFilter();
    /**
    * @brief This is the double-threshold version of the Apply function.
    *
    * @return Return is void.
    */
        virtual void Apply(vector<Image*> &original, vector<Image*> &filtered);
};

#endif