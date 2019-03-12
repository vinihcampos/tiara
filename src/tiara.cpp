#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "Canvas.h"
#include "Color.h"
#include "Point2d.h"
#include "Shape.h"
#include "Line.h"
#include "Arc.h"
#include "PPM.h"
#include "Polygon.h"
#include "Polyline.h"
#include "tinyxml2.h"

using namespace std;
using namespace tiara;
using namespace tinyxml2;

void processPoint(Canvas & canvas, XMLElement *& pChild);
void processLine(Canvas & canvas, XMLElement *& pChild);
void processPolygon(Canvas & canvas, XMLElement *& pChild);
void processPolyline(Canvas & canvas, XMLElement *& pChild);
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
		if(elementName.compare("Point") == 0 || elementName.compare("point") == 0){
			processPoint(canvas, pChild);
		}else if(elementName.compare("Line") == 0 || elementName.compare("line") == 0){
			processLine(canvas, pChild);
		}else if(elementName.compare("Polygon") == 0 || elementName.compare("polygon") == 0){
			processPolygon(canvas, pChild);
		}else if(elementName.compare("Polyline") == 0 || elementName.compare("polyline") == 0){
			processPolyline(canvas, pChild);
		}else if(elementName.compare("Arc") == 0 || elementName.compare("arc") == 0){
			processArc(canvas, pChild);
		}else{
			cerr << "The element " << elementName << " is invalid" << endl;
			return 0;
		}
	}

	canvas.antialiasing();
	tiara::PPM::generator(canvas, fileName);

	return 0;
}

void processPoint(Canvas & canvas, XMLElement *& pChild){
	int x = pChild->IntAttribute("x", 0);
	int y = pChild->IntAttribute("y", 0);
	string color = "";

	if(pChild->FindAttribute("color") != NULL)
		color = pChild->Attribute("color");

	Color c(color);

	canvas.pixel(Point2d(x,y), c);
}
void processLine(Canvas & canvas, XMLElement *& pChild){
	int x1 = pChild->IntAttribute("x1", 0);
	int x2 = pChild->IntAttribute("x2", 0);
	int y1 = pChild->IntAttribute("y1", 0);
	int y2 = pChild->IntAttribute("y2", 0);
	int thickness = pChild->IntAttribute("thickness", 1);

	if(thickness == 0)
		return;

	string color = "", algorithm = "";

	if(pChild->FindAttribute("color") != NULL)
		color = pChild->Attribute("color");
	if(pChild->FindAttribute("alg") != NULL)
		algorithm = pChild->Attribute("alg");

	Color c(color);

	Shape * s;

	float m = abs(x1-x2);
	if(abs(y1-y2) != 0) m /= (float) abs(y1-y2);

	if(thickness == 1){
		s = new Line(tiara::Point2d(x1,y1), tiara::Point2d(x2,y2), c, algorithm);
		s->draw(canvas);
	}else if(thickness % 2 != 0){
		int half = thickness / 2;
		for(int i = -half; i <= half; ++i){
			if(m <= 1){
				s = new Line(tiara::Point2d(x1+i,y1), tiara::Point2d(x2+i,y2), c, algorithm);
				s->draw(canvas);
			}else if(m > 1){
				s = new Line(tiara::Point2d(x1,y1+i), tiara::Point2d(x2,y2+i), c, algorithm);
				s->draw(canvas);
			}
		}
	}else{
		int half = thickness / 2;
		for(int i = -half+1; i <= half; ++i){
			if(m <= 1){
				s = new Line(tiara::Point2d(x1+i,y1), tiara::Point2d(x2+i,y2), c, algorithm);
				s->draw(canvas);
			}else if(m > 1){
				s = new Line(tiara::Point2d(x1,y1+i), tiara::Point2d(x2,y2+i), c, algorithm);
				s->draw(canvas);
			}
		}
	}

	delete s;
}
void processPolygon(Canvas & canvas, XMLElement *& pChild){
	string borderColor = "", fillColor = "";
	bool border = false, fill = false;
	if(pChild->FindAttribute("border-color") != NULL)
		borderColor = pChild->Attribute("border-color");
	if(pChild->FindAttribute("fill-color") != NULL)
		fillColor = pChild->Attribute("fill-color");

	int thickness = pChild->IntAttribute("thickness", 1);

	Color bc;
	Color fc;

	if(borderColor.compare("")){
		border = true;
		bc = Color(borderColor);
	}
	if(fillColor.compare("")){
		fill = true;
		fc = Color(fillColor);
	}

	std::vector<Point2d> points;

	for(XMLElement * pGrandchild = pChild->FirstChildElement(); pGrandchild != NULL; pGrandchild = pGrandchild->NextSiblingElement()){
		int x = pGrandchild->IntAttribute("x", 0);
		int y = pGrandchild->IntAttribute("y", 0);
		points.push_back(Point2d(x,y));
	}

	Shape * s = new Polygon(points, border, fill, bc, fc, thickness);
	s->draw(canvas);

	delete s;
}

void processPolyline(Canvas & canvas, XMLElement *& pChild){
	int thickness = pChild->IntAttribute("thickness", 1);
	string color = "";
	if(pChild->FindAttribute("color") != NULL)
		color = pChild->Attribute("color");

	Color bc(color);

	std::vector<Point2d> points;

	for(XMLElement * pGrandchild = pChild->FirstChildElement(); pGrandchild != NULL; pGrandchild = pGrandchild->NextSiblingElement()){
		int x = pGrandchild->IntAttribute("x", 0);
		int y = pGrandchild->IntAttribute("y", 0);
		points.push_back(Point2d(x,y));
	}

	Shape * s = new Polyline(points, color, thickness);
	s->draw(canvas);

	delete s;
}

void processArc(Canvas & canvas, XMLElement *& pChild){
	int x = pChild->IntAttribute("x", 0);
	int y = pChild->IntAttribute("y", 0);
	int thickness = pChild->IntAttribute("thickness", 1);
	float radius = pChild->FloatAttribute("radius", 0.0);

	int start = pChild->IntAttribute("start", 0);;
	int end = pChild->IntAttribute("end", 360);

	string borderColor = "";
	if(pChild->FindAttribute("border-color") != NULL)
		borderColor = pChild->Attribute("border-color");

	Color bc(borderColor);
	Shape * s;
	
	if(thickness == 1){
		s = new Arc(tiara::Point2d(x,y), radius, bc, start, end);
		s->draw(canvas);
	}else if(thickness % 2 != 0){
		int half = thickness / 2;
		for(int i = -half; i <= half; ++i){
			s = new Arc(tiara::Point2d(x,y), radius+i, bc, start, end);
			s->draw(canvas);
		}
	}else{
		int half = thickness / 2;
		for(int i = -half+1; i <= half; ++i){
			s = new Arc(tiara::Point2d(x,y), radius+i, bc, start, end);
			s->draw(canvas);
		}
	}

	string fillColor = "";
	if(pChild->FindAttribute("fill-color") != NULL)
		fillColor = pChild->Attribute("fill-color");

	Color fc(fillColor);

	vector<Point2d> triggers;

	for(XMLElement * pGrandchild = pChild->FirstChildElement(); pGrandchild != NULL; pGrandchild = pGrandchild->NextSiblingElement()){
		int x = pGrandchild->IntAttribute("x", 0);
		int y = pGrandchild->IntAttribute("y", 0);
		triggers.push_back(Point2d(x,y));
	}

	for(Point2d trigger : triggers){
		canvas.fill(fc, trigger, bc);
	}

	delete s;
}