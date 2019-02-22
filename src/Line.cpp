#include "Line.h"
#include "Point2d.h"
#include "math.h"
#include <iostream>

tiara::Line::Line(int x1_, int y1_, int x2_, int y2_, const Color & color_, const tiara::LineImpl lineImpl_){
	x1 = x1_;
	x2 = x2_;
	y1 = y1_;
	y2 = y2_;

	color = color_;
	lineImpl = lineImpl_;
}

void tiara::Line::draw(Canvas & canvas){
	switch(lineImpl){
		case LineDDA:
			dda(canvas);
			break;
		default:
			dda(canvas);
			break;
	}
}

void tiara::Line::dda(Canvas & canvas){
	float dx, dy, mx, my;

	dy = y2 - y1;
	dx = x2 - x1;

	if(dx == 0){
		for(size_t y = std::min(y1,y2); y <= std::max(y1,y2); ++y){
			canvas.pixel(Point2d(x1, y), color);
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

	float x = x1;
	float y = y1;

	for(int i = 0; i <= iterations; ++i){		
		canvas.pixel(Point2d(std::round(x), std::round(y)), color);
		x += mx;
		y += my;
	}

}