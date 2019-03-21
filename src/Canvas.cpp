#include "Canvas.h"
#include <string>
#include <cstring>
#include <iostream>
#include <math.h>
#include <stack>

tiara::Canvas::Canvas(size_t width_, size_t height_, float norm) : width{width_}, height{height_} {
	canvas = std::make_unique<component_t[]>(width * height * 3);
	std::memset(canvas.get(), 0, width * height * 3 * sizeof(component_t));

	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			kernel[i][j] *= norm; 
		}
	}
}

void tiara::Canvas::fill(const Color & color, const Point2d p, const Color & borderColor){
	std::stack<Point2d> points;
	points.push(p);

	while(!points.empty()){

		Point2d p_ = points.top();
		points.pop();

		if(p_.x >= 0 && p_.x < width && p_.y >= 0 && p_.y < height){
			if(!(get(p_) == borderColor) && !(get(p_) == color)){
				pixel(p_, color);
				points.push(Point2d(p_.x, p_.y+1));
				points.push(Point2d(p_.x+1, p_.y));
				points.push(Point2d(p_.x, p_.y-1));
				points.push(Point2d(p_.x-1, p_.y));	
			}		
		}
	}
}

tiara::Color tiara::Canvas::get(const tiara::Point2d & p) const{
	return tiara::Color( canvas[p.y * width + p.x],
	                     canvas[p.y * width + p.x + width * height],
	                     canvas[p.y * width + p.x + width * height * 2] );
}

tiara::Color tiara::Canvas::get(const size_t & idx) const{
	return tiara::Color( canvas[idx],
	                     canvas[idx + width * height] ,
	                     canvas[idx + width * height * 2] );
}

void tiara::Canvas::pixel(const Point2d & p, const Color & color){
	if(p.x < 0 || p.x >= width || p.y < 0 || p.y >= height )
		return;
	int real_p = p.y * width + p.x;
	for(int i = 0; i < 3; ++i)
		canvas[real_p + i * width * height] = color[i];
}

void tiara::Canvas::pixels(const Point2d ps[], const size_t & p_size, const Color & color){
	for(size_t i = 0; i < p_size; ++i) 
		pixel(ps[i], color);
}

void tiara::Canvas::antialiasing(){
	std::unique_ptr<component_t[]> copy = std::make_unique<component_t[]>(width * height * 3);
	float * kernel_results = new float[3];
	for(int i = 0; i < height; ++i){
		for(int j = 0; j < width; ++j){
			kernel_results = multiply(i-1, j-1, i+1, j+1);
			copy[i * width + j] = std::pow(kernel_results[0]  / 255.0, 1/2.0) * 255;
			copy[i * width + j + width * height] = std::pow(kernel_results[1] / 255.0, 1/2.0) * 255;
			copy[i * width + j + width * height * 2] = std::pow(kernel_results[2] / 255.0, 1/2.0) * 255;
		}
	}

	canvas = std::move(copy);
	delete kernel_results;
}

float * tiara::Canvas::multiply(int sh, int sw, int fh, int fw){
	float * sum = new float[3];
	sum[0] = 0;
	sum[1] = 0;
	sum[2] = 0;

	int kernel_index = 0;

	for(int i = sh; i <= fh; ++i){
		for(int j = sw; j <= fw; ++j){
			if(i < 0 || j < 0 || i >= height || j >= width){
				continue;
			}else{
				sum[0] += canvas[i * width + j] * kernel[kernel_index / 3][kernel_index % 3];
				sum[1] += canvas[i * width + j + width * height] * kernel[kernel_index / 3][kernel_index % 3];
				sum[2] += canvas[i * width + j + width * height * 2] * kernel[kernel_index / 3][kernel_index % 3];
			}
			kernel_index++;	
		}
	}

	return sum;
}