#include <iostream>
#include "Canvas.h"
#include "Color.h"
#include "PPM.h"
#include "yaml-cpp/yaml.h"

using namespace std;

int main(int argn, char const *argv[]){
	
	tiara::Canvas canvas(200,100);
	canvas.fill(tiara::Color(255,255,0));
	cout << tiara::PPM::generator(canvas) << endl;

	return 0;
}