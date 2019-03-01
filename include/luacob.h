#pragma once

#include <cstddef>
#include <string>
#include <functional>
#include <utility>
#include <string.h>
#include <assert.h>
#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

#define luacob_assert(e) if (!(e)) assert(0)
#define luacob_throw(e) assert(0)

#define lua_fastref(L) luaL_ref(L, LUA_REGISTRYINDEX)
#define lua_fastrefindex(L, idx) (lua_pushvalue(L, idx), luaL_ref(L, LUA_REGISTRYINDEX))
#define lua_fastunref(L, ref) luaL_unref(L, LUA_REGISTRYINDEX, ref)
#define lua_getfastref(L, ref) lua_rawgeti(L, LUA_REGISTRYINDEX, ref)

#define LuacobTo_lua_State(state) ((lua_State *)(state))
#define LuacobTo_LuaState(L) ((luacob::LuaState *)L)

static void stackDump (lua_State *L) {
    int i;
    int top = lua_gettop(L); /* depth of the stack */
    for (i = 1; i <= top; i++) { /* repeat for each level */
        int t = lua_type(L, i);
        switch (t) {
            case LUA_TSTRING: { /* strings */
                printf("'%s'", lua_tostring(L, i));
                break;
            }
            case LUA_TBOOLEAN: { /* Booleans */
                printf(lua_toboolean(L, i) ? "true" : "false");
                break;
            }
            case LUA_TNUMBER: { /* numbers */
                printf("%g", lua_tonumber(L, i));
                break;
            }
            default: { /* other values */
                printf("%s", lua_typename(L, t));
                break;
            }
        }
        printf(" "); /* put a separator */
    }
    printf("\n"); /* end the listing */
}

