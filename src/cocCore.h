//
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://codeoncanvas.cc
//
//  Created by Lukasz Karluk on 22/01/2016.
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
#include "cocRandom.h"
#include "cocRect.h"
#include "cocValue.h"

namespace coc {

double getTimeElapsed();
double getTimeElapsedSinceLastFrame();

std::string getTimestampString();
std::string getTimestampString(const std::string & timestampFormat);

std::string stringReplace(const std::string & input, const std::string & searchStr, const std::string & replaceStr);

}
