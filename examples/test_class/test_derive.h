/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: test_derive.h
 * Time-stamp: <2019-04-04 01:44:29>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */
#include "./test_helper.h"

class Base {
 public:
  int print(int a, int b) {
    std::cout << "a_ is " << a_ << std::endl;
    std::cout << "a+b is " << a+b << std::endl;
    return a + b;
  }

 protected:
  int a_;

};

class Foo : public Base {
 public:
  LUACOB_DECLARE_CLASS(Foo)

  public:
  static void get() {
    std::cout << "s_ is " << s_ << std::endl;;
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
LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION(get);
LUACOB_BIND_CLASS_STATIC_MEMBER(s_)
LUACOB_BIND_CLASS_STATIC_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(print);
LUACOB_BIND_CLASS_MEMBER(a_)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()

void test_derive(luacob::LuaState *state) {
  std::cout << "begin test derive" << std::endl;
  LUACOB_REGISTER_CLASS(state, Foo);
  DoString(state, "print(type(foo))");
  DoString(state, "print(foo.tt)");
  DoString(state, "f = foo()");
  // DoString(state, "f.a = 1");
  DoString(state, "f.b = 2");
  DoString(state, "print(f.a_)");
  DoString(state, "print(f.b)");
  DoString(state, "f:print(1, 2)");
  DoString(state, "foo.get()");

  DoString(state, "f2 = foo()");
  DoString(state, "f2.a_ = 6");
  DoString(state, "print(f.a_)");
  DoString(state, "print(f2.a_)");
  DoString(state, "print(f2:print(2, 3))");
  DoString(state, "foo.s_ = 123");
  DoString(state, "print(foo.s_)");
  DoString(state, "foo.get()");
  std::cout << "end test derive" << std::endl;
}
