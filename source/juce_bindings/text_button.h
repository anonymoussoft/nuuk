/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: text_button.h
 * Time-stamp: <2019-02-26 11:36:28>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_TEXT_BUTTON_H_
#define NUUK_SOURCE_JUCE_BINDINGS_TEXT_BUTTON_H_

#include "./nuuk.h"
#include "./juce.h"

class LTextButton: public juce::TextButton {
 public:
    LUACOB_DECLARE_CLASS(LTextButton)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_TEXT_BUTTON_H_
