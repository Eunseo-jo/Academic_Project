/**
 * @file vector3.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/ 
#include "vector3.h"

using namespace std;

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Vector3::Vector3() 
{
	x = 0.0, y = 0.0, z = 0.0;
}

Vector3::Vector3(double xVal, double yVal, double zVal)
	: x(xVal), y(yVal), z(zVal) 
{    

}

Vector3 Vector3::operator+(double val) 
{
    return Vector3(x + val, y + val, z + val);
}

Vector3 Vector3::operator+(Vector3 vec) 
{
    return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

Vector3 Vector3::operator-(double val) 
{
    return Vector3(x - val, y - val, z - val);
}

Vector3 Vector3::operator-(Vector3 vec) 
{
    return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator*(double val) 
{
    return Vector3(val*x, val*y, val*z);
}

Vector3 Vector3::operator*(Vector3 vec)
{
    return Vector3(x * vec.x, y * vec.y, z * vec.z);
}

Vector3 Vector3::operator/(double val) 
{
    return Vector3(x / val, y / val, z / val);
}

Vector3 Vector3::operator/(Vector3 vec)
{
    return Vector3(x / vec.x, y / vec.y, z / vec.z);
}

double Vector3::operator[](int idx)
{
    if(idx == 0) 
    {
        return x;
    }

    if(idx == 1)
    {
        return y;
    }

    if(idx == 2)
    {
        return z;
    }
    return -1;
}

bool Vector3::operator==(Vector3 vec)
{
    if(x==vec.x && y == vec.y && z == vec.z)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Vector3::operator!=(Vector3 vec)
{
    if(x==vec.x && y == vec.y && z == vec.z)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Vector3::Print() 
{
	cout << "[" << x << ", " << y << ", " << z << "]";
	cout << endl;
}

double Vector3::Magnitude()
{
    return sqrt(x * x + y * y + z * z);
}

void Vector3::Normalize()
{
    double mag = Magnitude();
    x = x/mag;
    y = y/mag;
    z = z/mag;
}

double * Vector3::getVector()
{
	double arr[3] = {x,y,z};
	double * array = arr;
	return array;
}
