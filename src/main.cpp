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
	s = new tiara::Arc(tiara::Point2d(15,15), 10);
	s->draw(canvas);
	cout << tiara::PPM::generator(canvas);


	return 0;
}