cmake_minimum_required(VERSION 3.16)

project(sel-homework_9)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#   set(CODE_COVERAGE ON)
#   include(CodeCoverage)
#   add_code_coverage_all_targets(EXCLUDE /usr/* /Library/*
#                                 ${PROJECT_BINARY_DIR}/_deps/*)
#   add_custom_target(coverage DEPENDS ccov-all)
# endif()

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG origin/main)

FetchContent_MakeAvailable(googletest)
# Now these targets are available:
# gtest
# gtest_main

include(GoogleTest)
include(ClangTidy)
add_subdirectory(util)
add_subdirectory(geometry2d)


add_executable(geometry2d_google_tests_exe test/point_test.cpp
                                           test/line_test.cpp
                                           test/compare_test.cpp
                                           test/geo_compare_test.cpp
                                           test/angle_test.cpp
                                           test/pose_test.cpp)

target_link_libraries(geometry2d_google_tests_exe PRIVATE geometry2D 
                                                          gtest_main)
gtest_discover_tests(geometry2d_google_tests_exe)

if(CODE_COVERAGE)
  target_code_coverage(geometry2d_google_tests_exe AUTO ALL)
endif()
