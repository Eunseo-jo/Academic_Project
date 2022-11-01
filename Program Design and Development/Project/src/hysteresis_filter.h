#ifndef HYSTERESIS_FILTER_H_
#define HYSTERESIS_FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include "color.h"

#include <string>
#include <vector> 

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the hysteresis filter
 */

class HysteresisFilter : public Filter
{
	public:
	/**
	 * @brief Creates a hysteresis filter object
	 * 
	 * @return Nothing
	 */
		HysteresisFilter();
	/**
	 * @brief The hysteresis filter's version of apply
	 * 
	 * @return Void
	 */
		void Apply (vector<Image*> &Original, vector<Image*> &Filtered);
};

#endif