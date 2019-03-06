/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: nuuk.cpp
 * Time-stamp: <2019-03-03 20:12:11>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./juce_bindings/juce_hooks.h"
//#include "./juce_bindings/string.h"
//#include "./juce_bindings/application.h"
#include "./juce_bindings/component.h"
//#include "./juce_bindings/document_window.h"

void RegisterUI(luacob::LuaState *state) {
    state->OpenLibs();
    // LUACOB_REGISTER_CLASS(state, LString);
    LUACOB_REGISTER_CLASS(state, LComponent);
    // LUACOB_REGISTER_CLASS(state, LApplication);
    // LUACOB_REGISTER_CLASS(state, LDocumentWindow);

    return;
}
