cmake_minimum_required (VERSION 2.8.11)

set (CMAKE_CXX_STANDARD 14)



#add_executable (App main.cpp)
#add_executable (Test test_main.cpp)

add_subdirectory(src)
add_subdirectory(tests)

#For seeing headers in IDE
FILE(GLOB_RECURSE LibFiles "include/*.h")
add_custom_target(headers SOURCES ${LibFiles})
