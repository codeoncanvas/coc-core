//
//  cocRandom.cpp
//  ParticleUniformDistribution
//
//  Created by Lukasz Karluk on 5/04/2016.
//
//

#include "cocRandom.h"

namespace coc {

//--------------------------------------------------------------
#ifdef COC_OF

float rand(float value) {
    return ofRandom(value);
}

#endif

#ifdef COC_CI

float rand(float value) {
    //
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
    //
}

#endif

}