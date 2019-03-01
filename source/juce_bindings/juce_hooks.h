/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: juce_hooks.h
 * Time-stamp: <2019-02-28 09:10:23>
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

inline void luacob_n2l(lua_State *L, juce::String &v) {
    std::string str = v.toStdString();
    lua_pushlstring(L, str.c_str(), str.length());
}

};

#endif  // NUUK_SOURCE_JUCE_BINDINGS_JUCE_HOOKS_H_
