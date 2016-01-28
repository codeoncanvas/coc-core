//
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://CodeOnCanvas.cc
//
//  cocCore.h
//  Created by Lukasz Karluk on 22/01/2016.
//  http://codeoncanvas.cc
//

#pragma once

#if !defined(COC_OF) && !defined(COC_CI)
#error Must define COC_OF or COC_CI!
#endif

#if defined( COC_OF )

#include "cocGlm.h"

typedef OF_ASPECT_RATIO_IGNORE COC_ASPECT_RATIO_IGNORE;
typedef OF_ASPECT_RATIO_KEEP COC_ASPECT_RATIO_KEEP;
typedef OF_ASPECT_RATIO_KEEP_BY_EXPANDING COC_ASPECT_RATIO_KEEP_BY_EXPANDING

#elif defined( COC_CI )

enum cocAspectRatioMode {
	COC_ASPECT_RATIO_IGNORE            = 0,
	COC_ASPECT_RATIO_KEEP              = 1,
	COC_ASPECT_RATIO_KEEP_BY_EXPANDING = 2,
};

#endif

#include "cocMath.h"
#include "cocRect.h"

namespace coc {

double getTimeElapsed();
double getTimeElapsedSinceLastFrame();

}