#include <iostream>
#include <string>
#include "Canvas.h"
#include "Color.h"
#include "Point2d.h"
#include "Shape.h"
#include "Line.h"
#include "Arc.h"
#include "PPM.h"
#include "Polygon.h"
#include "tinyxml2.h"

using namespace std;
using namespace tiara;
using namespace tinyxml2;

void processPixel(Canvas & canvas, XMLElement *& pChild);
void processLine(Canvas & canvas, XMLElement *& pChild);
void processPolygon(Canvas & canvas, XMLElement *& pChild);
void processArc(Canvas & canvas, XMLElement *& pChild);

int main(int argn, char const *argv[]){
	
	if(argn < 2){
		cerr << "Please, provide a tiara description scene" << endl;
		return 0;
	}

	XMLDocument xmlTiara;
	XMLError file = xmlTiara.LoadFile(argv[1]);

	XMLElement * pRootElement = xmlTiara.RootElement();
	int width, height;
	string fileName, elementName;

	width = pRootElement->IntAttribute("width", 800);
	height = pRootElement->IntAttribute("height", 600);
	if(pRootElement->Attribute("name") != NULL) 
		fileName = pRootElement->Attribute("name");
	else
		fileName = "scene";

	Canvas canvas(width, height, 1/16.0);

	for(XMLElement * pChild = pRootElement->FirstChildElement(); pChild != NULL; pChild = pChild->NextSiblingElement()){
		elementName = pChild->Name();
		if(elementName.compare("Pixel") == 0 || elementName.compare("pixel") == 0){
			processPixel(canvas, pChild);
		}else if(elementName.compare("Line") == 0 || elementName.compare("line") == 0){
			processLine(canvas, pChild);
		}else if(elementName.compare("Polygon") == 0 || elementName.compare("polygon") == 0){
			processPolygon(canvas, pChild);
		}else if(elementName.compare("Arc") == 0 || elementName.compare("arc") == 0){
			processArc(canvas, pChild);
		}else{
			cerr << "The element " << elementName << " is invalid" << endl;
			return 0;
		}
	}

	canvas.antialiasing();
	cout << tiara::PPM::generator(canvas);

	return 0;
}

void processPixel(Canvas & canvas, XMLElement *& pChild){

}
void processLine(Canvas & canvas, XMLElement *& pChild){
	int x1 = pChild->IntAttribute("x1", 0);
	int x2 = pChild->IntAttribute("x2", 0);
	int y1 = pChild->IntAttribute("y1", 0);
	int y2 = pChild->IntAttribute("y2", 0);

	string color, algorithm = "";

	if(pChild->FindAttribute("color") != NULL)
		color = pChild->Attribute("color");
	if(pChild->FindAttribute("alg") != NULL)
		algorithm = pChild->Attribute("alg");

	Color c(color);

	Shape * s = new Line(tiara::Point2d(x1,y1), tiara::Point2d(x2,y2), c, algorithm);
	s->draw(canvas);

	delete s;
}
void processPolygon(Canvas & canvas, XMLElement *& pChild){

}
void processArc(Canvas & canvas, XMLElement *& pChild){
	int x = pChild->IntAttribute("x", 0);
	int y = pChild->IntAttribute("y", 0);
	float radius = pChild->FloatAttribute("radius", 0.0);

	int start = pChild->IntAttribute("start", 0);;
	int end = pChild->IntAttribute("end", 360);

	string borderColor;
	if(pChild->FindAttribute("border-color") != NULL)
		borderColor = pChild->Attribute("border-color");

	Color bc(borderColor);

	Shape * s = new Arc(tiara::Point2d(x,y), radius, bc, start, end);
	s->draw(canvas);

	delete s;
}