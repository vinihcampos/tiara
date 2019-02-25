#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Canvas.h"
#include "Color.h"
#include "Point2d.h"
#include "Shape.h"
#include "Line.h"
#include "PPM.h"
#include "yaml-cpp/yaml.h"

using namespace std;

int main(int argn, char const *argv[]){
	
	tiara::Canvas canvas(300,200);
	tiara::Shape * s;
	s = new tiara::Line(tiara::Point2d(75,50),tiara::Point2d(75,199), tiara::WHITE);
	s->draw(canvas);
	s = new tiara::Line(tiara::Point2d(75,50),tiara::Point2d(100,100), tiara::WHITE);
	s->draw(canvas);
	s = new tiara::Line(tiara::Point2d(100,100),tiara::Point2d(200,100), tiara::WHITE);
	s->draw(canvas);
	s = new tiara::Line(tiara::Point2d(200,100),tiara::Point2d(225,50), tiara::WHITE);
	s->draw(canvas);
	s = new tiara::Line(tiara::Point2d(225,50),tiara::Point2d(225,199), tiara::WHITE);
	s->draw(canvas);
	cout << tiara::PPM::generator(canvas);

	return 0;
}