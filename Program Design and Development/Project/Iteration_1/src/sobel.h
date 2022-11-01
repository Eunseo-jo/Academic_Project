#ifndef SOBEL_H_
#define SOBEL_H_

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
 * @brief This is the class for the sobel filter
 */

class Sobel : public Filter
{
    public:
        /**
        * @brief Creates a Sobel filter object
        *
        * @return Nothing
        */
        Sobel();
        /**
        * @brief Apply a Sobel filter
        *
        * @return Nothing
        */
        virtual void Apply(std::vector<Image*> &Original, std::vector<Image*> &Filtered);
};

#endif
