#ifndef _CANVAS_
#define _CANVAS_

#include <memory>
#include <string>
#include "Color.h"
#include "Point2d.h"

namespace tiara{
	
	/**
	*	Type of a color component.
	*/
	typedef unsigned char component_t;

	/**
	* Provides methods to draw an image.
	* 
	* @author Vinícius Campos
	* @date 3/12/2019
	*/
	class Canvas{
		private:			
			size_t width, height;
			std::unique_ptr<component_t[]> canvas;

			float kernel[3][3] = { {1,2,1}, 
			                       {2,4,2}, 
			                       {1,2,1} };

			float * multiply(int sh, int sw, int fh, int fw);

		public:
			/**
			*	Creates an empty canvas.
			*	@param width_ The width of canvas.
			*	@param height_ The height of canvas.
			*/
			Canvas(size_t width_, size_t height_, float norm = 1/16.0);
			
			/**
			*	Method to get the width of canvas. 
			*	@return The width of canvas.
			*/
			size_t getWidth() const { return width; }
			
			/**
			*	Method to get the height of canvas.
			*	@return The height of canvas.
			*/
			size_t getHeight() const { return height; }

			/**
			*	Method to get the color of a pixel.
			*	@param p A point of canvas.
			*	@return The color of point p.
			*/
			Color get(const Point2d & p) const;

			/**
			*	Method to get the color of a pixel.
			*	@param idx An index of canvas array.
			*	@return The color of index array idx.
			*/
			Color get(const size_t & idx) const;

			/**
			*	Method to fill the background from a point with a specific color using flood fill algorithm.
			*	@param color The color to paint the background.
			*	@param p The start point of painting.
			*	@param borderColor The limit color of algorithm.
			*/
			void fill(const Color & color, const Point2d p = Point2d(0,0), const Color & borderColor = BLACK);
			
			/**
			* 	Method to paint a pixel.
			*	@param p A point of canvas.
			*	@param color The color to paint the pixel.
			*/
			void pixel(const Point2d & p, const Color & color);
			
			/**
			* 	Method to paint a list of pixels.
			*	@param ps The list of points.
			*	@param p_size The size of list ps.
			*	@param color The color to paint the list of pixels.
			*/
			void pixels(const Point2d ps[], const size_t & p_size, const Color & color);

			/** 
			* 	Method to apply antialiasing on canvas. &nbsp;
			*/
			void antialiasing();
	};

}

#endif