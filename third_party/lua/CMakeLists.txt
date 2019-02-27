cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "lua")
set(GROUP_NAME "lua")

aux_source_directory(src LUA_SOURCES)
list(REMOVE_ITEM LUA_SOURCES "src/lua.c" "src/luac.c")

add_library(${BINARY_NAME} STATIC ${LUA_SOURCES})
set_property(TARGET ${BINARY_NAME} PROPERTY FOLDER ${GROUP_NAME})
