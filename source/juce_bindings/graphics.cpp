/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: graphics.cpp
 * Time-stamp: <2019-03-30 03:35:26>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

LUACOB_BIND_WRAPPER_CLASS_BEGIN("Graphics", LGraphics, juce::Graphics)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_BEGIN()
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setColour)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setOpacity)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "setGradientFill",
    static_cast<void(juce::Graphics::*)(
        const ColourGradient&)>(&juce::Graphics::setGradientFill))
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setTiledImageFill)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(setFillType)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "setFont_Ft",
    static_cast<void(juce::Graphics::*)(
        const Font&)>(&juce::Graphics::setFont))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "setFont_f",
    static_cast<void(juce::Graphics::*)(
        float)>(&juce::Graphics::setFont))
LUACOB_BIND_CLASS_MEMBER_FUNCTION(getCurrentFont)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(drawSingleLineText)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(drawMultiLineText)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawText",
    static_cast<void(juce::Graphics::*)(
        const String&, int, int, int, int, Justification, bool)>(
            &juce::Graphics::drawText))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawFittedText",
    static_cast<void(juce::Graphics::*)(
        const String&, int, int, int, int, Justification, int, float)>(
            &juce::Graphics::drawFittedText))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillAll",
    static_cast<void(juce::Graphics::*)()>(&juce::Graphics::fillAll))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillAll_Colour",
    static_cast<void(juce::Graphics::*)(Colour)>(&juce::Graphics::fillAll))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillRect_Rec",
    static_cast<void(juce::Graphics::*)(
        Rectangle<int>)>(&juce::Graphics::fillRect))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillRect_iiii",
    static_cast<void(juce::Graphics::*)(
        int, int, int, int)>(&juce::Graphics::fillRect))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillRectList",
    static_cast<void(juce::Graphics::*)(
        const RectangleList<int>&)>(&juce::Graphics::fillRectList))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillRoundedRectangle",
    static_cast<void(juce::Graphics::*)(
        float, float, float, float, float)>(&juce::Graphics::fillRoundedRectangle))
LUACOB_BIND_CLASS_MEMBER_FUNCTION(fillCheckerBoard)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawRect",
    static_cast<void(juce::Graphics::*)(
        int, int, int, int, int)>(&juce::Graphics::drawRect))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawRoundedRectangle",
    static_cast<void(juce::Graphics::*)(
        float, float, float, float, float, float)>(&juce::Graphics::drawRoundedRectangle))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillEllipse",
    static_cast<void(juce::Graphics::*)(
        float, float, float, float)>(&juce::Graphics::fillEllipse))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawEllipse",
    static_cast<void(juce::Graphics::*)(
        float, float, float, float, float)>(&juce::Graphics::drawEllipse))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawLine_4f",
    static_cast<void(juce::Graphics::*)(
        float, float, float, float)>(&juce::Graphics::drawLine))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawLine_5f",
    static_cast<void(juce::Graphics::*)(
        float, float, float, float, float)>(&juce::Graphics::drawLine))
LUACOB_BIND_CLASS_MEMBER_FUNCTION(drawDashedLine)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(drawVerticalLine)
LUACOB_BIND_CLASS_MEMBER_FUNCTION(drawHorizontalLine)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillPath",
    static_cast<void(juce::Graphics::*)(
        const Path&)>(&juce::Graphics::fillPath))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "fillPath_with_transform",
    static_cast<void(juce::Graphics::*)(
        const Path&, const AffineTransform&)>(&juce::Graphics::fillPath))
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(strokePath)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(drawArrow)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(setImageResamplingQuality)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(drawImageAt)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "drawImage",
    static_cast<void(juce::Graphics::*)(
        const Image&, int, int, int, int, int, int, int, int, bool)>(
            &juce::Graphics::drawImage))
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(drawImageTransformed)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(drawImageWithin)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(getClipBounds)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(clipRegionIntersects)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "reduceClipRegion",
    static_cast<void(juce::Graphics::*)(
        int, int, int, int)>(&juce::Graphics::reduceClipRegion))
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(reduceClipRegion)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(excludeClipRegion)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(isClipEmpty)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(saveState)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(restoreState)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(beginTransparencyLayer)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(endTransparencyLayer)
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "setOrigin_pt",
    static_cast<void(juce::Graphics::*)(
        Point<int>)>(&juce::Graphics::setOrigin))
LUACOB_BIND_CLASS_MEMBER_FUNCTION_AS(
    "setOrigin_2i",
    static_cast<void(juce::Graphics::*)(
        int, int)>(&juce::Graphics::setOrigin))
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(addTransform)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(resetToDefaultState)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(isVectorDevice)
LUACOB_BIND_CLASS_MEMBER_AND_FUNCTION_END(getInternalContext)
LUACOB_BIND_WRAPPER_CLASS_END()
