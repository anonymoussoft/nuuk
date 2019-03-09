/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: lookandfeel.h
 * Time-stamp: <2019-03-09 00:42:00>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_LOOKANDFEEL_H_
#define NUUK_SOURCE_JUCE_BINDINGS_LOOKANDFEEL_H_

#include "./nuuk.h"
#include "./juce_hooks.h"

class LLookAndFeel: public juce::LookAndFeel_V4 {
 public:
    LUACOB_DECLARE_CLASS(LLookAndFeel)
    public:
};

#endif  // NUUK_SOURCE_JUCE_BINDINGS_LOOKANDFEEL_H_
