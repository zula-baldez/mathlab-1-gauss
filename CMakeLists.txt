cmake_minimum_required(VERSION 3.22)
project(untitled8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++20  -g -O0")
set(CMAKE_CXX_FLAGS_SANITIZED "-fsanitize=address,undefined,leak")
set(CMAKE_CXX_FLAGS_RELEASE " -O3")

if (CMAKE_BUILD_TYPE STREQUAL "Sanitized")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_SANITIZED}")
    message("SANITIZED build")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")
    message("RELEASE build")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")
    message("DEBUG build")
endif ()
add_executable(untitled8 main.cpp Matrix.cpp Matrix.h Row.h Row.cpp MatrixWithGauss.cpp MatrixWithGauss.h)

