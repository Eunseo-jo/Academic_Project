/**
 * @file canny_edge_detect.cc
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "canny_edge_detect.h"
#include <memory>
#include <iostream>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
CannyEdgeDetect::CannyEdgeDetect() {}

void CannyEdgeDetect::Apply (vector<Image*> &Original, vector<Image*> &Filtered)
{
    // Copy original image to filtered
    *Filtered[0] = *Original[0];

    Image output2, input2, temp;

    // Greyscale filter
    unique_ptr<Filter> Grey = unique_ptr<Filter>(new GreyScaleFilter()); // Create filter object
    Grey->Apply(Original, Filtered);  // Apply the filter

    // Gaussian blur filter
    *Original[0] = *Filtered[0];  // Set output of previous filter to the new input
    unique_ptr<Filter> Gaussian = unique_ptr<Filter>(new GaussianBlur());
    Gaussian->Apply(Original, Filtered);

    // Sobel filter
    *Original[0] = *Filtered[0];
    Filtered.push_back(&output2);
    unique_ptr<Filter> Sobelf = unique_ptr<Filter>(new Sobel());
    Sobelf->Apply(Original, Filtered);

    // Non-max suppression filter
    *Original[0] = *Filtered[0];
    Original.push_back(&input2);
    *Original[1] = *Filtered[1];
    unique_ptr<Filter> NonMax = unique_ptr<Filter>(new NonMaxSuppressionFilter());
    NonMax->Apply(Original, Filtered);

    // Double threshold filter
    *Original[0] = *Filtered[0];
    unique_ptr<Filter> Double = unique_ptr<Filter>(new DoubleThresholdFilter());
    Double->Apply(Original, Filtered);

    // Hysteresis filter
    *Original[0] = *Filtered[0];
    unique_ptr<Filter> Hysteresis = unique_ptr<Filter>(new HysteresisFilter());
    Hysteresis->Apply(Original, Filtered);
}
