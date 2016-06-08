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

#include "cinder/app/App.h"

#endif

#include <sstream>
#include <string>
#include <iostream>

namespace coc {

//--------------------------------------------------------------
double getTimeElapsed() {

#if defined( COC_OF )
    return ofGetElapsedTimef();
#elif defined( COC_CI )
    return ci::app::getElapsedSeconds();
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
// copy from OF.

std::string getTimestampString() {
    std::string timeFormat = "%Y-%m-%d-%H-%M-%S-%i";
	return getTimestampString(timeFormat);
}

std::string getTimestampString(const std::string & timestampFormat) {
	std::stringstream str;
	auto now = std::chrono::system_clock::now();
	auto t = std::chrono::system_clock::to_time_t(now);
    std::chrono::duration<double> s = now - std::chrono::system_clock::from_time_t(t);
    int ms = s.count() * 1000;
	auto tm = *std::localtime(&t);
	const int bufsize = 256;
	char buf[bufsize];

	// Beware! an invalid timestamp string crashes windows apps.
	// so we have to filter out %i (which is not supported by vs)
	// earlier.
    
    std::ostringstream msStr;
	msStr << std::fixed << std::setfill('0') << std::setw(3) << ms;
    
	auto tmpTimestampFormat = timestampFormat;
    tmpTimestampFormat = stringReplace(tmpTimestampFormat, "%i", msStr.str());

	if(strftime(buf,bufsize, tmpTimestampFormat.c_str(),&tm) != 0){
		str << buf;
	}
	auto ret = str.str();

    return ret;
}

//--------------------------------------------------------------
// copy from OF.

std::string stringReplace(const std::string & input, const std::string & searchStr, const std::string & replaceStr) {
    std::string str = input;
	auto pos = str.find(searchStr);
	while(pos != std::string::npos){
		str.replace(pos, searchStr.size(), replaceStr);
		pos += replaceStr.size();
		std::string nextfind(str.begin() + pos, str.end());
		auto nextpos = nextfind.find(searchStr);
		if(nextpos==std::string::npos){
			break;
		}
		pos += nextpos;
	}
    return str;
}

}