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