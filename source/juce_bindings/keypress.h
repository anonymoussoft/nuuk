/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: keypress.h
 * Time-stamp: <2019-02-28 00:45:10>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_KEYPRESS_H_
#define NUUK_SOURCE_JUCE_BINDINGS_KEYPRESS_H_

#include "./nuuk.h"
#include "./juce.h"

class LKeyPress: public juce::KeyPress {
 public:
    LUACOB_DECLARE_CLASS(LKeyPress)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_KEYPRESS_H_
