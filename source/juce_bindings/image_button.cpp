/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: image_button.cpp
 * Time-stamp: <2019-02-26 11:41:53>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./image_button.h"

LUACOB_BIND_CLASS_BEGIN("ImageButton", LImageButton)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setImages)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getNormalImage)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getOverImage)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getDownImage)
LUACOB_BIND_CLASS_END()