namespace luacob {

class LuaObject;
class LuaState;

template<typename T> void luacob_pushobj(lua_State *L, T &obj);
template<typename T> T luacob_toobj(lua_State *L, int idx);

// lua index value to native。return stack[i]
template<typename T>
T luacob_l2n(lua_State *L, int i) { return luacob_toobj<T>(L, i); }
template<> inline bool luacob_l2n<bool>(lua_State *L, int i) {
    return lua_toboolean(L, i) != 0; }
template<> inline char luacob_l2n<char>(lua_State *L, int i) {
    return (char)luaL_checkinteger(L, i); }
template<> inline unsigned char luacob_l2n<unsigned char>(lua_State *L, int i) {
    return (unsigned char)luaL_checkinteger(L, i); }
template<> inline short luacob_l2n<short>(lua_State *L, int i) {
    return (short)luaL_checkinteger(L, i); }
template<> inline unsigned short luacob_l2n<unsigned short>(lua_State *L, int i) {
    return (unsigned short)luaL_checkinteger(L, i); }
template<> inline int luacob_l2n<int>(lua_State *L, int i) {
    return (int)luaL_checkinteger(L, i); }
template<> inline unsigned int luacob_l2n<unsigned int>(lua_State *L, int i) {
    return (unsigned int)luaL_checkinteger(L, i); }
template<> inline long luacob_l2n<long>(lua_State *L, int i) {
    return (long)luaL_checkinteger(L, i); }
template<> inline unsigned long luacob_l2n<unsigned long>(lua_State *L, int i) {
    return (unsigned long)luaL_checkinteger(L, i); }
template<> inline long long luacob_l2n<long long>(lua_State *L, int i) {
    return luaL_checkinteger(L, i); }
template<> inline unsigned long long luacob_l2n<unsigned long long>(lua_State *L, int i) {
    return (unsigned long long)luaL_checkinteger(L, i); }
template<> inline float luacob_l2n<float>(lua_State *L, int i) {
    return (float)luaL_checknumber(L, i); }
template<> inline double luacob_l2n<double>(lua_State *L, int i) {
    return luaL_checknumber(L, i); }
template<> inline const char *luacob_l2n<const char*>(lua_State *L, int i) {
    return luaL_checkstring(L, i); }
template<> inline std::string luacob_l2n<std::string>(lua_State *L, int i) {
    size_t len = 0;
    const char *str = luaL_checklstring(L, i, &len);
    return std::string(str, len);
}

// native value push to lua stack
template<typename T>
void luacob_n2l(lua_State *L, T &v) { luacob_pushobj(L, v); }
inline void luacob_n2l(lua_State *L, bool v) { lua_pushboolean(L, v); }
inline void luacob_n2l(lua_State *L, char v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, unsigned char v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, short v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, unsigned short v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, int v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, unsigned int v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, long v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, unsigned long v) { lua_pushinteger(L, v); }
inline void luacob_n2l(lua_State *L, long long v) { lua_pushinteger(L, (lua_Integer)v); }
inline void luacob_n2l(lua_State *L, unsigned long long v) { lua_pushinteger(L, (lua_Integer)v); }
inline void luacob_n2l(lua_State *L, float v) { lua_pushnumber(L, v); }
inline void luacob_n2l(lua_State *L, double v) { lua_pushnumber(L, v); }
inline void luacob_n2l(lua_State *L, char *v) { lua_pushstring(L, v); }
inline void luacob_n2l(lua_State *L, const char *v) { lua_pushstring(L, v); }
inline void luacob_n2l(lua_State *L, void *v) { lua_pushlightuserdata(L, v); }
inline void luacob_n2l(lua_State *L, const void *v) { lua_pushlightuserdata(L, (void*)v); }
inline void luacob_n2l(lua_State *L, const std::string &v) { lua_pushlstring(L, v.c_str(), v.size()); }
inline void luacob_n2l(lua_State *L, lua_CFunction f) { lua_pushcclosure(L, f, 0); }

inline int LuacobAbsIndex(lua_State *L, int idx) {
    int top = lua_gettop(L);
    if (idx < 0 && -idx <= top)
        return idx + top + 1;
    return idx;
}

using LuacobGlobalFunction = std::function<int(lua_State*)>;
using LuacobObjectFunction = std::function<int(void*, lua_State*)>;

template<size_t... Integers, typename return_type, typename... arg_types>
return_type LuacobCallHelper(
    lua_State *L, return_type(*func)(arg_types...), std::index_sequence<Integers...>&&) {
    return (*func)(luacob_l2n<arg_types>(L, Integers + 1)...);
}

template<size_t... Integers, typename return_type, typename class_type, typename... arg_types>
return_type LuacobCallHelper(
    lua_State *L, class_type *obj,
    return_type(class_type::*func)(arg_types...), std::index_sequence<Integers...>&&) {
    return (obj->*func)(luacob_l2n<arg_types>(L, Integers + 1)...);
}

template<typename return_type, typename... arg_types>
LuacobGlobalFunction LuacobAdapter(return_type(*func)(arg_types...)) {
    return [=](lua_State *L) {
        luacob_n2l(L, LuacobCallHelper(L, func, std::make_index_sequence<sizeof...(arg_types)>()));
        return 1;
    };
}

template<typename... arg_types>
LuacobGlobalFunction LuacobAdapter(void(*func)(arg_types...)) {
    return [=](lua_State *L) {
        LuacobCallHelper(L, func, std::make_index_sequence<sizeof...(arg_types)>());
        return 0;
    };
}

template<>
inline LuacobGlobalFunction LuacobAdapter(int(*func)(lua_State *L)) {
    return func;
}

template<typename return_type, typename T, typename... arg_types>
LuacobObjectFunction LuacobAdapter(return_type(T::*func)(arg_types...)) {
    return [=](void *obj, lua_State *L) {
        luacob_n2l(L, LuacobCallHelper(L, (T*)obj, func,
                                       std::make_index_sequence<sizeof...(arg_types)>()));
        return 1;
    };
}

template<typename T, typename... arg_types>
LuacobObjectFunction LuacobAdapter(void(T::*func)(arg_types...)) {
    return [=](void *obj, lua_State *L) {
        LuacobCallHelper(L, (T*)obj, func, std::make_index_sequence<sizeof...(arg_types)>());
        return 0;
    };
}

template<typename T>
LuacobObjectFunction LuacobAdapter(int(T::*func)(lua_State *L)) {
    return [=](void *obj, lua_State *L) {
        T *this_ptr = (T*)obj;
        return (this_ptr->*func)(L);
    };
}

inline void *GetObjectUserdata(lua_State *L) {
    int type = lua_type(L, 1);
    if (type == LUA_TUSERDATA)
        return *(void **)(lua_touserdata(L, 1));
    else if (type == LUA_TTABLE) {
        lua_pushstring(L, "__object");
        lua_rawget(L, 1);

        void *ret;
        int subType = lua_type(L, -1);
        if (subType == LUA_TLIGHTUSERDATA) {
            ret = lua_touserdata(L, -1);
        } else if (subType == LUA_TUSERDATA) {
            ret = *(void **)(lua_touserdata(L, -1));
        } else {
            ret = nullptr;
            luaL_error(L, "The table does not have a userdata member called __object.");
        }
        lua_pop(L, 1);
        return ret;
    } else {
        luaL_argerror(L, 1, "must be userdata or a table with a userdata member called __object");
    }

    return nullptr;
}

int LuacobGlobalFunctionDispatcher(lua_State* L) {
    LuacobGlobalFunction *func = (LuacobGlobalFunction *)lua_touserdata(L, lua_upvalueindex(1));
    if (func != nullptr) {
        return (*func)(L);
    }
    return 0;
}

int LuacobObjectFunctionDispatcher(lua_State* L) {
    void *obj = GetObjectUserdata(L);
    LuacobObjectFunction *func = (LuacobObjectFunction *)lua_touserdata(L, lua_upvalueindex(1));
    if (obj != nullptr && func != nullptr) {
        return (*func)(obj, L);
    }
    return 0;
}

inline int MetatableNewindex(lua_State* L) {
    lua_pushvalue(L, 2);
    lua_rawget(L, lua_upvalueindex(1));
    if (lua_isfunction(L, -1)) {
        if (lua_getupvalue(L, -1, 2)) {
            if (lua_touserdata(L, -1) == (void*)-2) {
                lua_pop(L, 1);
                lua_CFunction f = lua_tocfunction(L, -1);
                lua_getupvalue(L, -1, 1);
                lua_replace(L, 4);
                return f(L);
            }
            lua_pop(L, 1);
        }
        lua_rawset(L, -3);
        return 0;
    } else if (!lua_isnil(L, -1)) {
        lua_pop(L, 1);
        lua_rawset(L, -3);
        return 0;
    }

    lua_pop(L, 1);

    if (!lua_getmetatable(L, -3))
        return 0;

    do {
        lua_getfield(L, -1, "__newindex");
        if (lua_isnil(L, -1)) {
            lua_pop(L, 2);
            lua_rawset(L, -3);
            return 0;
        }

        lua_getupvalue(L, -1, 1);
        lua_pushvalue(L, 2);
        lua_rawget(L, -2);
        if (lua_isfunction(L, -1)) {
            if (lua_getupvalue(L, -1, 2)) {
                if (lua_touserdata(L, -1) == (void*)-2) {
                    lua_pop(L, 1);
                    lua_CFunction f = lua_tocfunction(L, -1);
                    lua_getupvalue(L, -1, 1);
                    lua_replace(L, 4);
                    return f(L);
                }
                lua_pop(L, 2);
            }
            lua_rawset(L, -3);
            return 1;
        } else if (!lua_isnil(L, -1)) {
            lua_pop(L, 4);
            lua_rawset(L, -3);
            return 0;
        }

        lua_pop(L, 3);
        if (!lua_getmetatable(L, 4)) {
            lua_pop(L, 1);
            break;
        }
        lua_remove(L, -2);
    } while (true);

    lua_rawset(L, -3);
    return 0;
}

inline int MetatableIndex(lua_State* L) {
    lua_pushvalue(L, 2);
    lua_rawget(L, lua_upvalueindex(1));
    if (lua_isfunction(L, -1)) {
        if (lua_getupvalue(L, -1, 2)) {
            if (lua_touserdata(L, -1) == (void*)-2) {
                lua_pop(L, 1);
                lua_CFunction f = lua_tocfunction(L, -1);
                lua_getupvalue(L, -1, 1);
                lua_replace(L, 3);
                return f(L);
            }
            lua_pop(L, 1);
        }
        return 1;
    } else if (!lua_isnil(L, -1))
        return 1;

    lua_pop(L, 1);

    if (!lua_getmetatable(L, -2))
        return 0;

    do {
        lua_getfield(L, -1, "__index");
        if (lua_isnil(L, -1))
            return 0;

        lua_getupvalue(L, -1, 1);
        lua_pushvalue(L, 2);
        lua_rawget(L, -2);
        if (lua_isfunction(L, -1)) {
            if (lua_getupvalue(L, -1, 2)) {
                if (lua_touserdata(L, -1) == (void*)-2) {
                    lua_pop(L, 1);
                    lua_CFunction f = lua_tocfunction(L, -1);
                    lua_getupvalue(L, -1, 1);
                    lua_replace(L, 3);
                    return f(L);
                }
                lua_pop(L, 1);
            }
            return 1;
        } else if (!lua_isnil(L, -1))
            return 1;

        lua_pop(L, 3);
        if (!lua_getmetatable(L, 3))
            return 0;
        lua_remove(L, -2);
    } while (true);
}

template <typename Object, typename VarType>
class PropertyHelper {
 public:
    static int PropertyGet(lua_State* L) {
        stackDump(L);
        Object *obj = (Object*)GetObjectUserdata(L);
        void *offset = lua_touserdata(L, 3);
        luacob_n2l(L, *(VarType *)((unsigned char *)obj + (ptrdiff_t)offset));
        return 1;
    }
    static int PropertySet(lua_State* L) {
        stackDump(L);
        Object *obj = (Object*)GetObjectUserdata(L);
        void *offset = lua_touserdata(L, 4);
        *(VarType *)((unsigned char *)obj + (ptrdiff_t)offset) = luacob_l2n<VarType>(L, 3);
        return 0;
    }
};

template <typename VarType>
class GlobalHelper {
 public:
    static int GlobalGet(lua_State *L) {
        stackDump(L);
        void *ptr = lua_touserdata(L, 3);
        luacob_n2l(L, *(VarType *)ptr);
        return 1;
    }
    static int GlobalSet(lua_State *L) {
        stackDump(L);
        void *ptr = lua_touserdata(L, 4);
        *(VarType *)ptr = luacob_l2n<VarType>(L, 3);
        return 1;
    }
};

template <typename Object, typename VarType>
inline void luacob_pushpropertygetclosure(lua_State *L, VarType Object::* var) {
	lua_pushlightuserdata(L, (void*)&(((Object*)0)->*var));
	lua_pushlightuserdata(L, (void*)-2);
	lua_pushcclosure(L, &PropertyHelper<Object, VarType>::PropertyGet, 2);
}


template <typename Object, typename VarType>
inline void luacob_pushpropertysetclosure(lua_State *L, VarType Object::* var) {
	lua_pushlightuserdata(L, (void*)&(((Object*)0)->*var));
	lua_pushlightuserdata(L, (void*)-2);
	lua_pushcclosure(L, &PropertyHelper<Object, VarType>::PropertySet, 2);
}

template <typename VarType>
inline void luacob_pushglobalgetclosure(lua_State *L, VarType *var) {
    lua_pushlightuserdata(L, (void*)var);
	lua_pushlightuserdata(L, (void*)-2);
    lua_pushcclosure(L, &GlobalHelper<VarType>::GlobalGet, 2);
}

template <typename VarType>
inline void luacob_pushglobalsetclosure(lua_State *L, VarType *var) {
    lua_pushlightuserdata(L, (void*)var);
	lua_pushlightuserdata(L, (void*)-2);
    lua_pushcclosure(L, &GlobalHelper<VarType>::GlobalSet, 2);
}

/**
   Representation of a Lua object.
**/
class LuaObject {
 private:
    lua_State *L_;
    int ref_;

