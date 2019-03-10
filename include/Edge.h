#ifndef _EDGE_
#define _EDGE_

#include "Point2d.h"

namespace tiara{

	class Edge{
		public:

			Point2d p,q;
			int ymin, ymax;
			float xmin;
			float inverse_m;
			float x_frac;

			Edge(Point2d & p_, Point2d & q_, float x_frac_ = 0.0);
	};

	struct EdgeComparator {
	    bool operator()(Edge const& e0, Edge const& e1) const {
	        return e0.xmin < e1.xmin;
	    }
	};

}

#endif