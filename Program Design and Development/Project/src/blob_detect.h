#ifndef BLOB_DETECT_H_
#define BLOB_DETECT_H_

/*******************************************************************************
* Includes
******************************************************************************/
#include "filter.h"
#include "color.h"
#include "color_threshold.h"
#include "canny_edge_detect.h"
#include <vector>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the blob detect filter.
 */
class BlobDetect : public Filter
{
    public:
        /**
        * @brief Creates a blob detect object.
        *
        * @return No return.
        */
        BlobDetect();
        /**
        * @brief This is the blob detect version of the Apply function.
        *
        * @return Return is void.
        */
        void Apply(vector<Image*> &original, vector<Image*> &filtered);
};

#endif