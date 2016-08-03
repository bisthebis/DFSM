cmake_minimum_required (VERSION 2.8.11)

set (CMAKE_CXX_STANDARD 14)



#add_executable (App main.cpp)
#add_executable (Test test_main.cpp)

##add_subdirectory(src)
##add_subdirectory(tests)

include_directories(include)

#For seeing headers in IDE
FILE(GLOB_RECURSE LibFiles "include/*.h")
add_custom_target(headers SOURCES ${LibFiles})

add_executable (App 
	
	src/main.cpp
	
	
	
	)
	
add_executable (Tests
 
	tests/test_main.cpp 
	tests/NiceDFSM.cpp
	tests/transitionFunc.cpp
	
	)