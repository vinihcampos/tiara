#include "PPM.h"
#include <string>

std::string tiara::PPM::generator(const tiara::Canvas & canvas){
	
	std::string result = "P3\n";
	result += std::to_string(canvas.getWidth()) + " " + std::to_string(canvas.getHeight()) + "\n";
	result += std::to_string(255) + "\n";

	for(size_t i = 0; i < canvas.getHeight(); ++i){
		for(size_t j = 0; j < canvas.getWidth(); ++j){
			Color c = canvas.get(Point2d(i,j));
			result += std::to_string(c.r) + " " + std::to_string(c.g) + " " + std::to_string(c.b) + " ";
		}
		result += "\n";
	}

	return result;

}