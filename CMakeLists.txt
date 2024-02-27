# Template CmakeLists.txt for a C library
#Setting PROJECT_NAME
project(logc)
cmake_minimum_required( VERSION 3.3 )
add_library( ${PROJECT_NAME} STATIC "src/log.c" )
target_include_directories( ${PROJECT_NAME} PUBLIC "src" )
# -DLOG_USE_COLOR
target_compile_definitions( ${PROJECT_NAME} PRIVATE LOG_USE_COLOR )
