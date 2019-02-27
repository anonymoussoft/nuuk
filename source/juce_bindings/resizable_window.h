/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: resizable_window.h
 * Time-stamp: <2019-02-26 11:17:55>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_RESIZABLE_WINDOW_H_
#define NUUK_SOURCE_JUCE_BINDINGS_RESIZABLE_WINDOW_H_

#include "./nuuk.h"
#include "./juce.h"

class LResizableWindow: public juce::ResizableWindow {
 public:
    LUACOB_DECLARE_CLASS(LResizableWindow)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_RESIZABLE_WINDOW_H_
