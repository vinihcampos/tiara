#ifndef _CANVAS_
#define _CANVAS_

#include <memory>
#include "Color.h"
#include "Point2d.h"

namespace tiara{

	class Canvas{
		private:
			typedef unsigned char component_t;
			
			size_t width, height;
			std::unique_ptr<component_t[]> canvas;
		public:
			Canvas(size_t width_, size_t height_);
			void fill(const Color color);
			size_t getWidth() const { return width; }
			size_t getHeight() const { return height; }
			Color get(const Point2d p);
			Color get(const size_t idx);
	};

}

#endif