#pragma once

//best defined as pre-processor macro...
// #define COC_OF
// #define COC_CI

#if defined( COC_OF )

#include "ofMain.h"
#include "cocGlm.h"

#elif defined( COC_CI )

#include "cinder/app/App.h"

#endif