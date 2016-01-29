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

#elif defined( COC_CI )

//

#endif

#include "cocConstants.h"
#include "cocMath.h"
#include "cocRect.h"

namespace coc {

double getTimeElapsed();
double getTimeElapsedSinceLastFrame();

}
