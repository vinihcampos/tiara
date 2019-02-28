#ifndef _ARC_
#define _ARC_

#include "Shape.h"
#include "Color.h"
#include "Point2d.h"

namespace tiara{

	const float PI = 3.14159265;

	class Arc : public Shape{
		private:
			Point2d center;
			float radius;
			float start_angle, final_angle;
			Color color;

			float cosine(Point2d p, Point2d q);
		public:
			Arc(const Point2d center_, const float & radius_, const Color & color_ = WHITE, const float & start_angle_ = 0, const float & final_angle_ = 360);
			void draw(Canvas & canvas) override;
	};
}

#endif