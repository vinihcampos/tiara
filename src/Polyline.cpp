#include "Polyline.h"
#include "Line.h"

tiara::Polyline::Polyline(Color color_, const int & thickness_)
	: color{color_}, thickness{thickness_}{}

tiara::Polyline::Polyline(std::vector<Point2d> & points_, Color color_, const int & thickness_)
	: points{points_}, color{color_}, thickness{thickness_}{}

tiara::Polyline::~Polyline(){
	points.clear();
}

void tiara::Polyline::add(Point2d & point){
	points.push_back(point);
}

void tiara::Polyline::draw(Canvas & canvas){
	int size = points.size();
	for(size_t i = 0; i < size - 1; ++i){
		if(thickness == 1){
			Line line(points[i], points[i+1], color, Bresenham);
			line.draw(canvas);	
		}else{
			float m = std::abs(points[i].x-points[i+1].x);
			if(std::abs(points[i].y - points[i+1].y) != 0) m /= (float) std::abs(points[i].y - points[i+1].y);

			if(thickness % 2 != 0){
				int half = thickness / 2;
				for(int j = -half; j <= half; ++j){
					if(m <= 1){
						Line line(tiara::Point2d(points[i].x+j,points[i].y), tiara::Point2d(points[i+1].x+j,points[i+1].y), color, Bresenham);
						line.draw(canvas);
					}else if(m > 1){
						Line line(tiara::Point2d(points[i].x,points[i].y+j), tiara::Point2d(points[i+1].x,points[i+1].y+j), color, Bresenham);
						line.draw(canvas);
					}
				}
			}else{
				int half = thickness / 2;
				for(int j = -half+1; j <= half; ++j){
					if(m <= 1){
						Line line(tiara::Point2d(points[i].x+j,points[i].y), tiara::Point2d(points[i+1].x+j,points[i+1].y), color, Bresenham);
						line.draw(canvas);
					}else if(m > 1){
						Line line(tiara::Point2d(points[i].x,points[i].y+j), tiara::Point2d(points[i+1].x,points[i+1].y+j), color, Bresenham);
						line.draw(canvas);
					}
				}
			}
		}
	}
}