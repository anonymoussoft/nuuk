cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "nuuk")

include_directories(../include)
include_directories(../third_party)
include_directories(../third_party/lua/src)
include_directories(../third_party/juce)
include_directories(../third_party/juce/JUCE/modules)

set(
  NUUK_SRCS
  "../include/nuuk.h"
  "./nuuk.cpp"
  "../include/luastate_manager.h"
  "./luastate_manager.cpp"
  "./juce_bindings/juce.h"
  "./juce_bindings/application.h"
  "./juce_bindings/application.cpp"
  "./juce_bindings/document_window.h"
  "./juce_bindings/document_window.cpp"
  )

add_library(${BINARY_NAME} STATIC ${NUUK_SRCS})
target_link_libraries(${BINARY_NAME} X11 lua luaplus juce)
