/**
 * @file color.cc
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "color.h"

#include <string>

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/ 
Color::Color()
{
	r = 0.0;
	g = 0.0;
	b = 0.0;
	a = 1.0;
}

Color::Color(float red, float green, float blue, float alpha) 
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}


float Color::red() const 
{ 
	return r; 
}

float Color::green() const 
{ 
	return g; 
}

float Color::blue() const 
{ 
	return b; 
}

float Color::alpha() const 
{ 
	return a; 
}


Color Color::operator*(float value) const 
{ 
	return Color(value*r, value*g, value*b, value*a); 
}

Color Color::operator/(float value) const
{
	return Color(value/r, value/g, value/b, value/a);
}

Color Color::operator+(Color color) const 
{
	return Color(r+color.r, g+color.g, b+color.b, a+color.a); 
}

Color Color::operator-(Color color) const 
{
	return Color(r-color.r, g-color.g, b-color.b, a-color.a); 
}


bool Color::operator==(Color color) const
{
	if (r == color.r && g == color.g && b == color.b && a == color.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Color::operator>(Color color) const
{
  if (r > color.r && g > color.g && b > color.b && a > color.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Color::operator>=(Color color) const
{
  if (r >= color.r && g >= color.g && b >= color.b && a >= color.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}
  
bool Color::operator<(Color color) const
{
	if (r < color.r && g < color.g && b < color.b && a < color.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Color::operator<=(Color color) const
{
	if (r <= color.r && g <= color.g && b <= color.b && a <= color.a)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Color::setAlpha (float value)
{
	a = value;
}

float Color::GetLuminance() 
{
    return 0.2126*r + 0.7152*g + 0.0722*b;
}