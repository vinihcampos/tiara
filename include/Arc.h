#ifndef _ARC_
#define _ARC_

#include "Shape.h"
#include "Color.h"
#include "Point2d.h"
	
/**
 * @brief The box that encompasses the entire project implementation.
 *
 * \ingroup tiara
 */

namespace tiara{

	/**
	*	Contant PI. 
	*/
	const float PI = 3.14159265;

	/**
	* Provides methods to create arcs.
	* 
	* @author Vinícius Campos
	* @date 3/12/2019
	*/

	class Arc : public Shape{
		private:
			Point2d center;
			float radius;
			float start_angle, final_angle;
			Color color;

		public:
			/**
			*	Creates an arc. 
			*	@param center_ The center of arc.
			*	@param radius_ The radius of arc.
			*	@param color_ The border color of arc.
			*	@param start_angle_ Start angle of arc.
			*	@param final_angle_ Final angle of arc.
			*/
			Arc(const Point2d center_, const float & radius_, const Color & color_ = WHITE, const float & start_angle_ = 0, const float & final_angle_ = 360);
			
			/**
			*	Draws the arc on canvas. 
			*	@param canvas The canvas used to draw the arc.
			*/
			void draw(Canvas & canvas) override;
	};
}

#endif