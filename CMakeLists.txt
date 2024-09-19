cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0074 NEW)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(ExpresionSolver VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-deprecated")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# getting curret code version
#############################

execute_process(
    COMMAND bash -c "source settings.env && echo $CODE_VERSION"
    OUTPUT_VARIABLE CODE_VERSION
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# compile example solvers
##########################

file(GLOB examples LIST_DIRECTORIES true "examples/*")
foreach(dirpath ${examples})

  get_filename_component(dirname ${dirpath} NAME)
  message("Compiling example: ${dirname}")
  file(GLOB source_files "src/*.h" "src/*.cpp" "src/**/*.h" "src/**/*.cpp")
  file(GLOB example_files "examples/${dirname}/*.h" "examples/${dirname}/*.cpp"
                          "examples/${dirname}/**/*.h" "examples/${dirname}/**/*.cpp")
  add_executable(${dirname} ${source_files} ${example_files} )

endforeach()

# add Google tests
###################

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# compile tests
################

file(GLOB test_files "tests/*.h" "tests/*.cpp")
#list(REMOVE_ITEM source_files "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

enable_testing()
add_executable(
   TestSolver
   ${test_files}
   ${source_files}
)
target_link_libraries(TestSolver GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(TestSolver)

# create cmake export files
###########################

#set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")
set(CMAKE_INSTALL_LIBDIR lib)
set(CMAKE_INSTALL_INCLUDEDIR include)

install(DIRECTORY src/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/scnt-exs FILES_MATCHING PATTERN "*.h")

add_library(ExpressionSolver INTERFACE)
target_include_directories(ExpressionSolver INTERFACE
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
install(TARGETS ExpressionSolver EXPORT ExpressionSolverTargets
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/scnt-exs)
	
include(CMakePackageConfigHelpers)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/scnt-exs-config.cmake.in
  	"${CMAKE_CURRENT_BINARY_DIR}/scnt-exs-config.cmake"
  	INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/scnt-exs
	PATH_VARS CMAKE_INSTALL_INCLUDEDIR
)

write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/scnt-exs-config-version.cmake"
    	VERSION ${CODE_VERSION}
    	COMPATIBILITY AnyNewerVersion
)

install(FILES
	"${CMAKE_CURRENT_BINARY_DIR}/scnt-exs-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/scnt-exs-config-version.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/scnt-exs
)

install(EXPORT ExpressionSolverTargets
  FILE scnt-exs-targets.cmake
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/scnt-exs"
)
