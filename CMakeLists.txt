# influenced by https://github.com/lefticus/cpp_starter_project
cmake_minimum_required(VERSION 3.7)

set(MY_PROJECT_NAME cpp-db)
set(MY_PROJECT_VERSION 0.1)

project(${MY_PROJECT_NAME} VERSION ${MY_PROJECT_VERSION} LANGUAGES CXX)

# Set default warnings
set(WARNINGS_PRJ ${MY_PROJECT_NAME}-warnings)
add_library(${WARNINGS_PRJ} INTERFACE)
set(ARGS_PRJ ${MY_PROJECT_NAME}-args)
add_library(${ARGS_PRJ} INTERFACE)

if (MSVC)
    target_compile_options(${WARNINGS_PRJ} INTERFACE /W4)
    target_compile_options(${ARGS_PRJ} INTERFACE /std:c++latest)
else ()
    target_compile_options(${WARNINGS_PRJ} INTERFACE -Wall -Wextra -Wpedantic -Werror)
    if (${CMAKE_VERSION} VERSION_LESS 3.8)
        target_compile_options(${ARGS_PRJ} INTERFACE --std=c++1z)
    endif ()
endif ()


# Set Catch
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests/catch/)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

set(SOURCE_FILES src/main.cpp include/MetaCommand.h include/Statement.h include/Util.h include/Error.h include/InsertStatement.h include/SelectStatement.h src/Util.cpp src/MetaCommand.cpp src/Statement.cpp include/StatementBase.h src/InsertStatement.cpp src/SelectStatement.cpp include/Table.h src/Table.cpp include/Row.h src/Row.cpp src/Error.cpp)
add_executable(${MY_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${MY_PROJECT_NAME} PRIVATE ${WARNINGS_PRJ} ${ARGS_PRJ})

if (NOT (${CMAKE_VERSION} VERSION_LESS 3.8))
    set_target_properties(${MY_PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
    message("cmake >= 3.8")
endif ()

set_target_properties(${MY_PROJECT_NAME} PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

target_include_directories(${MY_PROJECT_NAME} PRIVATE include)

enable_testing()

set(TEST_PROJECT ${MY_PROJECT_NAME}-tests)

set(TEST_SOURCE_FILES tests/test_main.cpp)
add_executable(${TEST_PROJECT} ${TEST_SOURCE_FILES})
target_link_libraries(${TEST_PROJECT} PRIVATE ${WARNINGS_PRJ} ${ARGS_PRJ})
target_link_libraries(${TEST_PROJECT} PRIVATE Catch)

if (NOT (${CMAKE_VERSION} VERSION_LESS 3.8))
    set_target_properties(${TEST_PROJECT} PROPERTIES CXX_STANDARD 17)
    message("cmake >= 3.8")
endif ()

set_target_properties(${TEST_PROJECT} PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

add_test(NAME CppDbTests COMMAND ${TEST_PROJECT})