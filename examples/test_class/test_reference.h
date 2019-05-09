/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: test_reference.cpp
 * Time-stamp: <2019-05-10 04:16:41>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./test_helper.h"

class RefClass {
 public:
  LUACOB_DECLARE_CLASS(RefClass)

 public:
  RefClass() {
    a_ = "init";
  }

  bool MultiRet(int p1, int &p2, std::string p3, std::string &p4, RefClass &f) {
    p1 += 1;
    p2 += 2;
    p3 += "_tail_3";
    p4 += "_tail_4";
    f.a_ += "_tail";

    return true;
  }

  unsigned long long Addr() {
    return reinterpret_cast<unsigned long long>(this);
  }

 public:
  std::string a_;
};

RefClass *RefClass::LuacobCreateObj() {
  RefClass *f = new RefClass();
  return f;
}

void RefClass::LuacobDestroyObj(RefClass *obj) {
  if (obj != nullptr) {
    delete obj;
  }
}

LUACOB_BIND_CLASS_BEGIN("refclass", RefClass)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION_MULTIRET(MultiRet, LUACOB_ARGS(luacob::_in, luacob::_out, luacob::_in, luacob::_out, luacob::_out));
LUACOB_BIND_CLASS_MEMBER_FUNCTION(Addr);
LUACOB_BIND_CLASS_MEMBER(a_)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()

void test_reference(luacob::LuaState *state) {
  LUACOB_REGISTER_CLASS(state, RefClass);

  const char* script = R"foo(
print("==== test class pass by reference begin ====")
local f = refclass()
local address1 = f:Addr();
local f2 = f
ret, p1, p2, _ = f:MultiRet(1, 2, "ab", "cd", f)
if ret ~= true then
    error("wrong ret=" .. tostring(ret))
end
if p1 ~= 4 then
    error("wrong p1=" .. tostring(p1))
end
if p2 ~= "cd_tail_4" then
    error("wrong p2=" .. tostring(p2))
end
if f.a_ ~= "init_tail" then
    error("wrong f.a_=" .. tostring(f.a_))
end

local address2 = f:Addr();
local address3 = f2:Addr();

if address1 ~= address2 or address2 ~= address3 then
    error("wrong address1=" .. tostring(address1) .. ", address2=" .. tostring(address2) .. ", address3=" .. tostring(address3))
end


print("==== test class pass by reference success ====")

)foo";

  DoString(state, script);
}
