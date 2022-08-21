cmake_minimum_required(VERSION 3.5)

project(linprog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    linprog.cpp
    main.cpp
)

add_executable(linprog ${SOURCES})

# 指定头文件搜索路径
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/lib")
