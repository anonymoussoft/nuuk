/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: juce_hooks.h
 * Time-stamp: <2019-03-09 01:00:57>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_JUCE_HOOKS_H_
#define NUUK_SOURCE_JUCE_BINDINGS_JUCE_HOOKS_H_

#include <string>
#include <map>

#include "./luacob.h"
#include "./juce.h"

namespace luacob {

template<> inline juce::String luacob_basic_l2n<juce::String>(lua_State *L, int i) {
    size_t len;
    const char *s = luaL_checklstring(L, i, &len);
    juce::CharPointer_UTF8 cp(s);
    juce::String str(cp, len);
    lua_remove(L,i);
    return str;
}

inline void luacob_basic_n2l(lua_State *L, juce::String v) {
    std::string str = v.toStdString();
    luacob_n2l(L, str);
}

template<typename T>
juce::Range<T> luacob_l2n(type<juce::Range<T>>, lua_State *L, int i) {
    luacob::LuaObject obj(LuacobTo_LuaState(L), i);
    juce::Range<T> r(obj.Get("start").Value<T>(), obj.Get("end").Value<T>());
    return r;
}

template<class T>
void luacob_basic_n2l(lua_State *L, const juce::Range<T> &v) {
    std::map<char*, T> m{
        {"start", v.getStart()},
        {"end", v.getStart()}
    };
    luacob_n2l(L, m);
}

template<typename T>
juce::Point<T> luacob_l2n(type<juce::Range<T>>, lua_State *L, int i) {
    luacob::LuaObject obj(LuacobTo_LuaState(L), i);
    juce::Point<T> r(obj.Get("x").Value<T>(), obj.Get("y").Value<T>());
    return r;
}

template<class T>
void luacob_basic_n2l(lua_State *L, juce::Point<T> &v) {
    std::map<char*, T> m{
        {"x", v.getX()},
        {"y", v.getY()}
    };
    luacob_n2l(L, m);
}

template<class T>
juce::Rectangle<T> luacob_l2n(type<juce::Rectangle<T>>, lua_State *L, int i) {
    luacob::LuaObject obj(LuacobTo_LuaState(L), i);
    juce::Rectangle<T> r(obj.Get("x").Value<T>(), obj.Get("y").Value<T>(),
                         obj.Get("w").Value<T>(), obj.Get("h").Value<T>());
    return r;
}

template<class T>
void luacob_basic_n2l(lua_State *L, const juce::Rectangle<T> &v) {
    std::map<char*, T> m{
        {"x", v.getX()},
        {"y", v.getY()},
        {"w", v.getWidth()},
        {"h", v.getHeight()}
    };
    luacob_n2l(L, m);
}

template<class T>
juce::Line<T> luacob_l2n(type<juce::Line<T>>, lua_State *L, int i) {
    luacob::LuaObject obj(LuacobTo_LuaState(L), i);
    juce::Line<T> r(obj.Get("start_x").Value<T>(), obj.Get("start_y").Value<T>(),
                    obj.Get("end_x").Value<T>(), obj.Get("end_y").Value<T>());
    return r;
}

template<class T>
void luacob_basic_n2l(lua_State *L, const juce::Line<T> &v) {
    std::map<char*, T> m{
        {"start_x", v.getStartX()},
        {"start_y", v.getStartY()},
        {"end_x", v.getEndX()},
        {"end_y", v.getEndY()}
    };
    luacob_n2l(L, m);
}

// template<class T, class U>
// int luacob_n2l( const OwnedArray<U>&);
// template<class T>
// int luacob_n2l(const Array<T>&);
// template<class T>
// int luacob_n2l( const juce::SparseSet<T>& r );

// int luacob_n2l(const juce::AffineTransform&);
// int luacob_n2l(const std::list<var>);
// int luacob_n2l(const juce::RectanglePlacement&);
// int luacob_n2l(const StringArray& sa);
// int luacob_n2l(const StringPairArray& sa);
// int luacob_n2l(const Array<var>& val);

template<class T>
int luacob_n2l(const T* buffer, int size);

};

#endif  // NUUK_SOURCE_JUCE_BINDINGS_JUCE_HOOKS_H_
