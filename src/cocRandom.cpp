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

#include "cocRandom.h"

#if defined( COC_OF )

#include "ofMath.h"

#elif defined( COC_CI )

#include "cinder/Rand.h"

#endif

namespace coc {

//--------------------------------------------------------------
#ifdef COC_OF

float rand(float value) {
    return ofRandom(value);
}

#endif

#ifdef COC_CI

float rand(float value) {
    return ci::Rand::randFloat(value);
}

#endif

//--------------------------------------------------------------
#ifdef COC_OF

float rand(float value1, float value2) {
    return ofRandom(value1, value2);
}

#endif

#ifdef COC_CI

float rand(float value1, float value2) {
    return ci::Rand::randFloat(value1, value2);
}

//--------------------------------------------------------------
bool randBool(float scale) {
    return coc::rand(1.0) < scale;
}

#endif

}
