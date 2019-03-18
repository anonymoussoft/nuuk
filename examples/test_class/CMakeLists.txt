cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "test_class")

include_directories(../..)
include_directories(../lua-5.3.5/src)

add_definitions(-Wfatal-errors)

set(
  SRC_FILES
  "./test_class.cpp"
  )

add_executable(${BINARY_NAME} ${SRC_FILES})
target_link_libraries(${BINARY_NAME} lua)
