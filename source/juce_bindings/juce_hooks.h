/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: juce_hooks.h
 * Time-stamp: <2019-03-07 10:02:55>
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

template<> inline juce::String luacob_l2n<juce::String>(lua_State *L, int i) {
    size_t len;
    const char *s = luaL_checklstring(L, i, &len);
    juce::CharPointer_UTF8 cp(s);
    juce::String str(cp, len);
    lua_remove(L,i);
    return str;
}

inline void luacob_basic_n2l(lua_State *L, juce::String &v) {
    std::string str = v.toStdString();
    luacob_n2l(L, str);
}

template<typename T>
juce::Range<T> luacob_l2n(type<juce::Range<T>>, lua_State *L, int i) {
    luacob::LuaObject obj(L, i);
    juce::Range<T> r(obj.Get("start"), obj.Get("end"));
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
    luacob::LuaObject obj(L, i);
    juce::Point<T> r(obj.Get("x"), obj.Get("y"));
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
    luacob::LuaObject obj(L, i);
    juce::Rectangle<T> r(obj.Get("x"), obj.Get("y"), obj.Get("w"), obj.Get("h"));
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
    luacob::LuaObject obj(L, i);
    juce::Line<T> r(obj.Get("start_x"), obj.Get("start_y"),
                         obj.Get("end_x"), obj.Get("end_y"));
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
