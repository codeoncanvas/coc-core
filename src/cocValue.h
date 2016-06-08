//
//	    ┌─┐╔═╗┌┬┐┌─┐
//      │  ║ ║ ││├┤
//      └─┘╚═╝─┴┘└─┘
//	 ┌─┐┌─┐╔╗╔┬  ┬┌─┐┌─┐
//	 │  ├─┤║║║└┐┌┘├─┤└─┐
//	 └─┘┴ ┴╝╚╝ └┘ ┴ ┴└─┘
//	http://codeoncanvas.cc
//
// Created by Rene Christen on 28/01/2016.
// Copyright (c) 2016, Code on Canvas Pty Ltd
//

#pragma once

namespace coc {

template <class T>
class Value {

public:
    
    Value(const T & value=0) {
        valueClean = value;
        valueDirty = value;
        bValueChanged = false;
        bDirty = false;
    }

    Value(const Value & copy) {

        // just doing a straight copy.
        // there is an option to override this behaviour
        // and do something tricky dicky.

        valueClean = copy.valueClean;
        valueDirty = copy.valueDirty;
        bValueChanged = copy.bValueChanged;
        bDirty = copy.bDirty;
    }

    //--------------------------------------------------------------
    void operator = (const T & value) {
        setValue(value);
    }

    void operator = (const Value & value) {
        setValue(value.getValue());
    }

    //--------------------------------------------------------------
    bool operator == (const T & value) const {
        return (getValue() == value);
    }

    bool operator == (const Value & value) const {
        return (getValue() == value.getValue());
    }

    //--------------------------------------------------------------
    T update() {
        bValueChanged = (valueClean != valueDirty);
        valueClean = valueDirty;
        bDirty = false;
        return valueClean;
    }

    //--------------------------------------------------------------
    void setValue(T value) {
        valueDirty = value;
        bDirty = true;
    }
    
    operator T() const {
        return getValue();
    }

    const T & getValue() const {
        if(bDirty == true) {
            return valueDirty;
        }
        return valueClean;
    }

    T & getValueClean() {
        return valueClean;
    }

    T & getValueDirty() {
        return valueDirty;
    }

    bool hasChanged() const {
        if(bDirty == true) {
            return (valueClean != valueDirty);
        }
        return bValueChanged;
    }
    
private:

    T valueClean;
    T valueDirty;
    bool bValueChanged;
    bool bDirty;
    
};

}