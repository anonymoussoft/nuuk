/* =================================================================
 *
 * Copyright (C) 2018 anonymoussoft.com.  All rights reserved.
 * File: test_class.cpp
 * Time-stamp: <2019-04-04 01:55:05>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

//#include "./test_derive.h"
#include "./test_final.h"

int main(int argc, char **argv) {
    luacob::LuaState *state = luacob::LuaState::Create();
    state->OpenLibs();

    //test_derive(state);
    test_final(state);

    return 0;
}
