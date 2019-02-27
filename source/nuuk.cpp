/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: nuuk.cpp
 * Time-stamp: <2019-02-26 11:42:02>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./juce_bindings/application.h"
#include "./juce_bindings/document_window.h"

void RegisterUI() {
    LUACOB_REGISTER_CLASS(state, LComponent);
    NUUK_REGISTER_CLASS(state, LApplication);
    NUUK_REGISTER_CLASS(state, LDocumentWindow);

    return;
}
