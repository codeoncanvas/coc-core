//
//  Rect.h
//  Created by Lukasz Karluk on 22/01/2016.
//  http://codeoncanvas.cc
//

#pragma once

#if defined( COC_OF )

#include "ofRectangle.h"
#define RectBase ofRectangle

#elif defined( COC_CI )

#include "cinder/Rect.h"
#define RectBase ci::Rectf

#endif

namespace coc {

class Rect : public RectBase {

public:

#ifdef COC_OF

		//dangerous! safe as getters but not setters:
//		float &x1;
//		float &y1;
//		Rect() : x1(x), y1(y) {}

		float getX1() { return getX(); }
		float getY1() { return getY(); }
		float getX2() { return x + width; }
		float getY2() { return y + height; }

#endif

#ifdef COC_CI

		//dangerous! safe as getters but not setters:
//		float &x;
//		float &y;
//		Rect() : x(x1), y(y1) {}

		float 	getX() { return x1; }
		float 	getY() { return y1; }
		bool 	isEmpty() {
			if (getWidth()==0 || getHeight() ==0) return true;
			return false;
		}

		glm::vec2 getTopLeft() { return getUpperLeft(); }
		glm::vec2 getBottomRight() { return getLowerRight(); }

		bool inside( float x, float y) {
			return contains( glm::vec2(x,y) );
		}

		void setX( float f ) { x1 = f; }
		void setY( float f ) { y1 = f; }
		void setWidth( float f ) { x2 = x1 + f; }
		void setHeight( float f ) { y2 = y1 + f; }
#endif


};

}