 public:
    class LuaFastRefPush {
     public:
        LuaFastRefPush(const LuaObject *self) {
            lua_getfastref(self->L_, self->ref_);
            this->self = self;
        }

        ~LuaFastRefPush() {
            lua_pop(self->L_, 1);
        }

        const LuaObject *self;
    };

#define LUA_FASTREF_PUSH() LuaFastRefPush _frp(this)

 public:
    LuaObject() : L_(nullptr)
                , ref_(LUA_REFNIL) {}
	LuaObject(LuaState *state) throw() : L_(LuacobTo_lua_State(state))
                                       , ref_(LUA_REFNIL) {}
	LuaObject(LuaState *state, int stackIndex) throw() : L_(LuacobTo_lua_State(state)) {
        ref_ = lua_fastrefindex(L_, stackIndex); }
    LuaObject(LuaState *state, bool popTop) throw() : L_(LuacobTo_lua_State(state)) {
        ref_ = popTop ? lua_fastref(L_) : lua_fastrefindex(L_, -1);
    }
    ~LuaObject() { if (L_) lua_fastunref(L_, ref_); }

    LuaObject &operator=(const LuaObject &src) throw() {
        if (L_)
            lua_fastunref(L_, ref_);
        if (src.L_) {
            L_ = src.L_;
            lua_getfastref(L_, src.ref_);
            ref_ = lua_fastref(L_);
        } else {
            L_ = nullptr;
            ref_ = LUA_REFNIL;
        }
        return *this;
    }

