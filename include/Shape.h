#ifndef _SHAPE_
#define _SHAPE_

#include "Canvas.h"

namespace tiara{

	/**
	* Provides an abstract class for shapes.
	* 
	* @author Vinícius Campos
	* @date 3/12/2019
	*/
	class Shape{

		public:

			/**
			*	Virtual method to draw shapes on canvas. 
			*	@param canvas The canvas used to draw the shape.
			*/
			virtual void draw(Canvas & canvas) = 0;
	};

}

#endif