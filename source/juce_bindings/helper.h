/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: helper.h
 * Time-stamp: <2019-02-26 10:55:02>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */



template<typename T>
class L##T: public T {
};

#define NUUK_BEGIN_CLASS_BINDINGS(classname)  \
    void nuuk_register_##classname(LuaState* state) {  \
    LuaObject meta_tbl = state->GetGlobalVars().CreateTable(“#classname_mt”);  \
    meta_tbl.SetObject(“__index”, meta_tbl);

#define NUUK_CLASS_BIND_FUNCTION(name, func)     \
    meta_tbl.RegisterObjectDirect(name, (Ninja*)0, func);

#define NUUK_CLASS_BIND_MEMBER(name, member)           \
    LPCD::PropertyCreate(meta_tbl, name, member)

#define NUUK_END_CLASS_BINDINGS()               \
    }                                           \
        }

#define NUUK_REGISTER_CLASS(classname)          \
    nuuk_register_##classname();
