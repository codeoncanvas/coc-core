//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://codeoncanvas.cc
//
// Created by Rene Christen on 28/01/2016.
// Copyright (c) 2016, Code on Canvas Pty Ltd
//

#include "cocMath.h"

namespace coc {

//--------------------------------------------------------------
#ifdef COC_OF

float min(float x, float y) {
    return MIN(x, y);
}

#endif

#ifdef COC_CI

float min(float x, float y) {
    return ci::math<float>::min( x, y );
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

float max(float x, float y) {
    return MAX(x, y);
}

#endif

#ifdef COC_CI

float max(float x, float y) {
    return ci::math<float>::max( x, y );
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

float clamp(float x, float min, float max) {
    return ofClamp(x, min, max);
}

#endif

#ifdef COC_CI

float clamp(float x, float min, float max) {
    return ci::math<float>::clamp( x, min, max );
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

float abs(float x) {
    return ABS(x);
}

#endif

#ifdef COC_CI

float abs(float x) {
    return ci::math<float>::abs( x );
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

float map(float val, float inMin, float inMax, float outMin, float outMax, bool clamp) {
    return ofMap(val, inMin, inMax, outMin, outMax, clamp);
}

#endif

#ifdef COC_CI

float map(float val, float inMin, float inMax, float outMin, float outMax, bool clamp) {
    float outVal = ci::lmap<float>( val, inMin, inMax, outMin, outMax );
    if( clamp ){
        if(outMax < outMin) {
            if(outVal < outMax) {
                outVal = outMax;
            } else if(outVal > outMin) {
                outVal = outMin;
            }
        }else{
            if(outVal > outMax){
                outVal = outMax;
            } else if(outVal < outMin) {
                outVal = outMin;
            }
        }
    }
	return outVal;
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

float lerp(float a, float b, float amount) {
    return ofLerp(a, b, amount);
}

#endif

#ifdef COC_CI

float lerp(float a, float b, float amount) {
    return ci::lerp(a, b, amount);
}

#endif

//--------------------------------------------------------------
glm::mat4 lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 upTemp) {

    glm::vec3 look = target - position;
    look = normalize(look);

    glm::vec3 right = cross(upTemp, look); // cross mult with temp up vector.
    right = normalize(right);

    glm::vec3 up = cross(look, right);
    up = normalize(up);
    
    glm::mat4 lookAt;
    lookAt[0] = glm::vec4(right, 0.0);
    lookAt[1] = glm::vec4(up, 0.0);
    lookAt[2] = glm::vec4(look, 0.0);
    lookAt[3] = glm::vec4(0.0, 0.0, 0.0, 1.0);
    
    return lookAt;
}

float angleClockwise(glm::vec2 direction) {

    float angle = atan2(direction.y, direction.x);
    angle += M_PI * 0.5;
    if(angle < 0.0) {
        angle += M_PI * 2;
    } else if(angle > M_PI * 2) {
        angle -= M_PI * 2;
    }
    return angle;
}

}