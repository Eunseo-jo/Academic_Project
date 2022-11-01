/**
 * @file blob_detect.cc
 */
/*******************************************************************************
* Includes
******************************************************************************/
#include "blob_detect.h"
#include <memory>

using namespace std;
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
BlobDetect::BlobDetect() {}

void BlobDetect::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{
    // Copy original image to filtered
    *Filtered[0] = *Original[0];

    // Color Threshold Filter
    unique_ptr<Filter> ColorT = unique_ptr<Filter>(new ColorThresholdFilter());
    ColorT->Apply(Original, Filtered);

    // Canny Edge Detect
    *Original[0] = *Filtered[0];
    unique_ptr<Filter> Canny = unique_ptr<Filter>(new CannyEdgeDetect());
    Canny->Apply(Original, Filtered);
}