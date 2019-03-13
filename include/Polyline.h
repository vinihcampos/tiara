#ifndef _POLYLINE_
#define _POLYLINE_

#include "Point2d.h"
#include "Shape.h"
#include "Canvas.h"
#include "Color.h"
#include <vector>

namespace tiara{

	/**
	* Provides methods to create polylines.
	* 
	* @author Vinícius Campos
	* @date 3/12/2019
	*/
	class Polyline : public Shape{
		private:
			Color color;
			std::vector<Point2d> points;
			int thickness;
		public:
			/**
			*	Destructor of polyline.
			*/
			~Polyline();
			/**
			*	Create a polyline.
			*	@param color_ The color of border.
			*	@param thickness_ The thickness of border.
			*/
			Polyline(Color color_ = WHITE, const int & thickness_ = 1);
			/**
			*	Create a polyline.
			*	@param points_ A list of points.
			*	@param color_ The color of border.
			*	@param thickness_ The thickness of border.
			*/
			Polyline(std::vector<Point2d> & points_, Color color_ = WHITE, const int & thickness_ = 1);
			/**
			*	Add a point to polyline.
			*	@param point The point to be inserted in polyline.
			*/
			void add(Point2d & point);
			/**
			*	Draws the polyline on canvas. 
			*	@param canvas The canvas used to draw the polyline.
			*/
			void draw(Canvas & canvas) override;
	};
} 

#endif