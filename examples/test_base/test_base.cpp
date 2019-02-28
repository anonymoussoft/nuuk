/* =================================================================
 *
 * Copyright (C) 2018 qingteng<qingteng.me>.  All rights reserved.
 * File: test_base.cpp
 * Time-stamp: <2018-12-10 13:07:19>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./luacob.h"

#include <iostream>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    lua_State *L = luaL_newstate();
    // luaL_openlibs(L);

    const char *script = "print(os.date())";

    lua_State *L1 = lua_newthread(L);

    int status = luaL_loadbuffer(L1, script, strlen(script), "test_script");
    if (status == 0) {
        lua_pushstring(L1, "test_name");
        lua_call(L1, 1, 1);
    }

    std::cout << "begin2" << std::endl;

    const char *script2 = "print([[hello]])";

    lua_State *L2 = lua_newthread(L);

    int status2 = luaL_loadbuffer(L2, script2, strlen(script2), "test_script");
    if (status2 == 0) {
        lua_pushstring(L2, "test_name");
        lua_call(L2, 1, 1);
    }

    return 0;
}