 public:
    LuaObject Push(LuaState *state) const {
        lua_State *L = LuacobTo_lua_State(state);
        luacob_assert(L);
        lua_getfastref(L, ref_);
        return LuaObject(state, lua_gettop(L)); }
    const char *TypeName() const {
        luacob_assert(L_); LUA_FASTREF_PUSH();
        return lua_typename(L_, lua_type(L_, -1)); }
    int Type() const {
        luacob_assert(L_); LUA_FASTREF_PUSH(); return lua_type(L_, -1); }
    template<typename T>T Value() {
        luacob_assert(L_); LUA_FASTREF_PUSH(); return luacob_l2n<T>(L_, -1); }

    bool IsValid() const { return L_ != nullptr; };
    bool IsNil() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isnil(L_, -1) != 0; };
    bool IsNone() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isnone(L_, -1) != 0; };
    bool IsBoolean() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isboolean(L_, -1) != 0; };
    bool IsInteger() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_type(L_, -1) == LUA_TNUMBER; };
    bool IsNumber() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_type(L_, -1) == LUA_TNUMBER; };
    bool IsString() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_type(L_, -1) != LUA_TSTRING; };
    bool IsConvertibleToInteger() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isnumber(L_, -1) != 0; };
    bool IsConvertibleToNumber() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isnumber(L_, -1) != 0; };
    bool IsConvertibleToString() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isstring(L_, -1) != 0; };
    bool IsTable() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_istable(L_, -1) != 0; };
    bool IsUserdata() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isuserdata(L_, -1) != 0; };
    bool IsLightUserdata() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_islightuserdata(L_, -1) != 0; };
    bool IsCFunction() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_iscfunction(L_, -1) != 0; };
    bool IsFunction() const {
        if (!L_) return false; LUA_FASTREF_PUSH(); return lua_isfunction(L_, -1) != 0; };

    size_t ObjLen() {
        luacob_assert(L_); LUA_FASTREF_PUSH(); return lua_rawlen(L_, -1); };
    LuaObject GetMetatable() const {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        if (lua_getmetatable(L_, -1))
            return LuaObject(LuacobTo_LuaState(L_), true);
        return LuaObject(LuacobTo_LuaState(L_));
    }
	LuaObject &SetMetatable(const LuaObject &valueObj) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        lua_getfastref(L_, valueObj.ref_);
        lua_setmetatable(L_, -2);
        return *this;
    }

    LuaObject CreateTable(const char *key, int narray = 0, int nrec = 0) const {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        lua_pushstring(L_, key);
        lua_pushvalue(L_, -1);
        lua_createtable(L_, narray, nrec);
        lua_settable(L_, -4);
        lua_gettable(L_, -2);
        return LuaObject(LuacobTo_LuaState(L_), true);
    }

    LuaObject CreateTable(int key, int narray = 0, int nrec = 0) const {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        lua_pushinteger(L_, key);
        lua_pushvalue(L_, -1);
        lua_createtable(L_, narray, nrec);
        lua_settable(L_, -4);
        lua_gettable(L_, -2);
        return LuaObject(LuacobTo_LuaState(L_), true);
    }

    template<typename KeyT> LuaObject &SetNil(const KeyT &key) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        luacob_n2l(L_, key);
        lua_pushnil(L_);
        lua_settable(L_, -3);
        return *this;
    }

    template<typename KeyT> LuaObject &RawSetNil(const KeyT &key) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        luacob_n2l(L_, key);
        lua_pushnil(L_);
        lua_rawset(L_, -3);
        return *this;
    }

    LuaObject &AssignNil() {
        luacob_assert(L_);
        lua_fastunref(L_, ref_);
        lua_pushnil(L_);
        ref_ = lua_fastref(L_);
        return *this;
    }

    LuaObject &AssignNil(LuaState *state);
    template<typename ValueT> LuaObject &Assign(const ValueT &value) {
        luacob_assert(L_);
        lua_fastunref(L_, ref_);
        luacob_n2l(L_, value);
        ref_ = lua_fastref(L_);
        return *this;
    }

    template<typename ValueT> LuaObject &Assign(LuaState *state, const ValueT &value) {
        lua_State *L = LuacobTo_lua_State(state);
        luacob_assert(L);
        if (L_)
            lua_fastunref(L_, ref_);
        L_ = L;
        luacob_n2l(L_, value);
        ref_ = lua_fastref(L_);
        return *this;
    }

    // table manipulation
    LuaObject &AssignNewTable(LuaState *state, int narray = 0, int nrec = 0) {
        if (L_)
            lua_fastunref(L_, ref_);
        L_ = LuacobTo_lua_State(state);
        lua_createtable(L_, narray, nrec);
        ref_ = lua_fastref(L_);
        return *this;
    }

    template<typename KeyT, typename ValueT>
    LuaObject &Set(const KeyT &key, const ValueT &value) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        luacob_n2l(L_, key);
        luacob_n2l(L_, value);
        lua_settable(L_, -3);
        return *this;
    }

    template<typename KeyT, typename ValueT>
    LuaObject &RawSet(const KeyT &key, const ValueT &value) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        luacob_n2l(L_, key);
        luacob_n2l(L_, value);
        lua_rawset(L_, -3);
        return *this;
    }

    template<typename KeyT>
    LuaObject Get(const KeyT &key) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        luacob_n2l(L_, key);
        lua_gettable(L_, -2);
        return LuaObject(LuacobTo_LuaState(L_), true);
    }

    template<typename KeyT>
    LuaObject RawGet(const KeyT &key) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();
        luacob_n2l(L_, key);
        lua_rawget(L_, -2);
        return LuaObject(LuacobTo_LuaState(L_), true);
    }

 protected:
    LuaObject &RegisterHelper(const char *funcName, lua_CFunction function, void *func) {
        luacob_assert(L_);
        int top = lua_gettop(L_);
        lua_pushstring(L_, funcName);
        lua_pushlightuserdata(L_, func);
        lua_pushcclosure(L_, (lua_CFunction)function, 1);
        lua_rawset(L_, top);
        return *this;
    }

 public:
    template <typename Func>
	LuaObject &Register(const char *funcName, Func func) {
        luacob_assert(L_);
        LuacobGlobalFunction *gbl_func = new LuacobGlobalFunction;
        *gbl_func = LuacobAdapter(func);
        LUA_FASTREF_PUSH();
        int top = lua_gettop(L_);
        lua_pushstring(L_, funcName);
        lua_pushlightuserdata(L_, (void *)gbl_func);
        lua_pushcclosure(L_, (lua_CFunction)LuacobGlobalFunctionDispatcher, 1);
        lua_rawset(L_, top);
        return *this;
	}

    template<typename Func>
    LuaObject &RegisterObjectFunction(const char *funcName, Func func) {
        LuacobObjectFunction *obj_func = new LuacobObjectFunction;
        *obj_func = LuacobAdapter(func);
        return RegisterHelper(
            funcName, LuacobObjectFunctionDispatcher, (void *)obj_func);
    }

    template<typename Func>
    LuaObject &RegisterObjectSFunction(const char *funcName, Func func) {
        LuacobGlobalFunction *s_func = new LuacobGlobalFunction;
        *s_func = LuacobAdapter(func);
        return RegisterHelper(
            funcName, LuacobGlobalFunctionDispatcher, (void *)s_func);
    }

    template<typename Object, typename VarType>
    LuaObject &RegisterObjectProperty(const char *name, VarType Object:: *var, bool readonly) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();					// (table)

        lua_pushstring(L_, name);

        lua_getfield(L_, -2, "__index");
        lua_getupvalue(L_, -1, 1);
        lua_getupvalue(L_, -2, 2);
        bool inPlace = lua_toboolean(L_, -1) != 0;
        lua_pop(L_, 1);
        lua_pushvalue(L_, -3);
        luacob_pushpropertygetclosure(L_, var);
        lua_rawset(L_, -3);
        lua_pop(L_, 2);

        if (!readonly) {
            lua_getfield(L_, -2, "__newindex");
            lua_getupvalue(L_, -1, 1);
            lua_getupvalue(L_, -2, 2);
            bool inPlace = lua_toboolean(L_, -1) != 0;
            lua_pop(L_, 1);
            lua_pushvalue(L_, -3);
            luacob_pushpropertysetclosure(L_, var);
            lua_rawset(L_, -3);
            lua_pop(L_, 2);
        }

        lua_pop(L_, 2);

        return *this;
    }

    template<typename VarType>
    LuaObject &RegisterObjectSProperty(const char *name, VarType *var, bool readonly) {
        luacob_assert(L_);
        LUA_FASTREF_PUSH();					// (table)

        lua_pushstring(L_, name);

        lua_getfield(L_, -2, "__index");
        lua_getupvalue(L_, -1, 1);
        lua_getupvalue(L_, -2, 2);
        bool inPlace = lua_toboolean(L_, -1) != 0;
        lua_pop(L_, 1);
        lua_pushvalue(L_, -3);
        luacob_pushglobalgetclosure(L_, var);
        lua_rawset(L_, -3);
        lua_pop(L_, 2);

        if (!readonly) {
            lua_getfield(L_, -2, "__newindex");
            lua_getupvalue(L_, -1, 1);
            lua_getupvalue(L_, -2, 2);
            bool inPlace = lua_toboolean(L_, -1) != 0;
            lua_pop(L_, 1);
            lua_pushvalue(L_, -3);
            luacob_pushglobalsetclosure(L_, var);
            lua_rawset(L_, -3);
            lua_pop(L_, 2);
        }

        lua_pop(L_, 2);

        return *this;
    }
};

