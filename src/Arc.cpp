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

	int x = 0, y = radius;
	int d = 1 - radius, dh = 3, dv = (-2) * radius + 5;

	if(start_angle == 0 || start_angle == 360 || final_angle == 0 || final_angle == 360)
		canvas.pixel(Point2d(center.x + radius, center.y), color);
	if(start_angle <= 90 && final_angle >= 90)
		canvas.pixel(Point2d(center.x, center.y - radius), color);
	if(start_angle <= 180 && final_angle >= 180)
		canvas.pixel(Point2d(center.x - radius, center.y), color);
	if(start_angle <= 270 && final_angle >= 270)
		canvas.pixel(Point2d(center.x, center.y + radius), color);

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

		float a1,a2,a3,a4;
		a1 = std::acos( x / radius ) * 180.0 / PI;
		a2 = 180 - a1;
		a3 = 180 + a1;
		a4 = 270 + (90 - a1);

		if(start_angle <= a1 && a1 <= final_angle)
			canvas.pixel(Point2d(x + center.x, -y + center.y), color);
		if(start_angle <= a2 && a2 <= final_angle)
			canvas.pixel(Point2d(-x + center.x, -y + center.y), color);
		if(start_angle <= a3 && a3 <= final_angle)
			canvas.pixel(Point2d(-x + center.x, y + center.y), color);
		if(start_angle <= a4 && a4 <= final_angle)
			canvas.pixel(Point2d(x + center.x, y + center.y), color);

		if (x != y) {

			a1 = std::asin( x / radius ) * 180.0 / PI;
			a2 = 180 - a1;
			a3 = 180 + a1;
			a4 = 270 + (90 - a1);

			if(start_angle <= a1 && a1 <= final_angle)
				canvas.pixel(Point2d(y + center.x, -x + center.y), color);
			if(start_angle <= a2 && a2 <= final_angle)
				canvas.pixel(Point2d(-y + center.x, -x + center.y), color);
			if(start_angle <= a3 && a3 <= final_angle)
				canvas.pixel(Point2d(-y + center.x, x + center.y), color);
			if(start_angle <= a4 && a4 <= final_angle)
				canvas.pixel(Point2d(y + center.x, x + center.y), color);
        }
	}
}