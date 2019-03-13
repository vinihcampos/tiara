#ifndef _LINE_
#define _LINE_

#include "Shape.h"
#include "Color.h"
#include "Point2d.h"
#include <string>

namespace tiara{

	/**
	*	Enum that represents the line algorithm implementations
	*/
	enum LineImpl{
		DDA = 1,
		Bresenham = 2		
	};

	/**
	* Provides methods to create lines.
	* 
	* @author Vinícius Campos
	* @date 3/12/2019
	*/
	class Line : public Shape{
		private:
			Point2d p1, p2;
			Color color;
			LineImpl lineImpl;

			void dda(Canvas & canvas);
			void bresenham(Canvas & Canvas);
		public:

			/**
			*	Create an empty line.
			*/
			Line(){}
			
			/**
			*	Create a line.
			*	@param p1_ An extreme point of line.
			*	@param p2_ Another extreme point of line..
			*	@param color_ The color of line.
			*	@param lineImpl_ The algorithm used to draw the line.
			*/
			Line(Point2d p1_, Point2d p2_, const Color & color_, const LineImpl lineImpl_ = DDA);
			
			/**
			*	Create a line.
			*	@param p1_ An extreme point of line.
			*	@param p2_ Another extreme point of line..
			*	@param color_ The color of line.
			*	@param lineImpl_ The algorithm used to draw the line.
			*/
			Line(Point2d p1_, Point2d p2_, const Color & color_, const std::string & lineImpl_);
			
			/**
			*	Draws the line on canvas. 
			*	@param canvas The canvas used to draw the line.
			*/
			void draw(Canvas & canvas) override;
	};

}

#endif