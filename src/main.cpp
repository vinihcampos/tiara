#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Canvas.h"
#include "Color.h"
#include "Point2d.h"
#include "Shape.h"
#include "Line.h"
#include "Arc.h"
#include "PPM.h"
#include "Polygon.h"

using namespace std;

int main(int argn, char const *argv[]){
	
	tiara::Canvas canvas(300,300,1/16.0);

	tiara::Shape * s;
	//s = new tiara::Line(tiara::Point2d(50,150), tiara::Point2d(250,150), tiara::Color(0,0,255));
	//s->draw(canvas);
	//s = new tiara::Line(tiara::Point2d(150,50), tiara::Point2d(150,250), tiara::Color(0,0,255));
	//s->draw(canvas);
	//s = new tiara::Arc(tiara::Point2d(150,150), 100, tiara::WHITE);
	//s->draw(canvas);	
	//canvas.fill(tiara::Color(255,255,0), tiara::Point2d(150,150), tiara::WHITE);

	std::vector<tiara::Point2d> points;
	points.push_back(tiara::Point2d(100,100));
	points.push_back(tiara::Point2d(120,100));
	points.push_back(tiara::Point2d(120,70));
	points.push_back(tiara::Point2d(150,70));
	points.push_back(tiara::Point2d(160,55));
	points.push_back(tiara::Point2d(140,20));
	points.push_back(tiara::Point2d(120,20));
	points.push_back(tiara::Point2d(120,50));
	points.push_back(tiara::Point2d(70,50));
	points.push_back(tiara::Point2d(70,80));

	s = new tiara::Polygon(points, false, true, tiara::Color(255,0,0), tiara::WHITE);
	s->draw(canvas);

	//s = new tiara::Line(tiara::Point2d(10,10), tiara::Point2d(20,20), tiara::WHITE);
	//s->draw(canvas);
	//s = new tiara::Line(tiara::Point2d(20,20), tiara::Point2d(50,10), tiara::WHITE);
	//s->draw(canvas);
	//s = new tiara::Line(tiara::Point2d(50,10), tiara::Point2d(0,0), tiara::WHITE);
	//s->draw(canvas);
	//s = new tiara::Line(tiara::Point2d(0,0), tiara::Point2d(10,10), tiara::WHITE);
	//s->draw(canvas);

	canvas.antialiasing();
	cout << tiara::PPM::generator(canvas);

	return 0;
}