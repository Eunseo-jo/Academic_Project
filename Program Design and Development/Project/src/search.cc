// search.cc
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "search.h"
#include "color.h"

using namespace std;

// Search::Search() {}

bool Search::FindRobot()
{
    // move drone with movement class and take pictures

    // use pictures to apply filters
    // color threshold filter
    Filter *color_threshold = new ColorThresholdFilter();

    // Create input and output vectors
    facade image_facade;
    Image input("data/test.png");
    Image output;
    vector<Image*> inputs;
    vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);

    // Apply filter using image facade
    image_facade.ApplyFilter(color_threshold, inputs, outputs);
    
    // Save output image
    output.SaveAs("data/color_result.png");

    int width  = output.GetWidth();
    int height = output.GetHeight();

    // initialize white
    Color white = Color(1.0, 1.0, 1.0, 1.0);
    
    // count number of white pixels in both images
    // variable that will count number of white pixels in color threshold image
    float whitePixels_CT = 0;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            Color pixel = output.GetPixel(i, j);

            if(pixel == white)
            {
                whitePixels_CT++;
            }
        }
    }

    // blob detect filter
    Filter *canny_detect = new CannyEdgeDetect();
    
    // Create input and output vectors
    Image inputCanny("data/color_result.png");
    Image outputCanny;
    vector<Image*> inputsCanny;
    vector<Image*> outputsCanny;
    inputsCanny.push_back(&inputCanny);
    outputsCanny.push_back(&outputCanny);

    // Apply filter using image facade
    image_facade.ApplyFilter(canny_detect, inputsCanny, outputsCanny);
    
    // Save output image
    outputCanny.SaveAs("data/canny_result.png");

    width  = outputCanny.GetWidth();
    height = outputCanny.GetHeight();

    // variable that will count number of white pixels in canny edge detect image
    float whitePixels_CED = 0;
    
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            Color pixel = outputCanny.GetPixel(i, j);

            if(pixel == white)
            {
                whitePixels_CED++;
            }
        }
    }

    float ratio = whitePixels_CT/whitePixels_CED;

    if (ratio > 10.0)
    {
        return true;
    }
    else {return false;}

    // figure out position with rgba
    // ------------------------------------------------------------
    // DirVec = (<R, G, B> - <0.5, 0.5, 0.5>) * 2.0
    // Distance = (1.0 - |DirVec|) * 50.0
    // Direction = DirVec/|DirVec|
    // PixelLocation = CameraPosition + (distance * direction);
    //                 ^^ this is provided
}
