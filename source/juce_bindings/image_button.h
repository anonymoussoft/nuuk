/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: image_button.h
 * Time-stamp: <2019-02-26 11:40:14>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_IMAGE_BUTTON_H_
#define NUUK_SOURCE_JUCE_BINDINGS_IMAGE_BUTTON_H_

#include "./nuuk.h"
#include "./juce.h"

class LImageButton: public juce::ImageButton {
 public:
    LUACOB_DECLARE_CLASS(LImageButton)
};


#endif  // NUUK_SOURCE_JUCE_BINDINGS_IMAGE_BUTTON_H_
