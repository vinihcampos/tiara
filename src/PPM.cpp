#include "PPM.h"

std::string tiara::PPM::generator(const tiara::Canvas & canvas){
	
	std::string result = "P3\n";
	result += std::to_string(canvas.getWidth()) + " " + std::to_string(canvas.getHeight()) + "\n";
	result += std::to_string(255) + "\n";

	for(size_t i = 0; i < canvas.getWidth(); ++i){
		for(size_t j = 0; j < canvas.getHeight(); ++j){
			tiara::Color c = canvas.get(tiara::Point2d(i,j));
			result += c.r + " " + c.g + " " + c.b + " ";
		}
		result += "\n";
	}

	return result;

}