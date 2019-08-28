cmake_minimum_required(VERSION 3.7)

project(little-utility VERSION 0.1 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(include_dir ${PROJECT_SOURCE_DIR}/include/little-utility)
set(catch2_dir ${PROJECT_SOURCE_DIR}/extern/catch2)

add_subdirectory(test)

enable_testing()
add_test(
  NAME test-utility
  COMMAND $<TARGET_FILE:test-utility> --success
)