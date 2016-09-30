/**
 *
 *      ┌─┐╔═╗┌┬┐┌─┐
 *      │  ║ ║ ││├┤
 *      └─┘╚═╝─┴┘└─┘
 *   ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
 *   │  ├─┤║║║└┐┌┘├─┤└─┐
 *   └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
 *
 * Copyright (c) 2016 Code on Canvas Pty Ltd, http://CodeOnCanvas.cc
 *
 * This software is distributed under the MIT license
 * https://tldrlegal.com/license/mit-license
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code
 *
 **/

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

    Rect();
    Rect(RectBase rect);
	Rect(float x1, float y1, float x2, float y2);
	Rect(const glm::vec2 & v1, const glm::vec2 & v2);

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

    bool isEmpty() const;
    bool isInside(float x, float y) const;

    void fitInto(const Rect & rect, bool bFill=false);
    void lerp(const Rect & rect, float p);
    void grow(float amount);
    
    void transform(const glm::mat4x4 mat);      // TODO:
    glm::mat4 getTransform(const Rect & rect);

    bool operator == (const Rect & rect) const;
    bool operator != (const Rect & rect) const;

    void setRect( RectBase );

};

Rect RectFit(const Rect & rectFrom, const Rect & rectTo, bool bFill=true);
Rect RectLerp(const Rect & rectFrom, const Rect & rectTo, float p);
Rect RectGrow(const Rect & rectToGrow, float amount);

}
