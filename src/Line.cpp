#include "Line.h"
#include "Point2d.h"
#include <math.h>
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
		case Bresenham:
			bresenham(canvas);
			break;
		default:
			dda(canvas);
			break;
	}
}

void tiara::Line::bresenham(Canvas & canvas){
	Point2d p,q;
	bool climbing;
	int pk;
	int increment = 1;
	
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;

	if(std::abs(dy) < std::abs(dx)){
		if(p1.x <= p2.x){
			p = p1;
			q = p2;
		}else{
			p = p2;
			q = p1;
		} 
		climbing = false;
	}else{
		if(p1.y <= p2.y){
			p = p1;
			q = p2;
		}else{
			p = p2;
			q = p1;
		}
		climbing = true;
	}	

	dx = q.x - p.x;
	dy = q.y - p.y;

	if(!climbing){
		if(dy < 0){
			increment = -1;
			dy = -dy;
		}
	}else{
		if(dx < 0){
			increment = -1;
			dx = -dx;
		}
	}

	int twice_dx = 2 * dx;
	int twice_dy = 2 * dy;

	int x = p.x;
	int y = p.y;

	if(!climbing){
		pk = twice_dy - dx;
		for (; x <= q.x; ++x){
			canvas.pixel(Point2d(x,y), color);
			if(pk > 0){
				y += increment;
				pk += -twice_dx;
			}
			pk += twice_dy;
		}
	}else{
		pk = twice_dx - dy;
		for (; y <= q.y; ++y){
			canvas.pixel(Point2d(x,y), color);
			if(pk > 0){
				x += increment;
				pk += -twice_dy;
			}
			pk += twice_dx;
		}
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