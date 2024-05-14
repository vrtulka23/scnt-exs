cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0074 NEW)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-deprecated")

project(ExprSolver VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(ENV{PATH} "settings.env")

# compile source files
#######################

file(GLOB source_files "src/*.h" "src/*.cpp")
add_executable(ExprSolver ${source_files})

# add Google tests
###################

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

# compile tests
################

file(GLOB test_files "tests/*.h" "tests/*.cpp")
list(REMOVE_ITEM source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

enable_testing()
add_executable(
   TestSolver
   ${test_files}
   ${source_files}
)
target_link_libraries(TestSolver GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(TestSolver)
