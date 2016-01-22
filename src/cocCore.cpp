//
//  cocCore.cpp
//  Created by Lukasz Karluk on 22/01/2016.
//  http://codeoncanvas.cc
//

#include "cocCore.h"

#if defined( COC_OF )

    #include "ofUtils.h"
    #include "ofAppRunner.h"

#elif defined( COC_CI )

    //

#endif

namespace coc {

//--------------------------------------------------------------
double getTimeElapsed() {

#if defined( COC_OF )
    return ofGetElapsedTimef();
#elif defined( COC_CI )
    return 0; // TODO: add cinder equivalent.
#endif

}

//--------------------------------------------------------------
double getTimeElapsedSinceLastFrame() {

#if defined( COC_OF )
    return ofGetLastFrameTime();
#elif defined( COC_CI )
    return 0; // TODO: add cinder equivalent.
#endif

}

//--------------------------------------------------------------

}