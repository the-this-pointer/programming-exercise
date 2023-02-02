cmake_minimum_required(VERSION 3.23)
project(LeetCode)
set(CMAKE_CXX_STANDARD 23)

#
# Locate test sources
#
FILE (GLOB_RECURSE srcs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

FOREACH (T_FILE ${srcs})
    get_filename_component (T_NAME ${T_FILE} NAME_WE)
    add_executable (${T_NAME} ${T_FILE})
ENDFOREACH (T_FILE ${srcs})
