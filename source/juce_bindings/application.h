/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: application.h
 * Time-stamp: <2019-02-28 06:32:42>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_APPLICATION_H_
#define NUUK_SOURCE_JUCE_BINDINGS_APPLICATION_H_

#include "./nuuk.h"
#include "./juce.h"

class LApplication: public juce::JUCEApplication {
 public:
    LUACOB_DECLARE_CLASS(LApplication)

 public:
    const juce::String getApplicationName() override {
        return ProjectInfo::projectName;
    };

    const juce::String getApplicationVersion() override {
        return ProjectInfo::versionString;
    };

    void initialise (const juce::String& commandLine) override {
    }

    void shutdown() override {
    }

 public:
    void quit();

    void systemRequestedQuit();
};

#endif  // NUUK_SOURCE_JUCE_BINDINGS_APPLICATION_H_
