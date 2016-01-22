//
//  cocCore.h
//  Created by Lukasz Karluk on 22/01/2016.
//  http://codeoncanvas.cc
//

//best defined as pre-processor macro...
// #define COC_OF
// #define COC_CI

#pragma once

#if defined( COC_OF )

    #include "cocGlm.h"

#elif defined( COC_CI )

    #include "cinder/app/App.h"

#endif

#include "cocRect.h"

namespace coc {

double getTimeElapsed();
double getTimeElapsedSinceLastFrame();

}