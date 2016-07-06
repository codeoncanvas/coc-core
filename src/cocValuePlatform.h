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

#pragma once

namespace coc
{

template <class T> class ValuePlatform
{

public:

	void setMacWin( const T & valMac, const T & valWin ) {

#if defined( CINDER_COCOA )
		value = valMac;
#elif defined( CINDER_MSW )
		value = valWin;
#endif

	}

	T* getValueRef() { return & value; }
	const T getValue() { return value; }

private:

	T	value;

};//class ValuePlatform

} //namespace coc
