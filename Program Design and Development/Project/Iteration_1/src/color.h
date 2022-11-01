#ifndef COLOR_H_
#define COLOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/ 
#include <string>

using namespace std;

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The color class stores the rgba values of each pixel
 */

class Color 
{
	private:
		float r, g, b, a;
	public:
		/**
		  * @brief Constructor for the color class, auto sets rgb to 0.0 and a to 1.0 (will make a all black pixel)
		  *
		  * @return none
		*/ 
		Color();
		/**
		  * @brief Constructor for the color class, sets rgba to the provided values
		  *
		  * @return none
		*/ 
		Color(float red, float green, float blue, float alpha);

		/**
		  * @brief Function to find the red value of the pixel
		  *
		  * @return floating point value of the red portion of the pixel
		*/
		float red() const;
		/**
		  * @brief Function to find the green value of the pixel
		  *
		  * @return floating point value of the green portion of the pixel
		*/
		float green() const;
		/**
		  * @brief Function to find the blue value of the pixel
		  *
		  * @return floating point value of the blue portion of the pixel
		*/
		float blue() const;
		/**
		  * @brief Function to find the alpha (transparency) value of the pixel
		  *
		  * @return floating point value of the alpha (transparency) portion of the pixel
		*/
		float alpha() const;

		/**
		  * @brief Multiply operator overload, will multiply each of the rgba values by the provided val
		  * 
		  * @return updated color object
		*/ 
		Color operator*(float value) const;
		/**
		  * @brief Division operator overload, will divide each of the rgba values by the provided color's rgba values
		  *
		  * @return updated color object
		*/
		Color operator/(float value) const;
		/**
		  * @brief Addition operator overload, will add each of the rgba values by the provided color's rgba values
		  * 
		  * @return updated color object
		*/ 
		Color operator+(Color color) const;
		/**
		  * @brief Subtraction operator overload, will subtract each of the rgba values by the provided color's rgba values
		  * 
		  * @return updated color object
		*/ 
		Color operator-(Color color) const;

		/**
		  * @brief Equality operator overload
		  *
		  * @return boolean of true if == and false if not
		*/ 
   		bool operator==(Color color) const;
    	/**
		  * @brief Greater Than Equal To operator overload
		  *
		  * @return boolean of true if >= and false if not
		*/ 
		bool operator>=(Color color) const;
    	/**
		  * @brief Less Than operator overload
		  *
		  * @return boolean of true if < and false if not
		*/ 
		bool operator<(Color color) const;
    	/**
		  * @brief Less Than Equal To operator overload
		  *
		  * @return boolean of true if <= and false if not
		*/ 
		bool operator<=(Color color) const;

		/**
		  * @brief Function will change the alpha value of the color class to the new provided floating point value
		  *
		  * @return void 
		*/
		void setAlpha (float value);
		/**
		  * @brief Function to find the Luminance value of the pixel by caluculating 0.2126*r + 0.7152*g + 0.0722*b 
		  *
		  * @return floating point value of the luminance of the pixel
		*/ 
		float GetLuminance();
};

#endif
