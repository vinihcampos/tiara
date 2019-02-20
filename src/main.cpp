#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Canvas.h"
#include "Color.h"
#include "Point2d.h"
#include "PPM.h"
#include "yaml-cpp/yaml.h"

using namespace std;

int main(int argn, char const *argv[]){
	
	tiara::Canvas canvas(800,600);
	canvas.fill(tiara::Color(255,255,0));
	srand (time(NULL));
	tiara::Point2d ps[200];
	for(int i = 0; i < 200; ++i){
		ps[i] = tiara::Point2d(rand() % 600, rand() % 800);
	}
	canvas.pixels(ps, 200, tiara::WHITE);

	canvas.rectangle(tiara::Point2d(200,200), tiara::Point2d(500,500), tiara::Color(125, 0, 255), true);
	cout << tiara::PPM::generator(canvas);

	return 0;
}