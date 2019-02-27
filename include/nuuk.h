/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: nuuk.h
 * Time-stamp: <2019-02-26 10:57:30>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */


#ifndef NUUK_INCLUDE_NUUK_H_
#define NUUK_INCLUDE_NUUK_H_

#include "./luastate_manager.h"

#define LUA_OBJ_TYPE LuaPlus::LuaObject

#define CLASS_METATABLE_NAME(classname) "__##classname##_mtbl"

template <typename T>
static LuaPlus::LuaObject ReturnToScript(T *value) {
    LuaPlus::LuaState *state = LuaStateManager::Get();

    LuaPlus::LuaObject ins;
    ins.AssignNewTable(state);

    // assign the C++ instance pointer to the lua instance
    ins.SetLightUserdata("__object", reinterpret_cast<void*>(value));

    // assign the metatable to the new Lua instance table
    LuaPlus::LuaObject mtbl =
            state->GetGlobals().GetByName(CLASS_METATABLE_NAME(T));
    ins.SetMetatable(mtbl);

    return ins;
}

#define NUUK_BEGIN_CLASS_BINDINGS(bindname, classname)                   \
    static void nuuk_register(LuaPlus::LuaState *state) {          \
    typedef classname _classtype;                                     \
    LuaPlus::LuaObject globals = state->GetGlobals();               \
    globals.RegisterDirect(bindname, &classname::CreateFromScript); \
                                                                        \
    LuaPlus::LuaObject meta_tbl = state->GetGlobals()                \
                         .CreateTable(CLASS_METATABLE_NAME(classname)); \
    meta_tbl.SetObject("__index", meta_tbl);

#define NUUK_CLASS_BIND_FUNCTION(name, func)  \
    meta_tbl.RegisterObjectDirect(                      \
        name, reinterpret_cast<_classtype *>(0), func); \

#define NUUK_CLASS_BIND_SUPPER_FUNCTION(name, super_classtype, func) \
    meta_tbl.RegisterObjectDirect(                      \
        name, reinterpret_cast<super_classtype *>(0), func); \

#define NUUK_CLASS_BIND_MEMBER(name, member)        \
    LuaPlus::LPCD::PropertyCreate(meta_tbl, name, member)

#define NUUK_END_CLASS_BINDINGS()               \
        }

#define NUUK_REGISTER_CLASS(state, classname) \
    classname::nuuk_register(state);


void RegisterUI(LuaPlus::LuaState *state);


#endif  // NUUK_INCLUDE_NUUK_H_
