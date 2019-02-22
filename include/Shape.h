#ifndef _SHAPE_
#define _SHAPE_

#include "Canvas.h"

namespace tiara{

	class Shape{

		public:
			virtual void draw(Canvas & canvas) = 0;
	};

}

#endif