#include "Color.h"
#include <string>

tiara::Color::Color(const Color & color){
	r = color.r;
	g = color.g;
	b = color.b;
}

tiara::Color::Color(const std::string & color, std::map<std::string, Color> & pallete){

	if(pallete.find(color) != pallete.end()){
		Color c = pallete[color];
		r = c.r;
		g = c.g;
		b = c.b;
	}else if(!color.compare("white") || !color.compare("WHITE")){
		r = WHITE.r;
		g = WHITE.g;
		b = WHITE.b;
	}
	else if(!color.compare("red") || !color.compare("RED")){
		r = RED.r;
		g = RED.g;
		b = RED.b;
	}
	else if(!color.compare("blue") || !color.compare("BLUE")){
		r = BLUE.r;
		g = BLUE.g;
		b = BLUE.b;
	}
	else if(!color.compare("green") || !color.compare("GREEN")){
		r = GREEN.r;
		g = GREEN.g;
		b = GREEN.b;
	}
	else if(!color.compare("yellow") || !color.compare("YELLOW")){
		r = YELLOW.r;
		g = YELLOW.g;
		b = YELLOW.b;
	}else{
		r = BLACK.r;
		g = BLACK.g;
		b = BLACK.b;
	}
}

tiara::Color::channel& tiara::Color::operator[](int idx){
	switch(idx){
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		default:
			throw "Index out of range";
	}
}

const tiara::Color::channel& tiara::Color::operator[](int idx) const{
	switch(idx){
		case 0:
			return r;
		case 1:
			return g;
		case 2:
			return b;
		default:
			throw "Index out of range";
	}
}

bool tiara::Color::operator==(const tiara::Color & color) const{
	return r == color.r && g == color.g && b == color.b;
}