include_directories (${PROJECT_SRC_DIR}/include)
add_executable (Tests test_main.cpp)
set_target_properties(Tests PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
