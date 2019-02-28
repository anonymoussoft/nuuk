cmake_minimum_required(VERSION 3.4.1)

set(BINARY_NAME "test_window")

include_directories(../../include)
include_directories(../../third_party)
include_directories(../../third_party/lua/src)

set(
  TEST_SRCS
  "./main.cpp"
  )

add_executable(${BINARY_NAME} ${TEST_SRCS})
target_link_libraries(${BINARY_NAME} nuuk dl pthread freetype X11 Xext)