/**
   Representation of a Lua state.
**/
class LuaState {
 public:
    LuaState() = delete;
    ~LuaState() = delete;

 public:
    static LuaState *Create() { return LuacobTo_LuaState(luaL_newstate()); }
    static LuaState *Create(lua_Alloc allocFunction, void *userdata) {
        return LuacobTo_LuaState(lua_newstate(allocFunction, userdata)); }
    lua_State *GetCState() {  return LuacobTo_lua_State(this); }
    void OpenLibs() { luaL_openlibs(LuacobTo_lua_State(this)); }
    static void Destroy(LuaState *state)  {
        lua_State *L = LuacobTo_lua_State(state); lua_close(L); }

 public:
    // Querying elements
    int IsNumber(int idx) const { return lua_isnumber(LuacobTo_lua_State(this), idx); }
    int IsString(int idx) const { return lua_isstring(LuacobTo_lua_State(this), idx); }
    int IsCFunction(int idx) const { return lua_iscfunction(LuacobTo_lua_State(this), idx); }
    int IsInteger(int idx) const { return lua_isinteger(LuacobTo_lua_State(this), idx); }
    int IsUserdata(int idx) const { return lua_isuserdata(LuacobTo_lua_State(this), idx); }
    int IsFunction(int idx) const { return lua_isfunction(LuacobTo_lua_State(this), idx); }
    int IsTable(int idx) const { return lua_istable(LuacobTo_lua_State(this), idx); }
    int IsLightUserdata(int idx) const { return lua_islightuserdata(LuacobTo_lua_State(this), idx); }
    int IsNil(int idx) const { return lua_isnil(LuacobTo_lua_State(this), idx); }
    int IsBoolean(int idx) const { return lua_isboolean(LuacobTo_lua_State(this), idx); }
    int IsThread(int idx) const { return lua_isthread(LuacobTo_lua_State(this), idx); }

