/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: toplevel_window.cpp
 * Time-stamp: <2019-02-26 11:23:45>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./toplevel_window.h"

LUACOB_BIND_CLASS_BEGIN("TopLevelWindow", LTopLevelWindow)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isActiveWindow)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(centreAroundComponent)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setDropShadowEnabled)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isDropShadowEnabled)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setUsingNativeTitleBar)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isUsingNativeTitleBar)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getNumTopLevelWindows)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getTopLevelWindow)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getActiveTopLevelWindow)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(addToDesktop)
//LUACOB_BIND_CLASS_MEMBER_FUNCTION(addToDesktop)
LUACOB_BIND_CLASS_END()
