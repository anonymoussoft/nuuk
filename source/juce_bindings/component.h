/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: component.h
 * Time-stamp: <2019-03-07 09:48:15>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_COMPONENT_H_
#define NUUK_SOURCE_JUCE_BINDINGS_COMPONENT_H_

#include "./nuuk.h"
#include "./juce_hooks.h"

class LComponent: public juce::Component {
 public:
    LUACOB_DECLARE_CLASS(LComponent)
 public:
};

#endif  // NUUK_SOURCE_JUCE_BINDINGS_COMPONENT_H_
