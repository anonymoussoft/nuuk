/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: main.cpp
 * Time-stamp: <2019-02-26 10:56:06>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./nuuk.h"

void RegisterAll(luacob::LuaState *state) {
    state->OpenLibs();
    RegisterUI(state);

    return;
}

int main (int argc, char* argv[]) {
    luacob::LuaState *state = luacob::LuaState::Create();
    RegisterAll(state);

    int result = state->DoFile("demo.lua");

    return 0;
}
