/**
 * @file sharpen.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "sharpen.h"

#include <iostream>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Sharpen::Sharpen() {}

void Sharpen::Apply(vector<Image*> &Original, vector<Image*> &Filtered)
{
	*Filtered[0] = *Original[0];

	int width = Filtered[0]->GetWidth();
	int height = Filtered[0]->GetHeight();
	int kernelSize = 3;
	Kernel sharpen_kernel = Kernel ();

	sharpen_kernel.SetSize (kernelSize);

	float corners = 0.0;
	float sides = -0.5;
	float center = 3.0;

	for (int i = 0; i < kernelSize; i++)
	{
		for (int j= 0; j <kernelSize; j++)
		{
			if ( i == kernelSize/2 && j == kernelSize/2)
			{
				sharpen_kernel.SetValue(i, j, center);
			}
			else if ( i == kernelSize/2 || j == kernelSize/2)
			{
				sharpen_kernel.SetValue(i, j, sides);
			}
			else
			{
				sharpen_kernel.SetValue(i, j, corners);
			}
		}
	}

	sharpen_kernel.ApplyKernel(*Original[0], *Filtered[0]);
}
