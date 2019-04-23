/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: final.h
 * Time-stamp: <2019-04-24 03:34:58>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./test_helper.h"

class FinalClass final {
 public:
  int Add(int a, int b) {
    return a + b;
  }

  int MultiRet(int a, int &b, std::string &c) {
    a += 1;
    b += 1;
    c += "_ret";
    return 0;
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
LUACOB_BIND_CLASS_MEMBER_FUNCTION(Add);
LUACOB_BIND_CLASS_MEMBER_FUNCTION_MULTIRET(MultiRet, LUACOB_ARGS(luacob::_in, luacob::_out, luacob::_out));
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()

void test_final(luacob::LuaState *state) {
  LUACOB_REGISTER_CLASS(state, FinalClassWrapper);

  const char* script = R"foo(
print("==== test final class begin ====")
local final = FinalClass()
local ret = final:Add(1, 2)
if ret ~= 3 then
    error("unexpected result from final:FuncA")
end

local a = 1
local b = 2
local c = "test"
ret, b, c = final:MultiRet(a, b, c)
if ret ~= 0 then
    error("unexpected result from final:MultiRet, ret=" .. tostring(ret))
end
if b ~= 3 then
    error("unexpected result from final:MultiRet, b=" .. tostring(b))
end
if c ~= "test_ret" then
    error("unexpected result from final:MultiRet, c=" .. tostring(c))
end
print("==== test final class success ====\n")
)foo";

  DoString(state, script);
}
