#include "Edge.h"

#include <math.h>

tiara::Edge::Edge(Point2d & p_, Point2d & q_, float x_frac_) : p{p_}, q{q_}, x_frac{x_frac_}{
	if(p.y < q.y) xmin = p.x;
	else xmin = q.x;

	ymax = std::max(p.y, q.y);
	ymin = std::min(p.y, q.y);

	float dx = q.x - p.x;
	float dy = q.y - p.y;

	if(dy == 0)
		inverse_m = 0;
	else
		inverse_m = dx / dy;
}