cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "test_base")

include_directories(../../include)
include_directories(../../third_party/lua-5.3.5/src)

add_definitions(-Wfatal-errors)

set(
  SRC_FILES
  "./test_base.cpp"
  )

add_executable(${BINARY_NAME} ${SRC_FILES})
target_link_libraries(${BINARY_NAME} lua)
