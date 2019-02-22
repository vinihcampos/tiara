#ifndef _LINE_
#define _LINE_

#include "Shape.h"
#include "Color.h"

namespace tiara{

	enum LineImpl{
		LineDDA = 1			
	};

	class Line : public Shape{
		private:
			int x1, x2, y1, y2;
			Color color;
			LineImpl lineImpl;

			void dda(Canvas & canvas);
		public:

			Line(int x1_, int y1_, int x2_, int y2_, const Color & color_, const tiara::LineImpl lineImpl_ = LineDDA);
			void draw(Canvas & canvas) override;
	};

}

#endif