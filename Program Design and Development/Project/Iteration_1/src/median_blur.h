#ifndef MEDIANBLUR_H
#define MEDIANBLUR_H

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include "filter.h"
#include "color.h"
#include "kernel.h"

#include <string>
#include <vector>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the Median Blur Filter
 * It blurs an image using a 3x3 kernel and sets the pixel to the median values
 */

class MedianBlur : public Filter
{
	public:
        /**
        * @brief constructor for the class
        */
        MedianBlur();
        /**
        * @brief function to apply the median blur filter to an image
        *
        * @return void
        */
        void Apply (vector<Image*> &Original, vector<Image*> &Filtered);
        /**
        * @brief median blur requires sorting the kernel values so a quickSort method is used to do so
        *
        * @return void
        */
        void quickSort (float array[], int low, int high);
        /**
        * @brief part of quickSort, seperates the kernel values for sorting
        *
        * @return partition position in the array
        */
        int partition (float array[], int low, int high);
        /**
        * @brief part of quickSort, swaps array values for sorting
        *
        * @return void
        */
        void swap (float* a, float *b);
};

#endif
