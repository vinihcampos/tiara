#include "Canvas.h"
#include <string>
#include <cstring>
#include <iostream>

tiara::Canvas::Canvas(size_t width_, size_t height_) : width{width_}, height{height_} {
	canvas = std::make_unique<component_t[]>(width * height * 3);
	std::memset(canvas.get(), 0, width * height * 3 * sizeof(component_t));
}

void tiara::Canvas::fill(const Color & color){
	std::memset(canvas.get(),                       color.r, width * height * sizeof(component_t));
	std::memset(canvas.get() + (width * height),    color.g, width * height * sizeof(component_t));
	std::memset(canvas.get() + (width * height * 2),color.b, width * height * sizeof(component_t));
}

tiara::Color tiara::Canvas::get(const tiara::Point2d & p) const{
	return tiara::Color( canvas[p.x * width + p.y],
	                     canvas[p.x * width + p.y + width * height],
	                     canvas[p.x * width + p.y + width * height * 2] );
}

tiara::Color tiara::Canvas::get(const size_t & idx) const{
	return tiara::Color( canvas[idx],
	                     canvas[idx + width * height] ,
	                     canvas[idx + width * height * 2] );
}

void tiara::Canvas::pixel(const Point2d & p, const Color & color){
	size_t real_p = p.x * width + p.y;

	for(int i = 0; i < 3; ++i) 
		canvas[real_p + i * width * height] = color[i];
}

void tiara::Canvas::pixels(const Point2d ps[], const size_t & p_size, const Color & color){
	for(size_t i = 0; i < p_size; ++i) 
		pixel(ps[i], color);
}

void tiara::Canvas::rectangle(const Point2d & tl, const Point2d & br, const Color & color, const bool filled){
	
	// Draw horizontal lines
	for(size_t c = tl.y; c <= br.y; ++c){
		pixel(Point2d(tl.x, c), color);
		pixel(Point2d(br.x, c), color);
	}

	// Draw vertical lines
	for(size_t r = tl.y; r <= br.y; ++r){
		pixel(Point2d(r, tl.y), color);
		pixel(Point2d(r, br.y), color);
	}

	if(filled){
		for(size_t r = tl.x + 1; r < br.x; ++r){
			for(size_t c = tl.y + 1; c < br.y; ++c){
				pixel(Point2d(r,c), color);
			}
		}
	}	
}