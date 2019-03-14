/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: application.cpp
 * Time-stamp: <2019-03-14 09:50:15>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./application.h"

LUACOB_BIND_CLASS_BEGIN("Application", LApplication)
BEGINLUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(moreThanOneInstanceAllowed)
// LUACOB_BIND_CLASS_MEMBER_FUNCTION(anotherInstanceStarted)
// LUACOB_BIND_CLASS_MEMBER_FUNCTION(systemRequestedQuit)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(suspended)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(resumed)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()

void LApplication::quit() {
    JUCEApplicationBase::quit();
    return;
}

void LApplication::systemRequestedQuit() {
    JUCEApplicationBase::quit();
    return;
}
