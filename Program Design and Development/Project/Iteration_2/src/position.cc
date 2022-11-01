//position.cc
#include "position.h"
Position::Position ()
{
	xpos = 0.0; // x 
	ypos = 0.0; // y
	zpos = 0.0; // z
}

Position::Position (double xStart, double yStart, double zStart)
{
	xpos = xStart; // x 
	ypos = yStart; // y
	zpos = zStart; // z
}

void Position::updatePosition (double x, double y, double z)
{
	xpos += x; // x 
	ypos += y; // y
	zpos += z; // z
}
