/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: application.h
 * Time-stamp: <2019-02-26 10:54:46>
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
    NUUK_BEGIN_CLASS_BINDINGS("Application", LApplication)
        NUUK_CLASS_BIND_FUNCTION("quit", &LApplication::quit)
    NUUK_END_CLASS_BINDINGS()

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

 public:
    static LUA_OBJ_TYPE CreateFromScript() {
        LApplication *dw = new LApplication();

        return ReturnToScript(dw);
    }
};

#endif  // NUUK_SOURCE_JUCE_BINDINGS_APPLICATION_H_
