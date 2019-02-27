/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: toplevel_window.h
 * Time-stamp: <2019-02-26 11:19:51>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_TOPLEVEL_WINDOW_H_
#define NUUK_SOURCE_JUCE_BINDINGS_TOPLEVEL_WINDOW_H_

#include "./nuuk.h"
#include "./juce.h"

class LTopLevelWindow: public juce::TopLevelWindow {
 public:
    LUACOB_DECLARE_CLASS(LTopLevelWindow)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_TOPLEVEL_WINDOW_H_
