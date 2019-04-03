/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: final.h
 * Time-stamp: <2019-04-04 05:31:39>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./test_helper.h"

class FinalClass final {
 public:
  int FuncA(int a, int b) {
    return a + b;
  }

  void FuncB(std::string a) {
    std::cout << "in FuncB " << a << std::endl;
  }

  int FuncC(std::string &a) {
    a = "11";
    std::cout << "a is " << a << std::endl;
    return 2;
  }
};

using FinalClassWrapper = LuacobWrapper<FinalClass>;

template<>
FinalClassWrapper *FinalClassWrapper::LuacobCreateObj() {
  FinalClassWrapper *f = new FinalClassWrapper(new FinalClass());
  return f;
}

template<>
void FinalClassWrapper::LuacobDestroyObj(FinalClassWrapper *obj) {
  if (obj != nullptr) {
    delete obj->get();
    delete obj;
  }
}

LUACOB_BIND_WRAPPER_CLASS_BEGIN("FinalClass", FinalClassWrapper, FinalClass)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(FuncA);
LUACOB_BIND_CLASS_MEMBER_FUNCTION(FuncB);
LUACOB_BIND_CLASS_MEMBER_FUNCTION_MULTIRET(FuncC, LUACOB_ARGS(luacob::_out));
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()

void test_final(luacob::LuaState *state) {
  LUACOB_REGISTER_CLASS(state, FinalClassWrapper);
  DoString(state, "c = FinalClass()");
  DoString(state, "print(c:FuncA(1, 2))");
  DoString(state, "c:FuncB([[cc]])");
  DoString(state, "i = [[22]]");
  DoString(state, "ret, i = c:FuncC(i)");
  DoString(state, "print(ret)");
  DoString(state, "print(i)");
}
