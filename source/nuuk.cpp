/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: nuuk.cpp
 * Time-stamp: <2019-02-28 02:21:42>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./juce_bindings/application.h"
#include "./juce_bindings/document_window.h"

void RegisterUI(luacob::LuaState *state) {
    state->OpenLibs();
    LUACOB_REGISTER_CLASS(state, LComponent);
    LUACOB_REGISTER_CLASS(state, LApplication);
    LUACOB_REGISTER_CLASS(state, LDocumentWindow);

    return;
}
