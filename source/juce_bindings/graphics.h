/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: graphics.h
 * Time-stamp: <2019-03-30 03:41:15>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_GRAPHICS_H_
#define NUUK_SOURCE_JUCE_BINDINGS_GRAPHICS_H_

#include "./nuuk.h"
#include "./juce_hooks.h"

template<>
using LGraphics = LuacobWrapper<juce::Graphics>;

LUACOB_DECLARE_CLASS

// class LGraphics {
//  public:
//   LUACOB_DECLARE_CLASS(LGraphics);

//  public:
//   juce::Graphics* operator->() { return graphics_; }

//  private:
//   juce::Graphics *graphics_;

// };

#include "./graphics.cpp"

#endif  // NUUK_SOURCE_JUCE_BINDINGS_GRAPHICS_H_
