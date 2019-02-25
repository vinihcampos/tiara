#ifndef _POINT2D_
#define _POINT2D_

#include <string>

namespace tiara{
	class Point2d{
		public:
			int x, y;

			Point2d(int x_ = 0, int y_ = 0) : x{x_}, y{y_}{}
			Point2d(const Point2d & copy) : x{copy.x}, y{copy.y}{}

			friend bool operator==(const Point2d& lhs, const Point2d& rhs){ return lhs.x == rhs.x && lhs.y == rhs.y; }
			friend bool operator!=(const Point2d& lhs, const Point2d& rhs){ return !(lhs==rhs); }
	};
}
#endif