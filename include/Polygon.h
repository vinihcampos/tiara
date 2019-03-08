#ifndef _POLYGON_
#define _POLYGON_

#include "Point2d.h"
#include "Shape.h"
#include "Canvas.h"
#include "Color.h"
#include <vector>

namespace tiara{

	class Polygon : public Shape{
		private:
			Color borderColor;
			Color fillColor;
			bool border, fill;
			std::vector<Point2d> points;
		public:
			~Polygon();
			Polygon(bool border_ = true, bool fill_ = false, Color borderColor_ = WHITE, Color fillColor_ = WHITE);
			Polygon(std::vector<Point2d> & points_, bool border_ = true, bool fill_ = false, Color borderColor_ = WHITE, Color fillColor_ = WHITE);
			void add(Point2d & point);
			void draw(Canvas & canvas) override;
	};
} 

#endif