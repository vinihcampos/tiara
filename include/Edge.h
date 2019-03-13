#ifndef _EDGE_
#define _EDGE_

#include "Point2d.h"

namespace tiara{

	/**
	* Provides the entity edge.
	* 
	* @author Vinícius Campos
	* @date 4/12/2019
	*/
	class Edge{
		public:

			/** 
			* Extreme points of edge.
			*/
			Point2d p;
			/** 
			* Extreme points of edge. 
			*/
			Point2d q;
			/** 
			* Minimum y of edge. 
			*/
			int ymin;
			/** 
			* Maximum y of edge. 
			*/
			int ymax;
			/** 
			* Minimum x of edge. 
			*/
			float xmin;
			/** 
			* The inverse ratio between dy and dx (dx/dy). 
			*/
			float inverse_m;

			/**
			*	Creates an edge.
			*	@param p_ An extreme point of edge.
			*	@param q_ Another extreme point of edge.
			*/
			Edge(Point2d & p_, Point2d & q_);
	};

	/** 
	* Struct used in insertion algorithm. 
	*/
	struct EdgeComparator {
	    bool operator()(Edge const& e0, Edge const& e1) const {
	        return e0.xmin < e1.xmin;
	    }
	};

}

#endif