add_executable(test-utility test_main.cc test.cc)

set_target_properties(test-utility PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

target_include_directories(test-utility PUBLIC ${include_dir})
target_include_directories(test-utility PUBLIC ${catch2_dir})

set_target_properties(test-utility PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})