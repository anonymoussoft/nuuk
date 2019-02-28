/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: label.h
 * Time-stamp: <2019-02-28 00:56:33>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_LABEL_H_
#define NUUK_SOURCE_JUCE_BINDINGS_LABEL_H_

#include "./nuuk.h"
#include "./juce.h"

class LLabel: public juce::Label {
 public:
    LUACOB_DECLARE_CLASS(LLabel)
    public:
};

#endif  // NUUK_SOURCE_JUCE_BINDINGS_LABEL_H_
