/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: string.h
 * Time-stamp: <2019-02-28 08:53:31>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_STRING_H_
#define NUUK_SOURCE_JUCE_BINDINGS_STRING_H_

#include "./nuuk.h"
#include "./juce.h"

class LString: public juce::String {
 public:
    LUACOB_DECLARE_CLASS(LString)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_STRING_H_
