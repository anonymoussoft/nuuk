/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: keypress.cpp
 * Time-stamp: <2019-02-28 00:53:20>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./button.h"

LUACOB_BIND_CLASS_BEGIN("KeyPress", LKeyPress)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isValid)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getKeyCode)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getModifiers)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getTextCharacter)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isKeyCode)
LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION(createFromDescription)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getTextDescription)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getTextDescriptionWithIcons)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(isCurrentlyDown)
LUACOB_BIND_CLASS_STATIC_MEMBER_FUNCTION(isKeyCurrentlyDown)
LUACOB_BIND_CLASS_END()
