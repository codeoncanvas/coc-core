					//
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

#pragma once

#if defined( COC_OF )

#define M_PI PI // M_PI is not defined in OF.

#include "cocGlm.h"
#include "ofMath.h"

#elif defined( COC_CI )

#include "cinder/CinderMath.h"

#endif


namespace coc {

float min(float x, float y);
float max(float x, float y);
float clamp(float x, float min = 0, float max = 1);
float abs(float x);
float map(float val, float inMin, float inMax, float outMin, float outMax, bool clamp = false);
float lerp(float a, float b, float amount);

glm::mat4 lookAt(glm::vec3 position, glm::vec3 target, glm::vec3 up = glm::vec3(0, 1, 0));
glm::vec2 perpendicular(glm::vec2 vec);
glm::vec2 direction(float angle, float angleOffset=0);
float angleClockwise(glm::vec2 direction);

}