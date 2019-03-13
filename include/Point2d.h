#ifndef _POINT2D_
#define _POINT2D_

#include <string>

namespace tiara{

	/**
	* Provides the entity point.
	* 
	* @author Vinícius Campos
	* @date 4/12/2019
	*/
	class Point2d{
		public:
			/**
			*	A point of X-axis.
			*/
			int x;
			/**
			*	A point of Y-axis.
			*/
			int y;

			/**
			*	Creates a point. 
			*	@param x_ A point of X-axis.
			*	@param y_ A point of Y-axis.
			*/
			Point2d(int x_ = 0, int y_ = 0) : x{x_}, y{y_}{}

			/**
			*	Creates a copy of a point. 
			*	@param copy An existing point.
			*/
			Point2d(const Point2d & copy) : x{copy.x}, y{copy.y}{}

			/**
			*	Compare the equality of two points.
			*	@param lhs left point.
			*	@param rhs right point.
			*/
			friend bool operator==(const Point2d& lhs, const Point2d& rhs){ return lhs.x == rhs.x && lhs.y == rhs.y; }
			
			/**
			*	Compare the difference of two points.
			*	@param lhs left point.
			*	@param rhs right point.
			*/
			friend bool operator!=(const Point2d& lhs, const Point2d& rhs){ return !(lhs==rhs); }
	};
}
#endif