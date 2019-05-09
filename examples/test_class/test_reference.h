/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: test_reference.cpp
 * Time-stamp: <2019-05-09 15:59:14>
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
    std::cout << "construct RefClass, this=" << this << std::endl;
  }

  bool MultiRet(int p1, int &p2, std::string p3, std::string &p4, RefClass &f) {
    p1 += 1;
    p2 += 2;
    p3 += "_tail_3";
    p4 += "_tail_4";
    f.a_ += "_tail";

    std::cout << "call CheckRefClass with f=" << &f.a_ << std::endl;

    return true;
  }

  void Addr() {
    std::cout << "call Addr with this= " << this << std::endl;
  }

 public:
  std::string a_;
};

RefClass *RefClass::LuacobCreateObj() {
  RefClass *f = new RefClass();
  f->a_ = 11;
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
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()

void test_reference(luacob::LuaState *state) {
  LUACOB_REGISTER_CLASS(state, RefClass);

  const char* script = R"foo(
print("==== test class pass by reference begin ====")
local f = refclass()
f:Addr();
ret, p1, p2, p3, p4, f = f:CheckRefClass(1, 2, "ab", "cd", f)
if ret ~= true then
    error("wrong ret=" .. tostring(ret))
end
if p1 ~= 2 then
    error("wrong p1=" .. tostring(p1))
end
if p2 ~= 4 then
    error("wrong p2=" .. tostring(p2))
end
if p3 ~= "ab_tail_3" then
    error("wrong p3=" .. tostring(p3))
end
if p4 ~= "ab_tail_4" then
    error("wrong p4=" .. tostring(p4))
end

f:Addr();


print("==== test class pass by reference end ====")

)foo";

  DoString(state, script);
}
