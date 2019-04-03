/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: test_helper.h
 * Time-stamp: <2019-04-04 01:42:39>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#pragma once

#include "./luacob.h"
#include <iostream>

void DoString(luacob::LuaState *state, const char *str) {
  std::cout << str << "\t\t";
  int ret = state->DoString(str);
  std::cout << "ret=" << ret;
  if (ret != 0 && state->IsString(-1)) {
    luacob::LuaObject obj = state->Get(-1);
    std::string val = obj.Value<std::string>();
    std::cout << ", " << val;
  }
  std::cout << std::endl << std::endl;
}
