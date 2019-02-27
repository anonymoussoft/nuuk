/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: binding_helper.h
 * Time-stamp: <2019-02-26 10:55:42>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef BINDINGS_BINDING_HELPER_H_
#define BINDINGS_BINDING_HELPER_H_


template<typename T>
class L##T: public T {
};

#define KS_BEGIN_CLASS_BINDINGS(classname)                            \
    void ks_register_##classname(LuaState* state) {                   \
    LuaObject meta_tbl = state->GetGlobalVars().CreateTable(“#classname_mt”); \
    meta_tbl.SetObject(“__index”, meta_tbl);

#define KS_CLASS_BIND_FUNCTION(name, func)                \
    meta_tbl.RegisterObjectDirect(name, reinterpret_cast<Ninja*>(0), func);

#define KS_CLASS_BIND_MEMBER(name, member)        \
    LPCD::PropertyCreate(meta_tbl, name, member)

#define KS_END_CLASS_BINDINGS()               \
    }                                           \
        }

#define KS_REGISTER_CLASS(classname)          \
    ks_register_##classname();


#endif  // BINDINGS_BINDING_HELPER_H_
