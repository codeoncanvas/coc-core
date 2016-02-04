//
//  cocRect.cpp
//  ScrollViewSample
//
//  Created by Lukasz Karluk on 2/02/2016.
//
//

#include "cocRect.h"
#include "cocMath.h"

namespace coc {

//--------------------------------------------------------------
#ifdef COC_OF

void Rect::setX(float value) {
    RectBase::setX(value);
}
    
#endif

#ifdef COC_CI

void Rect::setX(float value) {
    float w = getW();
    x1 = value;
    x2 = x1 + w;
}
    
#endif

//--------------------------------------------------------------
#ifdef COC_OF

void Rect::setY(float value) {
    RectBase::setY(value);
}
    
#endif

#ifdef COC_CI
    
void Rect::setY(float value) {
    float h = getH();
    y1 = value;
    y2 = y1 + h;
}

#endif    

//--------------------------------------------------------------
#ifdef COC_OF
    
void Rect::setW(float value) {
    setWidth(value);
}
    
#endif

#ifdef COC_CI

void Rect::setW(float value) {
    x2 = x1 + value;
}
    
#endif

//--------------------------------------------------------------
#ifdef COC_OF
    
void Rect::setH(float value) {
    setHeight(value);
}
    
#endif

#ifdef COC_CI

void Rect::setH(float value) {
    y2 = y1 + value;
}
    
#endif

//--------------------------------------------------------------
#ifdef COC_OF

float Rect::getX() const {
    return RectBase::getX();
}
    
#endif

#ifdef COC_CI

float Rect::getX() const {
    return x1;
}
    
#endif

//--------------------------------------------------------------
#ifdef COC_OF

float Rect::getY() const {
    return RectBase::getY();
}
    
#endif

#ifdef COC_CI
    
float Rect::getY() const {
    return y1;
}
    
#endif
    
//--------------------------------------------------------------
float Rect::getW() const {
    return getWidth();
}
    
//--------------------------------------------------------------
float Rect::getH() const {
    return getHeight();
}

//--------------------------------------------------------------
#ifdef COC_OF

void Rect::setX1(float value) {
    x = value;
}

#endif

#ifdef COC_CI

void Rect::setX1(float value) {
    x1 = value;
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

void Rect::setY1(float value) {
    y = value;
}

#endif

#ifdef COC_CI

void Rect::setY1(float value) {
    y1 = value;
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

void Rect::setX2(float value) {
    width = value - x;
}

#endif

#ifdef COC_CI

void Rect::setX2(float value) {
    x2 = value;
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

void Rect::setY2(float value) {
    height = value - y;
}

#endif

#ifdef COC_CI

void Rect::setY2(float value) {
    y2 = value;
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

float Rect::getX1() const {
    return x;
}
    
#endif

#ifdef COC_CI

float Rect::getX1() const {
    return RectBase::getX1();
}
    
#endif
    
//--------------------------------------------------------------
#ifdef COC_OF

float Rect::getY1() const {
    return y;
}
    
#endif

#ifdef COC_CI

float Rect::getY1() const {
    return RectBase::getY1();
}
    
#endif
    
//--------------------------------------------------------------
#ifdef COC_OF

float Rect::getX2() const {
    return x + width;
}
    
#endif

#ifdef COC_CI

float Rect::getX2() const {
    return RectBase::getX2();
}
    
#endif

//--------------------------------------------------------------
#ifdef COC_OF

float Rect::getY2() const {
    return y + height;
}
    
#endif

#ifdef COC_CI

float Rect::getY2() const {
    return RectBase::getY2();
}
    
#endif

//----------------------------------------------------------
bool Rect::isEmpty() {

    bool bEmpty = true;
    bEmpty = (getW() == 0);
    bEmpty = (getH() == 0);
    return bEmpty;
}

//----------------------------------------------------------
#ifdef COC_OF

bool Rect::isInside(float x, float y) {
    return inside(x, y);
}

#endif

#ifdef COC_CI

bool Rect::isInside(float x, float y) {
    return contains(glm::vec2(x, y));
}

#endif

//----------------------------------------------------------
void Rect::lerp(const Rect & rect, float p) {

    float _x1 = coc::lerp(getX1(), rect.getX1(), p);
    float _x2 = coc::lerp(getX2(), rect.getX2(), p);
    float _y1 = coc::lerp(getY1(), rect.getY1(), p);
    float _y2 = coc::lerp(getY2(), rect.getY2(), p);

    setX1(_x1);
    setX2(_x2);
    setY1(_y1);
    setY2(_y2);
}

//----------------------------------------------------------
bool Rect::operator == (const Rect & rect) const {
    bool bSame = true;
    bSame = bSame && (getX1() == rect.getX1());
    bSame = bSame && (getX2() == rect.getX2());
    bSame = bSame && (getY1() == rect.getY1());
    bSame = bSame && (getY2() == rect.getY2());
    return bSame;
}

bool Rect::operator != (const Rect & rect) const {
	return ((*this == rect) == false);
}
    //----------------------------------------------------------
    
#ifdef COC_OF

void Rect::setRect( RectBase rect ) {
    setX(rect.x);
    setY(rect.y);
    setW(rect.width);
    setH(rect.height);
}

#endif

#ifdef COC_CI

void Rect::setRect( RectBase rect ) {
    setX1(rect.x1);
    setY1(rect.y1);
    setX2(rect.x2);
    setY2(rect.y2);
}
    
#endif

//----------------------------------------------------------
Rect RectLerp(const Rect & rectFrom, const Rect & rectTo, float p) {
    Rect rect = rectFrom;
    rect.lerp(rectTo, p);
    return rect;
}



}//namespace coc
