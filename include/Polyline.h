#ifndef _POLYLINE_
#define _POLYLINE_

#include "Point2d.h"
#include "Shape.h"
#include "Canvas.h"
#include "Color.h"
#include <vector>

namespace tiara{

	class Polyline : public Shape{
		private:
			Color color;
			std::vector<Point2d> points;
			int thickness;
		public:
			~Polyline();
			Polyline(Color color_ = WHITE, const int & thickness_ = 1);
			Polyline(std::vector<Point2d> & points_, Color color_ = WHITE, const int & thickness_ = 1);
			void add(Point2d & point);
			void draw(Canvas & canvas) override;
	};
} 

#endif