# influenced by https://github.com/lefticus/cpp_starter_project
cmake_minimum_required(VERSION 3.8)

set(MY_PROJECT_NAME cpp-db)
set(MY_PROJECT_VERSION 0.1)

project(${MY_PROJECT_NAME} VERSION ${MY_PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(SOURCE_FILES src/main.cpp)
add_executable(${MY_PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${MY_PROJECT_NAME} PRIVATE include)