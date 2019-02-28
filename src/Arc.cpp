#include "Arc.h"
#include <iostream>
#include <math.h>

tiara::Arc::Arc(const Point2d center_, 
			    const float & radius_,
			    const Color & color_, 
			    const float & start_angle_, 
			    const float & final_angle_) : center{center_}, radius{radius_}, color{color_},
				start_angle{start_angle_}, final_angle{final_angle_}{}

void tiara::Arc::draw(Canvas & canvas){
	float start_rad = start_angle * PI / 180;
	float end_rad = start_angle * PI / 180;

	int x = 0, y = radius;
	int d = 1 - radius, dh = 3, dv = (-2) * radius + 5;

	canvas.pixel(Point2d(center.x + radius, center.y), color);
	canvas.pixel(Point2d(center.x - radius, center.y), color);
	canvas.pixel(Point2d(center.x, center.y + radius), color);
	canvas.pixel(Point2d(center.x, center.y - radius), color);

	while(y > x){
		
		if(d < 0){
			d += dh;
			dh += 2;
			dv += 2;
		}else{
			d += dv;
			dh += 2;
			dv += 4;
			y--;
		}
		x++;
		canvas.pixel(Point2d(x + center.x, -y + center.y), color);
		canvas.pixel(Point2d(-x + center.x, y + center.y), color);
		canvas.pixel(Point2d(-x + center.x, -y + center.y), color);
		canvas.pixel(Point2d(x + center.x, y + center.y), color);

		if (x != y) { 
			canvas.pixel(Point2d(y + center.x, -x + center.y), color);
			canvas.pixel(Point2d(-y + center.x, x + center.y), color);
			canvas.pixel(Point2d(-y + center.x, -x + center.y), color);
			canvas.pixel(Point2d(y + center.x, x + center.y), color);
        } 

		/*float angle1 = cosine(Point2d( center.x + radius, 0 ), Point2d( x + center.x, -y + center.y) );
		float angle2 = cosine(Point2d( 0, center.y - radius ), Point2d(-x + center.x, -y + center.y) ) + angle1;
		float angle3 = cosine(Point2d( center.x - radius, 0 ), Point2d(-x + center.x,  y + center.y) ) + angle2;
		float angle4 = cosine(Point2d( 0, center.y + radius ), Point2d( x + center.x,  y + center.y) ) + angle3;

		std::cout << angle1 << "," << angle2 << "," << angle3 << "," << angle4 << std::endl;

		// 1º Quad
		if(start_rad <= angle1 && angle1 <= end_rad)
			canvas.pixel(Point2d(x + center.x, -y + center.y), color);

		// 2º Quad
		if(start_rad <= angle2 && angle2 <= end_rad)
			canvas.pixel(Point2d(-x + center.x, -y + center.y), color);

		// 3º Quad
		if(start_rad <= angle3 && angle3 <= end_rad)
			canvas.pixel(Point2d(-x + center.x, y + center.y), color);

		// 4º Quad
		if(start_rad <= angle4 && angle4 <= end_rad)
			canvas.pixel(Point2d(x + center.x, y + center.y), color);*/
	}
}

float tiara::Arc::cosine(Point2d p, Point2d q){
	float dist = std::sqrt( std::pow(p.x - q.x, 2) + std::pow(p.y - q.y, 2));
	float twice_r_square = 2 * (radius * radius);

	return std::acos( (twice_r_square - dist) / twice_r_square );
}