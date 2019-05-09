/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: test_derive.h
 * Time-stamp: <2019-05-09 15:35:10>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */
#include "./test_helper.h"

class Base {
 public:
  int Add(int a, int b) {
    return a + b;
  }

 protected:
  int a_;

};

class Foo : public Base {
 public:
  LUACOB_DECLARE_CLASS(Foo)

  public:
  static std::string SGet() {
    return "static_ret";
  }
  static int SGet_s_() {
    return s_;
  }

  static int s_;
};

int Foo::s_ = 55;

Foo *Foo::LuacobCreateObj() {
  Foo *f = new Foo();
  f->a_ = 11;
  return f;
}

void Foo::LuacobDestroyObj(Foo *obj) {
  if (obj != nullptr) {
    delete obj;
  }
}

LUACOB_BIND_CLASS_BEGIN("foo", Foo)
LUACOB_BIND_CLASS_STATIC_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION(SGet);
LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION(SGet_s_);
LUACOB_BIND_CLASS_STATIC_MEMBER(s_)
LUACOB_BIND_CLASS_STATIC_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(Add);
LUACOB_BIND_CLASS_MEMBER(a_)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()

void test_derive(luacob::LuaState *state) {
  LUACOB_REGISTER_CLASS(state, Foo);

  const char* script = R"foo(
print("==== test derived class begin ====")
local f = foo()
if f.a_ ~= 11 then
    error("read member failed, a_=" .. tostring(f.a_))
end
f.b = 2
if f.b ~= 2 then
    error("write extra member failed")
end
local c = f:Add(1, 2)
if c ~= 3 then
    error("call Add failed")
end
local ret = foo.SGet()
if ret ~= "static_ret" then
    error("call static SGet() failed")
end

local f2 = foo()
f2.a_ = 6
if f2.a_ ~=6 or f.a_ ~= 11 then
    error("write member failed")
end

foo.s_ = 123
ret = foo.SGet_s_()
if ret ~= 123 then
    error("write static member failed")
end


print("==== test derived class success ====\n")

)foo";

  DoString(state, script);
}
