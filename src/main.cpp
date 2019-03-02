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
#include "yaml-cpp/yaml.h"

using namespace std;

int main(int argn, char const *argv[]){
	
	tiara::Canvas canvas(30,30);
	tiara::Shape * s;
	s = new tiara::Line(tiara::Point2d(5,15), tiara::Point2d(25,15), tiara::Color(0,0,255));
	s->draw(canvas);
	s = new tiara::Line(tiara::Point2d(15,5), tiara::Point2d(15,25), tiara::Color(0,0,255));
	s->draw(canvas);
	s = new tiara::Arc(tiara::Point2d(15,15), 10, tiara::WHITE, 45, 135);
	s->draw(canvas);
	cout << tiara::PPM::generator(canvas);


	return 0;
}