/**
 * @file gaussian-blur.cc
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "image.h"
#include "gaussian-blur.h"
#include "kernel.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
GaussianBlur::GaussianBlur() {}

void GaussianBlur::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered)
{
    *filtered[0] = *original[0];
    int width = filtered[0]->GetWidth();
    int height = filtered[0]->GetHeight();

    int kernelSize = 5;

    Kernel GKernel = Kernel ();
    //GKernel.SetSize (kernelSize);

    GKernel.GaussianKernel(kernelSize);

    GKernel.ApplyKernel(*original[0], *filtered[0]);
}
