/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: button.h
 * Time-stamp: <2019-02-26 11:27:01>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_BUTTON_H_
#define NUUK_SOURCE_JUCE_BINDINGS_BUTTON_H_

#include "./nuuk.h"
#include "./juce.h"

class LButton: public juce::Button {
 public:
    LUACOB_DECLARE_CLASS(LButton)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_BUTTON_H_
