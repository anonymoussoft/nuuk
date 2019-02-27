/* =================================================================
 *
 * Copyright (C) 2019 anonymoussoft.com.  All rights reserved.
 * File: component.cpp
 * Time-stamp: <2019-02-26 11:01:30>
 * Description:
 * Author: bin.gao
 *
 * =================================================================
 */

#include "./component.h"

LUACOB_BIND_CLASS_BEGIN("Component", LComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getName)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setName)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getComponentID)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setComponentID)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isVisible)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setVisible)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(visibilityChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isShowing)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(addToDesktop)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(removeFromDesktop)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isOnDesktop)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getPeer)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(userTriedToCloseWindow)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(minimisationStateChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getDesktopScaleFactor)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(toFront)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(toBack)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(toBehind)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setAlwaysOnTop)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isAlwaysOnTop)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getX)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getY)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getWidth)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getHeight)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getRight)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getPosition)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getBottom)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getBounds)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getLocalBounds)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getBoundsInParent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getScreenX)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getScreenY)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getScreenPosition)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getScreenBounds)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getLocalPoint)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getLocalArea)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(localPointToGlobal)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(localAreaToGlobal)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setTopLeftPosition)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setTopRightPosition)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setSize)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBounds)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBoundsRelative)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBoundsInset)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBoundsToFit)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setCentrePosition)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setCentreRelative)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(centreWithSize)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getTransform)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setTransform)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isTransformed)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(proportionOfWidth)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(proportionOfHeight)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getParentWidth)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getParentHeight)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getParentMonitorArea)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getNumChildComponents)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getChildComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getIndexOfChildComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getChildren)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(findChildWithID)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(addChildComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(addAndMakeVisible)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(addChildAndSetID)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(removeChildComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(removeAllChildren)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(deleteAllChildren)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getParentComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(findParentComponentOfClass)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getTopLevelComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isParentOf)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(parentHierarchyChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(childrenChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(hitTest)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getInterceptsMouseClicks)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setInterceptsMouseClicks)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(contains)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(reallyContains)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getComponentAt)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(repaint)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBufferedToImage)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(createComponentSnapshot)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(paintEntireComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isPaintingUnclipped)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setPaintingIsUnclipped)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getComponentEffect)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setComponentEffect)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getLookAndFeel)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setLookAndFeel)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(lookAndFeelChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(sendLookAndFeelChange)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isOpaque)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setOpaque)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isBroughtToFrontOnMouseClick)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setBroughtToFrontOnMouseClick)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getWantsKeyboardFocus)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setWantsKeyboardFocus)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getMouseClickGrabsKeyboardFocus)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setMouseClickGrabsKeyboardFocus)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(grabKeyboardFocus)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(hasKeyboardFocus)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getCurrentlyFocusedComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(unfocusAllComponents)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(moveKeyboardFocusToSibling)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(createFocusTraverser)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getExplicitFocusOrder)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setExplicitFocusOrder)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isFocusContainer)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setFocusContainer)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isEnabled)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setEnabled)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(enablementChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getAlpha)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setAlpha)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(alphaChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getMouseCursor)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setMouseCursor)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(updateMouseCursor)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(paint)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(paintOverChildren)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseMove)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseEnter)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseExit)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseDown)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseDrag)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseUp)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseDoubleClick)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseWheelMove)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(mouseMagnify)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(beginDragAutoRepeat)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setRepaintsOnMouseActivity)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(addMouseListener)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(removeMouseListener)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(addKeyListener)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(removeKeyListener)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(keyPressed)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(keyStateChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(modifierKeysChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(focusGained)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(focusLost)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(focusOfChildComponentChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isMouseOver)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isMouseButtonDown)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isMouseOverOrDragging)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isMouseButtonDownAnywhere)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getMouseXYRelative)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(resized)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(moved)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(childBoundsChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(parentSizeChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(broughtToFront)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(addComponentListener)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(removeComponentListener)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(postCommandMessage)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(handleCommandMessage)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(runModalLoop)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(enterModalState)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(exitModalState)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isCurrentlyModal)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getNumCurrentlyModalComponents)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getCurrentlyModalComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isCurrentlyBlockedByAnotherModalComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(canModalEventBeSentToComponent)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(inputAttemptWhenModal)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getProperties)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(findColour)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setColour)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(removeColour)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(isColourSpecified)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(copyAllExplicitColoursTo)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(colourChanged)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getWindowHandle)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getPositioner)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setPositioner)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getCachedComponentImage)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setCachedComponentImage)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(getViewportIgnoreDragFlag)
    LUACOB_BIND_CLASS_MEMBER_FUNCTION(setViewportIgnoreDragFlag)
LUACOB_BIND_CLASS_END()