    // Pushing elements
    LuaObject Push(LuaObject &obj) {
        obj.Push(this);
        return LuaObject(this, lua_gettop(LuacobTo_lua_State(this))); }

    LuaObject Get(int idx) {
        return LuaObject(this, idx);
    }

    // Globals and Registry
    LuaObject GetGlobal(const char *name) {
        lua_State *L = LuacobTo_lua_State(this);
        lua_getglobal(L, name);
        return LuaObject(LuacobTo_LuaState(L), true);
    }
    LuaObject GetGlobals() throw() {
        lua_State *L = LuacobTo_lua_State(this);
        lua_pushglobaltable(L);
        return LuaObject(LuacobTo_LuaState(L), true);
    }
    LuaObject GetRegistry() { return LuaObject(this, LUA_REGISTRYINDEX); }
    int DoString(const char *str) { return luaL_dostring(LuacobTo_lua_State(this), str); };
};

class LuaStateAuto {
 public:
    LuaStateAuto() { state_ = LuaState::Create(); }
    LuaStateAuto(lua_Alloc allocFunction, void *userdata) {
		state_ = LuaState::Create(allocFunction, userdata);
	}
    LuaStateAuto(LuaState *newState) : state_(newState) {}
    LuaStateAuto &operator=(LuaState *newState) {
        Assign(newState);
        return *this;
    }
    ~LuaStateAuto() { Assign(nullptr); }

    operator LuaState*() { return state_; }
    operator const LuaState*() const { return state_; }
    operator LuaState*() const { return state_; }
    LuaState &operator*() { return *state_; }
    const LuaState &operator*() const { return *state_; }
    LuaState *operator->() { return state_; }
    const LuaState *operator->() const { return state_; }
    LuaState *Get() const { return state_; }

 protected:
    void Assign(LuaState *state) {
        if (state_)
            LuaState::Destroy(state_);
        state_ = state;
    }
 protected:
    LuaState *state_;
};

template<typename T>
struct has_member_gc {
    template<typename U>
    static auto check_gc(int) -> decltype(std::declval<U>().__gc(), std::true_type());
    template<typename U> static std::false_type check_gc(...);
    enum { value = std::is_same<decltype(check_gc<T>(0)), std::true_type>::value };
};

template<class T>
typename std::enable_if<has_member_gc<T>::value, void>::type lua_handle_gc(T *obj) { obj->__gc(); }
template<class T>
typename std::enable_if<!has_member_gc<T>::value, void>::type lua_handle_gc(T *obj) { delete obj; }

template<typename T>
int lua_object_gc(lua_State *L) {
    T *obj = luacob_toobj<T*>(L, 1);
    if (obj == nullptr)
        return 0;
    lua_handle_gc(obj);
    return 0;
}

template<>
void luacob_pushobj(lua_State *L, const LuaObject &obj) {
    obj.Push(LuacobTo_LuaState(L));
}

// template<typename T>
// void luacob_pushobj(lua_State *L, T obj) {
//     std::cout << "luacob_pushobj1" << std::endl;
// }

// template<>
// void luacob_pushobj(lua_State *L, LuaObject obj) {
//     std::cout << "luacob_pushobj3" << std::endl;
//     std::cout << "obj is " << obj.TypeName() << std::endl;
//     obj.Push(LuacobTo_LuaState(L));
//     std::cout << "obj is " << obj.TypeName() << std::endl;
// }

template<typename T>
struct has_meta_data {
    template<typename U>
    static auto check_meta(int) -> decltype(std::declval<U>().lua_get_meta_data(), std::true_type());
    template<typename U> static std::false_type check_meta(...);
    enum { value = std::is_same<decltype(check_meta<T>(0)), std::true_type>::value };
};

template<typename T>
T luacob_toobj(lua_State *L, int idx) {
    // static_assert(has_meta_data<typename std::remove_pointer<T>::type>::value,
    //               "T should be declared export !");
    // static_assert(std::is_final<typename std::remove_pointer<T>::type>::value,
    //               "T should be declared final !");
    T obj = nullptr;
    idx = LuacobAbsIndex(L, idx);

    if (lua_istable(L, idx)) {
        lua_pushstring(L, "__object");
        lua_rawget(L, idx);
        obj = (T)lua_touserdata(L, -1);
		lua_pop(L, 1);
    }
    return obj;
}

