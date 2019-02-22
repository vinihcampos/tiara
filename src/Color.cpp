#include "Color.h"

tiara::Color::Color(const Color & color){
	r = color.r;
	g = color.g;
	b = color.b;
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