#include "Canvas.h"
#include <cstring>

tiara::Canvas::Canvas(size_t width_, size_t height_) : width{width_}, height{height_} {
	canvas = std::make_unique<tiara::Canvas::component_t[]>(width * height * 3);
}

void tiara::Canvas::fill(const Color color){
	std::memset(canvas.get(),                       color.r, width * height * sizeof(component_t));
	std::memset(canvas.get() + (width * height),    color.g, width * height * sizeof(component_t));
	std::memset(canvas.get() + (width * height * 2),color.b, width * height * sizeof(component_t));
}

tiara::Color get(const tiara::Point2d p){
	return tiara::Color( canvas[p.x * width + p.y],
	                     canvas[p.x * width + p.y] + width * height,
	                     canvas[p.x * width + p.y] + width * height * 2);
}

tiara::Color get(const size_t idx){
	return tiara::Color( canvas[idx],
	                     canvas[idx] + width * height,
	                     canvas[idx] + width * height * 2);
}