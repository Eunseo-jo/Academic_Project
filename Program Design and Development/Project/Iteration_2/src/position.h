//position.h
#ifndef POSITION_H_
#define POSITION_H_


class Position 
{
public:
	Position ();
	Position (double xStart,double yStart,double zStart);
	void updatePosition ( double x, double y, double z);
private:
	double xpos;
	double ypos;
	double zpos;

};

#endif


