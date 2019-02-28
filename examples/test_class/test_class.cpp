/* =================================================================
 *
 * Copyright (C) 2018 anonymoussoft.com.  All rights reserved.
 * File: test_class.cpp
 * Time-stamp: <2019-02-26 11:00:42>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./luacob.h"
#include <iostream>

class Base {
 public:
    void print() {
        std::cout << "a_ is " << a_ << std::endl;
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
LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION(get);
LUACOB_BIND_CLASS_MEMBER_FUNCTION(print);
LUACOB_BIND_CLASS_MEMBER(a_)
LUACOB_BIND_CLASS_STATIC_MEMBER(s_)
LUACOB_BIND_CLASS_END()

void DoString(luacob::LuaState *state, const char *str) {
    std::cout << str << "\t\t";
    int ret = state->DoString(str);
    std::cout << "ret=" << ret << ", ";
    if (state->IsString(-1)) {
        luacob::LuaObject obj = state->Get(-1);
        std::string val = obj.Value<std::string>();
        std::cout << val;
    }
    std::cout << std::endl << std::endl;
}

int main(int argc, char **argv) {
    luacob::LuaState *state = luacob::LuaState::Create();
    state->OpenLibs();

    LUACOB_REGISTER_CLASS(state, Foo);
    std::cout << "register end" << std::endl;
    DoString(state, "print(type(foo))");
    DoString(state, "print(foo.tt)");
    DoString(state, "f = foo()");
    // DoString(state, "f.a = 1");
    DoString(state, "f.b = 2");
    DoString(state, "print(f.a_)");
    DoString(state, "print(f.b)");
    DoString(state, "f:print()");
    DoString(state, "foo.get()");

    DoString(state, "f2 = foo()");
    DoString(state, "f2.a_ = 6");
    DoString(state, "print(f.a_)");
    DoString(state, "print(f2.a_)");
    DoString(state, "foo.s_ = 123");
    DoString(state, "print(foo.s_)");
    DoString(state, "foo.get()");


    return 0;
}
