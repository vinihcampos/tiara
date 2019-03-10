#ifndef _COLOR_
#define _COLOR_

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
			void paint(const FillingImpl impl = Fill);

			channel& operator[](int idx);
			const channel& operator[](int idx) const;
			bool operator==(const Color & color) const;
	};

	/* Predefined colors*/
	static const Color BLACK;
	static const Color WHITE(255,255,255);
	static const Color TRANSPARENT(255,255,255);

}

#endif