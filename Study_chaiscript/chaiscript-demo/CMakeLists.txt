cmake_minimum_required(VERSION 3.16)
project(chaiscript_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Explicitly point to your clone
set(CHAI_INCLUDE "${CMAKE_SOURCE_DIR}/../ChaiScript/include")
include_directories(BEFORE ${CHAI_INCLUDE})

add_executable(chaiscript_demo src/main.cpp)
