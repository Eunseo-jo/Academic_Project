
#include "image_facade.h"

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

facade::facade()
{}
facade::~facade()
{}

void facade::ApplyFilter(Filter *filter, vector<Image*> &original, vector<Image*> &filtered) 
{
    filter->Apply(original,filtered);
}