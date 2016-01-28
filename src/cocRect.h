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
		float getX1() { return getX(); }
		float getY1() { return getY(); }
#endif

#ifdef COC_CI
		float 	getX() { return getX1(); }
		float 	getY() { return getY1(); }
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