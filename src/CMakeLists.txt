include_directories (${PROJECT_SRC_DIR}/include)

add_executable (App main.cpp)
set_target_properties (App PROPERTIES RUNTIME_OUTPUT_DIRECTORY ..)