template<>
LuaObject luacob_toobj(lua_State *L, int idx) {
    return LuaObject(LuacobTo_LuaState(L), idx);
}

template<typename T>
void lua_detach(lua_State *L, T obj) {
    if (obj == nullptr)
        return;

    lua_getfield(L, LUA_REGISTRYINDEX, "__objects__");
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return;
    }

    // stack: __objects__
    if (lua_rawgetp(L, -1, obj) != LUA_TTABLE) {
        lua_pop(L, 2);
        return;
    }

    // stack: __objects__, __shadow_object__
    lua_pushstring(L, "__pointer__");
    lua_pushnil(L);
    lua_rawset(L, -3);

    lua_pushnil(L);
    lua_rawsetp(L, -3, obj);
    lua_pop(L, 2);
}

void luacob_pushfunc(lua_State *L, LuacobGlobalFunction func);
inline void luacob_pushfunc(lua_State *L, lua_CFunction func) { lua_pushcfunction(L, func); }

template<typename T>
void luacob_pushfunc(lua_State *L, T func) {
    luacob_pushfunc(L, LuacobAdapter(func));
}

template<typename T>
void luacob_register_function(lua_State *L, const char *name, T func) {
    luacob_pushfunc(L, func);
    lua_setglobal(L, name);
}

inline bool luacob_get_global_function(lua_State *L, const char function[]) {
    lua_getglobal(L, function);
    return lua_isfunction(L, -1);
}

bool luacob_get_table_function(lua_State *L, const char table[], const char function[]) {
    lua_getglobal(L, table);
    if (!lua_istable(L, -1))
        return false;
    lua_getfield(L, -1, function);
    lua_remove(L, -2);
    return lua_isfunction(L, -1);
}

template<typename T>
void luacob_set_table_function(lua_State *L, int idx, const char name[], T func) {
    idx = LuacobAbsIndex(L, idx);
    luacob_pushfunc(L, func);
    lua_setfield(L, idx, name);
}

template<typename T>
bool luacob_get_object_function(lua_State *L, T *object, const char function[]) {
    luacob_pushobj(L, object);
    if (!lua_istable(L, -1))
        return false;
    lua_getfield(L, -1, function);
    lua_remove(L, -2);
    return lua_isfunction(L, -1);
}

template<size_t... Integers, typename... var_types>
void luacob_l2n_mutil(lua_State *L, std::tuple<var_types&...> &vars, std::index_sequence<Integers...>&&) {
    int _[] = { 0, (std::get<Integers>(vars) = luacob_l2n<var_types>(L, (int)Integers - (int)sizeof...(Integers)), 0)... };
}

bool luacob_callfunc(lua_State *L, std::string *err, int arg_count, int ret_count) {
    int func_idx = lua_gettop(L) - arg_count;
    if (func_idx <= 0 || !lua_isfunction(L, func_idx))
        return false;

    lua_getglobal(L, "debug");
    lua_getfield(L, -1, "traceback");
    lua_remove(L, -2); // remove 'debug'

    lua_insert(L, func_idx);
    if (lua_pcall(L, arg_count, ret_count, func_idx))
    {
        if (err != nullptr)
        {
            *err = lua_tostring(L, -1);
        }
        return false;
    }
    lua_remove(L, -ret_count - 1); // remove 'traceback'
    return true;
}

template<typename... ret_types, typename... arg_types>
bool luacob_callfunc(
    lua_State *L, std::string *err, std::tuple<ret_types&...>&& rets, arg_types... args) {
    int _[] = { 0, (luacob_n2l(L, args), 0)... };
    if (!luacob_callfunc(L, err, sizeof...(arg_types), sizeof...(ret_types)))
        return false;
    luacob_l2n_mutil(L, rets, std::make_index_sequence<sizeof...(ret_types)>());
    return true;
}

template<typename... ret_types, typename... arg_types>
bool luacob_call_table_function(
    lua_State *L, std::string *err, const char table[], const char function[],
    std::tuple<ret_types&...>&& rets, arg_types... args) {
    luacob_get_table_function(L, table, function);
    int _[] = { 0, (luacob_n2l(L, args), 0)... };
    if (!luacob_callfunc(L, err, sizeof...(arg_types), sizeof...(ret_types)))
        return false;
    luacob_l2n_mutil(L, rets, std::make_index_sequence<sizeof...(ret_types)>());
    return true;
}

template<typename T, typename... ret_types, typename... arg_types>
bool luacob_call_object_function(
    lua_State *L, std::string *err, T *o, const char function[],
    std::tuple<ret_types&...>&& rets, arg_types... args) {
    luacob_get_object_function(L, o, function);
    int _[] = { 0, (luacob_n2l(L, args), 0)... };
    if (!luacob_callfunc(L, err, sizeof...(arg_types), sizeof...(ret_types)))
        return false;
    luacob_l2n_mutil(L, rets, std::make_index_sequence<sizeof...(ret_types)>());
    return true;
}

template<typename... ret_types, typename... arg_types>
bool luacob_call_global_function(
    lua_State *L, std::string *err, const char function[],
    std::tuple<ret_types&...>&& rets, arg_types... args) {
    lua_getglobal(L, function);
    int _[] = { 0, (luacob_n2l(L, args), 0)... };
    if (!luacob_callfunc(L, err, sizeof...(arg_types), sizeof...(ret_types)))
        return false;
    luacob_l2n_mutil(L, rets, std::make_index_sequence<sizeof...(ret_types)>());
    return true;
}

