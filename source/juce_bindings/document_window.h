/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: document_window.h
 * Time-stamp: <2019-02-26 11:01:17>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_DOCUMENT_WINDOW_H_
#define NUUK_SOURCE_JUCE_BINDINGS_DOCUMENT_WINDOW_H_

#include "./nuuk.h"
#include "./juce.h"
#include <string>

class LDocumentWindow: public juce::DocumentWindow {
 public:
    LUACOB_DECLARE_CLASS(LDocumentWindow)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_DOCUMENT_WINDOW_H_
