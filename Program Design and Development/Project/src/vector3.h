#ifndef VECTOR3_H_
#define VECTOR3_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <math.h>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This is the class for the Vector3 type
 */
class Vector3 
{
	public:
		/**
		* @brief Creates a Vector3 object (0.0, 0.0, 0.0)
		* 
		* @return Nothing
		*/
		Vector3();

		/**
		* @brief Creates a Vector3 object with specified values
		* 
		* @return Nothing
		*/
		Vector3(double xVal, double yVal, double zVal);

		/**
		* @brief Adds to a Vector3 object
		* 
		* @return a Vector3
		*/
		Vector3 operator+(double val);

		/**
		* @brief Adds two Vector3 objects
		* 
		* @return a Vector3
		*/
		Vector3 operator+(Vector3 vec);

		/**
		* @brief Subtracts from a Vector3 object
		* 
		* @return a Vector3
		*/
		Vector3 operator-(double val);

		/**
		* @brief Subtracts two Vector3 objects
		* 
		* @return a Vector3
		*/
		Vector3 operator-(Vector3 vec);

		/**
		* @brief Multiplies a Vector3 object by a specified amount
		* 
		* @return a Vector3
		*/
		Vector3 operator*(double val);

		/**
		* @brief Multiplies two Vector3 objects
		* 
		* @return a Vector3
		*/
		Vector3 operator*(Vector3 vec);

		/**
		* @brief Divides a Vector3 object by a specified amount
		* 
		* @return a Vector3
		*/
		Vector3 operator/(double val);

		/**
		* @brief Divides two Vector3 objects
		* 
		* @return a Vector3
		*/
		Vector3 operator/(Vector3 vec);

		/**
		* @brief This lets a Vector3 object be accessed with brackets []
		* 
		* @return a double of the specified index
		*/
		double operator[](int idx);

		/**
		* @brief This is the equality check operator for Vector3
		* 
		* @return boolean
		*/
		bool operator==(Vector3 vec);

		/**
		* @brief This is the not equal to check operator for Vector3
		* 
		* @return boolean
		*/
		bool operator!=(Vector3 vec);

		/**
		* @brief Prints a Vector3 object
		* 
		* @return Void
		*/
		void Print();

		/**
		* @brief This calculates the magnitude
		* 
		* @return double
		*/
		double Magnitude();

		/**
		* @brief Normalize a Vector3
		* 
		* @return Void
		*/
		void Normalize();
		/**
		* @brief GetVector returns an array of the elements
		* 
		* @return double array of the elements
		*/
		double * getVector ();

	private:
		double x, y, z;
};

#endif
