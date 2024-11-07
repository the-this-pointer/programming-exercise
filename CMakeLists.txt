cmake_minimum_required(VERSION 3.23)
project(programming-exercises)
set(CMAKE_CXX_STANDARD 23)

include_directories(util)

add_subdirectory(daily)
add_subdirectory(interview_easy)
add_subdirectory(ds)
add_subdirectory(sorting)