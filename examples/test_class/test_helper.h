/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: test_helper.h
 * Time-stamp: <2019-04-24 03:21:22>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#pragma once

#include "./luacob.h"
#include <iostream>

void DoString(luacob::LuaState *state, const char *str) {
  int ret = state->DoString(str);
  if (ret != 0 && state->IsString(-1)) {
    luacob::LuaObject obj = state->Get(-1);
    std::string val = obj.Value<std::string>();
    std::cout << "ret=" << ret;
    std::cout << ", " << val << std::endl;
  }
}
