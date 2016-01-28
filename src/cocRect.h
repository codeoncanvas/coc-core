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



};

}