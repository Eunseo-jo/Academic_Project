#ifndef SHARPEN_H
#define SHARPEN_H

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
 * @brief The class for the shapren filter.
 * It takes an image and applys a 3x3 kernel where the kerenel values are {[0,-0.5,0][-0.5,3,-0.5][0,-0.5,0]}
 * This emphasizes the edges of an image to make it appear more clear
 */

class Sharpen : public Filter
{
	public:
	/**
       * @brief constructor for sharpen filter (does nothing)
       */
	       Sharpen();
	/**
       * @brief applys the sharpen filter to an image
       */
	       void Apply(vector<Image*> &Original, vector<Image*> &Filtered);
};

#endif
