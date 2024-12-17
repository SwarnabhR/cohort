cmake_minimum_required(VERSION 3.10)
project(http-server-cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(http-server-cpp
    src/main.cpp
    src/server.cpp
    src/utils.cpp
)