bool luacob_call_table_function(
    lua_State *L, std::string *err, const char table[], const char function[]) {
    return luacob_call_table_function(L, err, table, function, std::tie()); }

template<typename T>
bool luacob_call_object_function(
    lua_State *L, std::string *err, T *o, const char function[]) {
    return luacob_call_object_function(L, err, o, function, std::tie()); }

bool luacob_call_global_function(
    lua_State *L, std::string *err, const char function[]) {
    return luacob_call_global_function(L, err, function, std::tie()); }

void InitLuacob() {
}

inline void InitMetatable(lua_State* L, int metatable_idx, bool inPlace = false) {
	metatable_idx = LuacobAbsIndex(L, metatable_idx);
	lua_pushstring(L, "__index");
	lua_newtable(L);
	lua_pushboolean(L, inPlace ? 1 : 0);
	lua_pushcclosure(L, MetatableIndex, 2);
	lua_rawset(L, metatable_idx);

	lua_pushstring(L, "__newindex");
	lua_newtable(L);
	lua_pushboolean(L, inPlace ? 1 : 0);
	lua_pushcclosure(L, MetatableNewindex, 2);
	lua_rawset(L, metatable_idx);
}

inline void PushObjectFuncTbl(LuaState *state, LuaObject &mtbl) {
    if (nullptr == state) return;
    mtbl.Push(state);
    lua_State *L = LuacobTo_lua_State(state);
    lua_getfield(L, -1, "__index");
    lua_getupvalue(L, -1, 1);
    lua_remove(L, -2);
}

}  // namespace luacob

#define LUACOB_CLASS_METATABLE_NAME(classname) "__##classname##_mtbl"
#define LUACOB_CLASS_SMETATABLE_NAME(classname) "__##classname##_smtbl"

#define LUACOB_DECLARE_CLASS(classname)                         \
    static classname *LuacobCreateObj();                        \
    static void LuacobDestroyObj(classname *obj);               \
    static int luacob_create_from_script(lua_State *L);         \
    static void luacob_register_class(luacob::LuaState *state); \

#define LUACOB_BIND_CLASS_BEGIN(bindname, classname)                    \
    int classname::luacob_create_from_script(lua_State *L) {            \
        luacob::LuaState *state = LuacobTo_LuaState(L);                 \
        luacob::LuaObject ins;                                          \
        ins.AssignNewTable(state);                                      \
                                                                        \
        classname *obj = LuacobCreateObj();                             \
        ins.Set("__object", reinterpret_cast<void*>(obj));              \
        luacob::LuaObject globals = state->GetGlobals();                \
        luacob::LuaObject mtbl = globals.Get(                           \
            LUACOB_CLASS_METATABLE_NAME(classname));                    \
        ins.SetMetatable(mtbl);                                         \
                                                                        \
        state->Push(ins);                                               \
        return 1;                                                       \
    }                                                                   \
                                                                        \
    void classname::luacob_register_class(luacob::LuaState *state) {    \
    typedef classname class_type;                                       \
                                                                        \
    lua_State *L = LuacobTo_lua_State(state);                           \
    luacob::LuaObject globals = state->GetGlobals();                    \
    luacob::LuaObject smtbl = globals.CreateTable(                      \
        LUACOB_CLASS_SMETATABLE_NAME(classname));                       \
    smtbl.Set("__call", classname::luacob_create_from_script);          \
    state->Push(smtbl);                                                 \
    luacob::InitMetatable(L, lua_gettop(L), false);                     \
    luacob::LuaObject class_obj;                                        \
    class_obj.AssignNewTable(state);                                    \
                                                                        \
    class_obj.SetMetatable(smtbl);                                      \
    globals.Set(bindname, class_obj);                                   \
                                                                        \
    luacob::LuaObject mtbl = globals.CreateTable(                       \
        LUACOB_CLASS_METATABLE_NAME(classname));                        \
    state->Push(mtbl);                                                  \
    luacob::InitMetatable(L, lua_gettop(L), false);                     \

#define LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION_AS(name, func) \
    PushObjectFuncTbl(state, smtbl);  \
    smtbl.RegisterObjectSFunction(name, func);  \
    lua_pop(L, 2);  \

#define LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(name, func)    \
    PushObjectFuncTbl(state, mtbl);            \
    mtbl.RegisterObjectFunction(name, func);    \
    lua_pop(L, 2);                              \

#define LUACOB_BIND_CLASS_STATIC_MEMBER_AS(name, member)    \
    smtbl.RegisterObjectSProperty(name, member, false); \

#define LUACOB_BIND_CLASS_MEMBER_AS(name, member)       \
    mtbl.RegisterObjectProperty(name, member, false);   \

#define LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION(func)              \
    LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION_AS(#func, &class_type::func) \

#define LUACOB_BIND_CLASS_MEMBER_FUNCTION(func)               \
    LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(#func, &class_type::func)  \

#define LUACOB_BIND_CLASS_STATIC_MEMBER(member)                 \
    LUACOB_BIND_CLASS_STATIC_MEMBER_AS(#member, &class_type::member)  \

#define LUACOB_BIND_CLASS_MEMBER(member)                 \
    LUACOB_BIND_CLASS_MEMBER_AS(#member, &class_type::member)  \

#define LUACOB_BIND_CLASS_PROPERTY(name, accessor, mutator)

#define LUACOB_BIND_CLASS_END()                 \
    }                                           \

#define LUACOB_REGISTER_CLASS(state, classname) \
    classname::luacob_register_class(state);
