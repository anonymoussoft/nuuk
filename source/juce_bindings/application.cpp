/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: application.cpp
 * Time-stamp: <2019-02-26 10:55:14>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./application.h"

void LApplication::quit() {
    JUCEApplicationBase::quit();
    return;
}

void LApplication::systemRequestedQuit() {
    JUCEApplicationBase::quit();
    return;
}
