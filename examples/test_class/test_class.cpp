/* =================================================================
 *
 * Copyright (C) 2018 anonymoussoft.com.  All rights reserved.
 * File: test_class.cpp
 * Time-stamp: <2019-05-09 16:02:57>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./test_derive.h"
#include "./test_final.h"
#include "./test_reference.h"

int main(int argc, char **argv) {
    luacob::LuaState *state = luacob::LuaState::Create();
    state->OpenLibs();

    test_derive(state);
    test_final(state);
    test_reference(state);

    return 0;
}
