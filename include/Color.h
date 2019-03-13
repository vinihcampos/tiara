#ifndef _COLOR_
#define _COLOR_

#include <string>
#include <map>

namespace tiara{

	/**
	* Provides the entity which represents a color.
	* 
	* @author Vinícius Campos
	* @date 3/12/2019
	*/
	class Color{

		public:
			/**
			*	Type of a color channel.
			*/
			typedef unsigned char channel;

			/**
			*	The red channel.
			*/
			channel r;
			
			/**
			*	The green channel.
			*/
			channel g;
			
			/**
			*	The blue channel.
			*/
			channel b;

			/**
			*	Creates a color. 
			*	@param r_ The value of channel R from RGB.
			*	@param g_ The value of channel G from RGB.
			*	@param b_ The value of channel B from RGB.
			*/
			Color(const channel r_ = 0, const channel g_ = 0, const channel b_ = 0) : r{r_}, g{g_}, b{b_} {}

			/**
			*	Creates a color from another. 
			*	@param color A color object.
			*/
			Color(const Color & color);

			/**
			*	Creates a color from string. 
			*	@param color The name of a color.
			*	@param pallete Color pallete.
			*/
			Color(const std::string & color, std::map<std::string, Color> & pallete);

			/**
			*	Returns one of the channels
			*	@param idx The index of channel (1 = R, 2 = Green, 3 = Blue).
			*/
			channel& operator[](int idx);
			
			/**
			*	Returns one of the channels
			*	@param idx The index of channel (1 = R, 2 = Green, 3 = Blue).
			*/
			const channel& operator[](int idx) const;
			
			/**
			*	Compare two colors
			*	@param color Another color to be compared.
			*/
			bool operator==(const Color & color) const;
	};

	/* Predefined colors*/
	static const Color BLACK;
	static const Color WHITE = tiara::Color(255,255,255);
	static const Color RED = tiara::Color(255,0,0);
	static const Color GREEN = tiara::Color(0,255,0);
	static const Color BLUE = tiara::Color(0,0,255);
	static const Color YELLOW = tiara::Color(255,255,0);

}

#endif