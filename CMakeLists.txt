# Template CmakeLists.txt for a C library
#Setting PROJECT_NAME
project(logc)
cmake_minimum_required( VERSION 3.3 )
add_library( ${PROJECT_NAME} STATIC "src/log.c" )
target_include_directories( ${PROJECT_NAME} PUBLIC "src" )
