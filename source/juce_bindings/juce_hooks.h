/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: juce_hooks.h
 * Time-stamp: <2019-03-07 01:03:51>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#ifndef NUUK_SOURCE_JUCE_BINDINGS_JUCE_HOOKS_H_
#define NUUK_SOURCE_JUCE_BINDINGS_JUCE_HOOKS_H_

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

template<> inline const juce::String &luacob_l2n<const juce::String&>(lua_State *L, int i) {
    size_t len;
    const char *s = luaL_checklstring(L, i, &len);
    juce::CharPointer_UTF8 cp(s);
    juce::String str(cp, len);
    lua_remove(L,i);
    return str;
}

inline void luacob_n2l(lua_State *L, juce::String &v) {
    std::string str = v.toStdString();
    lua_pushlstring(L, str.c_str(), str.length());
}

// template<class T>
// int luacob_n2l(const juce::Range<T>&);
template<class T>
int luacob_n2l(const juce::Point<T>&) {
    luceI_pushlightclass<T>({p.getX(), p.getY()}, "lightLPoint");
}
// template<class T>
// int luacob_n2l(const juce::Rectangle<T>&);
// template<class T>
// int luacob_n2l(const juce::Line<T>&);
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
