#ifndef _CANVAS_
#define _CANVAS_

#include <memory>
#include <string>
#include "Color.h"
#include "Point2d.h"

namespace tiara{
	
	typedef unsigned char component_t;

	class Canvas{
		private:			
			size_t width, height;
			std::unique_ptr<component_t[]> canvas;

			float kernel[3][3] = { {1,2,1}, 
			                       {2,4,2}, 
			                       {1,2,1} };

			float * multiply(int sh, int sw, int fh, int fw);

		public:
			Canvas(size_t width_, size_t height_, float norm = 1/16.0);
			size_t getWidth() const { return width; }
			size_t getHeight() const { return height; }
			Color get(const Point2d & p) const;
			Color get(const size_t & idx) const;

			/* Fill background wih specific color */
			void fill(const Color & color);
			/* Paint a specific pixel */
			void pixel(const Point2d & p, const Color & color);
			/* Paint a set of pixels */
			void pixels(const Point2d ps[], const size_t & p_size, const Color & color);
			/* Paint a square by top-left and bottom-right corners */
			void rectangle(const Point2d & tl, const Point2d & br, const Color & color, const bool filled);
			/* Apply antialiasing */
			void antialiasing();
	};

}

#endif