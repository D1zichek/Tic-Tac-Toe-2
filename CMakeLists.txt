cmake_minimum_required(VERSION 3.10)
project(TTC)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build as shared library" OFF)

add_subdirectory(lib)

add_executable(TTC main.cpp)
target_link_libraries(TTC PRIVATE libttc)



