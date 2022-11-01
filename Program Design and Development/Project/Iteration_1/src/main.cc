/**
 * @file main.cc
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include "filter.h"
#include "threshold_filter.h"
#include "mean_blur_filter.h"
#include "greyscale_filter.h"
#include "sharpen.h"
#include "median_blur.h"
#include "gaussian-blur.h"
#include "sobel.h"
#include "non_max_suppression.h"
#include "double_threshold.h"
#include "hysteresis_filter.h" 
#include "canny_edge_detect.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <cmath>

using namespace std;

/*******************************************************************************
 * Main Function
 ******************************************************************************/ 
int main(int argc, const char* argv[])
{
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    string inputFile(argv[1]);
    string filterType(argv[2]);
    string outputFile(argv[3]);

    // Create available filters (unique_ptr handles dynamic memory)
    map<string, unique_ptr<Filter>> filters;
    filters["greyscale"]            = unique_ptr<Filter>(new GreyScaleFilter());
    filters["threshold"]            = unique_ptr<Filter>(new ThresholdFilter(0.5));
    filters["threshold-low"]        = unique_ptr<Filter>(new ThresholdFilter(0.25));
    filters["threshold-high"]       = unique_ptr<Filter>(new ThresholdFilter(0.75));
    filters["mean_blur"]            = unique_ptr<Filter>(new MeanBlurFilter());
    filters["sharpen"]              = unique_ptr<Filter>(new Sharpen());
    filters["median_blur"]          = unique_ptr<Filter>(new MedianBlur());
    filters["gaussian_blur"]        = unique_ptr<Filter>(new GaussianBlur());
    //filters["sobel"]                = unique_ptr<Filter>(new Sobel());
    //filters["non_max_suppression"]  = unique_ptr<Filter>(new NonMaxSuppressionFilter());
    filters["double_threshold"]     = unique_ptr<Filter>(new DoubleThresholdFilter());
    filters["hysteresis"]           = unique_ptr<Filter>(new HysteresisFilter());
    filters["canny_edge_detect"]    = unique_ptr<Filter>(new CannyEdgeDetect());
    
    // Create input and output vectors
    Image input(inputFile);
    Image output;
    vector<Image*> inputs;
    vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);

    // Apply filter based on filter type
    filters[filterType]->Apply(inputs, outputs);
    
    // Save output image
    output.SaveAs(outputFile);
}
