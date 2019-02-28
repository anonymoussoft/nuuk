cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "test_base")

include_directories(../..)
include_directories(../lua-5.3.5/src)

set(
  SRC_FILES
  "./test_base.cpp"
  )

add_executable(${BINARY_NAME} ${SRC_FILES})
target_link_libraries(${BINARY_NAME} lua)
