#include "Line.h"
#include "Point2d.h"
#include "math.h"
#include <iostream>

tiara::Line::Line(size_t x1_, size_t y1_, size_t x2_, size_t y2_, const Color & color_, const tiara::LineImpl lineImpl_){
	if(x1_ < x2_){
		x1 = x1_;
		x2 = x2_;
		y1 = y1_;
		y2 = y2_;
	}else{
		x1 = x2_;
		x2 = x1_;
		y1 = y2_;
		y2 = y1_;
	}

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
	float dx, dy, y, m;
	bool climbind = true;

	if(y2 < y1)
		climbind = false;

	dy = y2 - y1;
	dx = x2 - x1;

	m = dy/dx;

	if(std::abs(m) > 1)
		m = dx/dy;

	y = y1;
	for(size_t x = x1; x <= x2; ++x){
		canvas.pixel(Point2d(x, std::round(y)), color);
		if(climbind) y += m;
		else y -= m;
	}

}