#ifndef _COLOR_
#define _COLOR_

#include <string>
#include <map>

namespace tiara{

	class Color{

		enum FillingImpl{
			Fill = 1,
			ScanLine = 2		
		};

		public:
			typedef unsigned char channel;
			channel r;
			channel g;
			channel b;

			Color(const channel r_ = 0, const channel g_ = 0, const channel b_ = 0) : r{r_}, g{g_}, b{b_} {}
			Color(const Color & color);
			Color(const std::string & color, std::map<std::string, Color> & pallete);
			void paint(const FillingImpl impl = Fill);

			channel& operator[](int idx);
			const channel& operator[](int idx) const;
			bool operator==(const Color & color) const;
	};

	/* Predefined colors*/
	static const Color BLACK;
	static const Color WHITE(255,255,255);
	static const Color YELLOW(255,255,0);
	static const Color RED(255,0,0);
	static const Color GREEN(0,255,0);
	static const Color BLUE(0,0,255);

}

#endif