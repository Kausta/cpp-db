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
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

set(SOURCE_FILES src/main.cpp include/MetaCommand.h include/Statement.h include/Util.h include/Error.h include/InsertStatement.h include/SelectStatement.h src/Util.cpp src/MetaCommand.cpp src/Statement.cpp include/StatementBase.h src/InsertStatement.cpp src/SelectStatement.cpp)
add_executable(${MY_PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${MY_PROJECT_NAME} PRIVATE include)
