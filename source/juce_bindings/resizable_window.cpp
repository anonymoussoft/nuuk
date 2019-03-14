/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: resizable_window.cpp
 * Time-stamp: <2019-03-14 09:50:55>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./resizable_window.h"

LUACOB_BIND_CLASS_BEGIN("ResizableWindow", LResizableWindow)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getBackgroundColour)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBackgroundColour)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setResizable)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isResizable)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setResizeLimits)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setDraggable)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isDraggable)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getConstrainer)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setConstrainer)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBoundsConstrained)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isFullScreen)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setFullScreen)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isMinimised)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setMinimised)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isKioskMode)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getWindowStateAsString)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(restoreWindowStateFromString)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getContentComponent)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setContentOwned)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setContentNonOwned)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(clearContentComponent)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setContentComponentSize)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getBorderThickness)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getContentComponentBorder)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()
