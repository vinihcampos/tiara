#ifndef _POLYGON_
#define _POLYGON_

#include "Point2d.h"
#include "Shape.h"
#include "Canvas.h"
#include "Color.h"
#include "Edge.h"
#include <vector>
#include <map>

namespace tiara{

	/**
	* Provides methods to create polygons.
	* 
	* @author Vinícius Campos
	* @date 3/12/2019
	*/
	class Polygon : public Shape{
		private:
			Color borderColor;
			Color fillColor;

			bool border, fill;
			
			std::vector<Point2d> points;

			int miny, maxy;
			int thickness;
			std::map< int, std::vector<Edge> >  edges;
		public:
			/**
			*	Destructor of polygon.
			*/
			~Polygon();

			/**
			*	Create a polygon.
			*	@param border_ A boolean that indicates if the polygon has border.
			*	@param fill_ A boolean that indicates if the polygon has filling.
			*	@param borderColor_ The color of border.
			*	@param fillColor_ The color of filling.
			*	@param thickness_ The thickness of border.
			*/
			Polygon(bool border_ = true, bool fill_ = false, Color borderColor_ = WHITE, Color fillColor_ = WHITE, const int & thickness_ = 1);
			
			/**
			*	Create a polygon.
			*	@param points_ A list of points.
			*	@param border_ A boolean that indicates if the polygon has border.
			*	@param fill_ A boolean that indicates if the polygon has filling.
			*	@param borderColor_ The color of border.
			*	@param fillColor_ The color of filling.
			*	@param thickness_ The thickness of border.
			*/
			Polygon(std::vector<Point2d> & points_, bool border_ = true, bool fill_ = false, Color borderColor_ = WHITE, Color fillColor_ = WHITE, const int & thickness_ = 1);
			
			/**
			*	Add a point to polygon.
			*	@param point The point to be inserted in polygon.
			*/
			void add(Point2d & point);

			/**
			*	Draws the polygon on canvas. 
			*	@param canvas The canvas used to draw the polygon.
			*/
			void draw(Canvas & canvas) override;
	};
} 

#endif