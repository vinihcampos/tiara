#ifndef _LINE_
#define _LINE_

#include "Shape.h"
#include "Color.h"
#include "Point2d.h"

namespace tiara{

	enum LineImpl{
		DDA = 1,
		Bresenham = 2		
	};

	class Line : public Shape{
		private:
			Point2d p1, p2;
			Color color;
			LineImpl lineImpl;

			void dda(Canvas & canvas);
			void bresenham(Canvas & Canvas);
		public:

			Line(){}
			Line(Point2d p1_, Point2d p2_, const Color & color_, const tiara::LineImpl lineImpl_ = DDA);
			void draw(Canvas & canvas) override;
	};

}

#endif