/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: document_window.h
 * Time-stamp: <2019-03-14 09:49:27>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./document_window.h"


// LDocumentWindow::LDocumentWindow()
//     : DocumentWindow("",
//           juce::Colours::lightgrey,
//           juce::DocumentWindow::allButtons,
//           false) {
// }

LDocumentWindow *LDocumentWindow::LuacobCreateObj() {
    return nullptr;
}

void LDocumentWindow::LuacobDestroyObj(LDocumentWindow *obj) {
    if (obj != nullptr) {
        delete obj;
    }
}

LUACOB_BIND_CLASS_BEGIN("DocumentWindow", LDocumentWindow)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setName)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setIcon)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setTitleBarHeight)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getTitleBarHeight)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setTitleBarButtonsRequired)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setTitleBarTextCentred)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setMenuBar)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getMenuBarComponent)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setMenuBarComponent)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(closeButtonPressed)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(minimiseButtonPressed)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(maximiseButtonPressed)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getCloseButton)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getMinimiseButton)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getMaximiseButton)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(centreWithSize)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setVisible)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setContentOwned)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()
