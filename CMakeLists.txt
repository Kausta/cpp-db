# influenced by https://github.com/lefticus/cpp_starter_project
cmake_minimum_required(VERSION 3.7)

set(MY_PROJECT_NAME cpp-db)
set(MY_PROJECT_VERSION 0.1)

project(${MY_PROJECT_NAME} VERSION ${MY_PROJECT_VERSION} LANGUAGES CXX)

set(SOURCE_FILES src/main.cpp include/MetaCommand.h include/Statement.h include/Util.h include/Error.h include/InsertStatement.h include/SelectStatement.h src/Util.cpp src/MetaCommand.cpp src/Statement.cpp include/StatementBase.h src/InsertStatement.cpp src/SelectStatement.cpp include/Table.h src/Table.cpp include/Row.h src/Row.cpp src/Error.cpp)
add_executable(${MY_PROJECT_NAME} ${SOURCE_FILES})

if (NOT (${CMAKE_VERSION} VERSION_LESS 3.8))
    set_target_properties(${MY_PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
    message("cmake >= 3.8")
endif ()

set_target_properties(${MY_PROJECT_NAME} PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

if (MSVC)
    target_compile_options(${MY_PROJECT_NAME} PRIVATE /W4 /std:c++latest)
else ()
    target_compile_options(${MY_PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    if (${CMAKE_VERSION} VERSION_LESS 3.8)
        target_compile_options(${MY_PROJECT_NAME} PRIVATE --std=c++1z)
    endif ()
endif ()

target_include_directories(${MY_PROJECT_NAME} PRIVATE include)
