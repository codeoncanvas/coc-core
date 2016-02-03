//
//  Rect.h
//  Created by Lukasz Karluk on 22/01/2016.
//  http://codeoncanvas.cc
//

#pragma once

#if defined( COC_OF )

#include "cocGlm.h"

#include "ofRectangle.h"
#define RectBase ofRectangle

#elif defined( COC_CI )

#include "cinder/Rect.h"
#define RectBase ci::Rectf

#endif

namespace coc {

class Rect : public RectBase {

public:

    void setX(float value);
    void setY(float value);
    void setW(float value);
    void setH(float value);

    float getX() const;
    float getY() const;
    float getW() const;
    float getH() const;
    
    void setX1(float value);
    void setY1(float value);
    void setX2(float value);
    void setY2(float value);
    
    float getX1() const;
    float getY1() const;
    float getX2() const;
    float getY2() const;
    
    bool isEmpty();
    bool isInside(float x, float y);
    
    void lerp(const Rect & rect, float p);
    void erode(float value);                    // TODO:
    void dilate(float value);                   // TODO:
    void transform(const glm::mat4x4 mat);      // TODO:

    bool operator == (const Rect & rect) const;
    bool operator != (const Rect & rect) const;

};

Rect RectLerp(const Rect & rectFrom, const Rect & rectTo, float p);

}