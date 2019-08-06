include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(little-utility test.cc)

set_target_properties(little-utility PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})