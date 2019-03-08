#include "Polygon.h"
#include "Line.h"
#include <iostream>

tiara::Polygon::Polygon(bool border_, bool fill_, tiara::Color borderColor_, tiara::Color fillColor_){
	border = border_;
	fill = fill_;
	borderColor = borderColor_;
	fillColor = fillColor_;
}

tiara::Polygon::Polygon(std::vector<tiara::Point2d> & points_, bool border_, bool fill_, tiara::Color borderColor_, tiara::Color fillColor_){
	points = points_;
	border = border_;
	fill = fill_;
	borderColor = borderColor_;
	fillColor = fillColor_;
}

tiara::Polygon::~Polygon(){
	points.clear();
}

void tiara::Polygon::add(Point2d & point){
	points.push_back(point);
}

void tiara::Polygon::draw(Canvas & canvas){
	int size = points.size();

	for(size_t i = 0; i < size; ++i){
		if(i == size - 1){
			Line line(points[i], points[0], borderColor, Bresenham);
			line.draw(canvas);
		}else{
			Line line(points[i], points[i+1], borderColor, Bresenham);
			line.draw(canvas);
		}
	}
}