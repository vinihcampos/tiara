#include "Line.h"
#include "Point2d.h"
#include "math.h"
#include <iostream>

tiara::Line::Line(Point2d p1_, Point2d p2_, const Color & color_, const tiara::LineImpl lineImpl_){
	p1 = p1_;
	p2 = p2_;

	color = color_;
	lineImpl = lineImpl_;
}

void tiara::Line::draw(Canvas & canvas){
	switch(lineImpl){
		case DDA:
			dda(canvas);
			break;
		default:
			dda(canvas);
			break;
	}
}

void tiara::Line::dda(Canvas & canvas){
	float dx, dy, mx, my;

	dy = p2.y - p1.y;
	dx = p2.x - p1.x;

	if(dx == 0){
		size_t max_y = std::max(p1.y,p2.y);
		for(size_t y = std::min(p1.y,p2.y); y <= max_y; ++y){
			canvas.pixel(Point2d(p1.x, y), color);
		}
		return;
	}

	int iterations;

	if(std::abs(dy) > std::abs(dx))
		iterations = std::abs(dy);
	else
		iterations = std::abs(dx);

	my = dy/((1.0)*iterations);
	mx = dx/((1.0)*iterations);

	float x = p1.x;
	float y = p1.y;

	for(int i = 0; i <= iterations; ++i){		
		canvas.pixel(Point2d(std::round(x), std::round(y)), color);
		x += mx;
		y += my;
	}

}