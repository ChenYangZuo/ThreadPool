cmake_minimum_required(VERSION 3.27)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/thirdparty/inc
)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)

add_executable(ThreadPool main.cpp ${SRC_LIST})

add_subdirectory(${PROJECT_SOURCE_DIR}/test/unittest)