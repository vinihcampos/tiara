#include "Polygon.h"
#include "Line.h"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits>

tiara::Polygon::Polygon(bool border_, bool fill_, tiara::Color borderColor_, tiara::Color fillColor_){
	border = border_;
	fill = fill_;
	borderColor = borderColor_;
	fillColor = fillColor_;

	miny = std::numeric_limits<int>::max();
	maxy = std::numeric_limits<int>::min();
}

tiara::Polygon::Polygon(std::vector<tiara::Point2d> & points_, bool border_, bool fill_, tiara::Color borderColor_, tiara::Color fillColor_){
	points = points_;
	border = border_;
	fill = fill_;
	borderColor = borderColor_;
	fillColor = fillColor_;

	miny = std::numeric_limits<int>::max();
	maxy = std::numeric_limits<int>::min();
}

tiara::Polygon::~Polygon(){
	points.clear();
}

void tiara::Polygon::add(Point2d & point){
	points.push_back(point);
}

void tiara::Polygon::draw(Canvas & canvas){
	int size = points.size();

	if(fill){
		for(size_t i = 0; i < size; ++i){
			if(points[i].y < miny)
				miny = points[i].y;
			if(points[i].y > maxy)
				maxy = points[i].y;

			if(i == size - 1){
				if(points[i].y - points[0].y == 0 && points[i].y == maxy)
					continue;
				int curr_y = std::min(points[i].y,points[0].y);
				Edge edge(points[i], points[0]);

				if(edges[curr_y].empty())
					edges[curr_y].push_back(edge);
				else{
					auto it = std::lower_bound(edges[curr_y].begin(), edges[curr_y].end(), edge, EdgeComparator());
					if(it == edges[curr_y].end())
						edges[curr_y].push_back(edge);
					else
						edges[curr_y].insert(it, edge);
				}
			}else{
				if(points[i].y - points[i+1].y == 0 && points[i].y == maxy)
					continue;
				int curr_y = std::min(points[i].y,points[i+1].y);
				Edge edge(points[i], points[i+1]);
				
				if(edges[curr_y].empty())
					edges[curr_y].push_back(edge);
				else{
					auto it = std::lower_bound(edges[curr_y].begin(), edges[curr_y].end(), edge, EdgeComparator());
					if(it == edges[curr_y].end())
						edges[curr_y].push_back(edge);
					else
						edges[curr_y].insert(it, edge);
				}
			}
		}

		std::vector<Edge> active;

		for(int y = miny; y <= maxy; ++y){
			if(edges[y].empty())
				continue;
			active = edges[y];
			
			int bit = 0;

			for(size_t j = 0; j < active.size(); ++j){
				if(j == active.size() - 1)
					continue;
				if(active[j].xmin == active[j+1].xmin){
					if(active[j].ymin == active[j+1].ymin || active[j].ymax == active[j+1].ymax){
						if(!bit) canvas.pixel(Point2d((int) active[j].xmin, y), fillColor);
						bit = (bit + 1) % 2; //
					}else{
						if(!bit) canvas.pixel(Point2d((int) active[j].xmin, y), fillColor); //
					}
				}else{
					if(!bit){
						Line line(Point2d((int) active[j].xmin, y), Point2d((int) active[j+1].xmin, y), fillColor, Bresenham);
						line.draw(canvas);
						bit = 1;
					}else{
						bit = 0;
					}
				}
			}

			for(size_t j = 0; j < active.size(); ++j){
				active[j].xmin += active[j].inverse_m;
				if(active[j].ymax > y){
					auto it = std::lower_bound(edges[y+1].begin(), edges[y+1].end(), active[j], EdgeComparator());
					if(it == edges[y+1].end())
						edges[y+1].push_back(active[j]);
					else
						edges[y+1].insert(it, active[j]);
				}
			}
		}
	}

	if(border)
		for(size_t i = 0; i < size; ++i){
			if(i == size - 1){
				Line line(points[i], points[0], borderColor, Bresenham);
				line.draw(canvas);
			}else{
				Line line(points[i], points[i+1], borderColor, Bresenham);
				line.draw(canvas);
			}
		}
}