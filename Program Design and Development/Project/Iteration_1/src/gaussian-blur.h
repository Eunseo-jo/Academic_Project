#ifndef GAUSSIAN_BLUR_H_
#define GAUSSIAN_BLUR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include "filter.h"

#include <string>
#include <vector>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the GaussianBlur filter
 */

class GaussianBlur : public Filter{
    public:
    /**
     * @brief Creates a GaussianBlur filter object
     *
     * @return Nothing
     */
        GaussianBlur();
    /**
     * @brief Apply a GaussianBlur's filter
     *
     * @return Nothing
     */
        virtual void Apply(std::vector<Image*> &Original, std::vector<Image*> &Filtered);
};

#endif