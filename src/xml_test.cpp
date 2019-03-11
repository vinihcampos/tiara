#include "tinyxml2.h"
#include <iostream>
#include <string>

using namespace std;
using namespace tinyxml2;

// Macro errors

/*#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

int main(int argn, char const *argv[]){
	
	if(argn < 1)
		return 0;

	XMLDocument xmlTiara;
	XMLError file = xmlTiara.LoadFile(argv[1]);
	XMLCheckResult(file);

	XMLElement * pRootElement = xmlTiara.RootElement();
	for(XMLElement * pChild = pRootElement->FirstChildElement(); pChild != NULL; pChild = pChild->NextSiblingElement()){
		std::cout << pChild->Name() << ": ";
		for(const XMLAttribute * pAttr = pChild->FirstAttribute(); pAttr != NULL; pAttr = pAttr->Next()){
			std::cout << pAttr->Name() << ",";
		}
		std::cout << std::endl;
	}


	return 0;
}*/