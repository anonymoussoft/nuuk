/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: image_button.cpp
 * Time-stamp: <2019-03-14 09:50:36>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./image_button.h"

LUACOB_BIND_CLASS_BEGIN("ImageButton", LImageButton)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setImages)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getNormalImage)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getOverImage)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getDownImage)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END()
LUACOB_BIND_CLASS_END()
