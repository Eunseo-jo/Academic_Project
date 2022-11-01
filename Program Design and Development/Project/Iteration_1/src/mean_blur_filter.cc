/**
 * @file mean_blur_filter.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "mean_blur_filter.h"

#include <iostream>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
MeanBlurFilter::MeanBlurFilter() {}

void MeanBlurFilter::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{	
	*Filtered[0] = *Original[0];

	int width = Filtered[0]->GetWidth();
	int height = Filtered[0]->GetHeight();
	
	int kernelSize = 3;
	Kernel mean_blur_kernel = Kernel ();

	mean_blur_kernel.SetSize (kernelSize);

	float meanDivisor = 1.0/9.0;

	for (int i = 0; i < kernelSize; i++)
	{
		for (int j= 0; j <kernelSize; j++)
		{
			mean_blur_kernel.SetValue(i, j, meanDivisor);
		}
	}

	mean_blur_kernel. ApplyKernel(*Original[0], *Filtered[0]);
}
