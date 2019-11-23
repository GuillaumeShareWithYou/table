cmake_minimum_required(VERSION 3.15)
project(Table)

set(CMAKE_CXX_STANDARD 17)

# GOOGLE TEST FRAMEWORK ####################
add_subdirectory(googletest)
enable_testing()
#################################

#LIB FOLDER
add_subdirectory(src)

#TEST FOLDER
add_subdirectory(test)