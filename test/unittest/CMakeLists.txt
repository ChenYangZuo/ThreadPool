cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(task_unittest task_unittest.cpp)