#ifndef NON_MAX_SUPPRESSION_H_
#define NON_MAX_SUPPRESSION_H_

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
 * @brief The main class for the non-max-suppresion filter.
 */

class NonMaxSuppressionFilter : public Filter
{
    public:
    /**
    * @brief This is the constructor.
    *
    * @return No return.
    */
        NonMaxSuppressionFilter();
    /**
    * @brief This is the Non-max-suppression version of the Apply function.
    *
    * @return Return is void.
    */
        virtual void Apply(vector<Image*> &Original, vector<Image*> &Filtered);
};

#endif
