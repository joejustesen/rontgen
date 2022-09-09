cmake_minimum_required(VERSION 3.20...3.23)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(ENABLE_DEVELOPER_MODE TRUE CACHE BOOL "Enable 'developer mode'")
set(OPT_WARNINGS_AS_ERRORS_DEVELOPER_DEFAULT TRUE)

# Add project_options v0.20.0
# https://github.com/cpp-best-practices/project_options
include(FetchContent)
FetchContent_Declare(_project_options URL https://github.com/aminya/project_options/archive/refs/tags/v0.20.0.zip)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)

project(rontgen VERSION 0.0.1 DESCRIPTION "an application tracer and monitor" HOMEPAGE_URL "%%myurl%%" LANGUAGES CXX)

# This variable is set by project() in CMake 3.21+
string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${PROJECT_SOURCE_DIR}" PROJECT_IS_TOP_LEVEL)

include(FetchContent)

find_package(GTest)

if(NOT GTest_Found)
    message(STATUS "fetching gtest/gmock from github")
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)
endif()

find_package(fmt)

if(NOT fmt_Found)
    message(STATUS "fetching fmt library from github")
    FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 9.1.0
    )
    FetchContent_MakeAvailable(fmt)
endif()

# if(PROJECT_IS_TOP_LEVEL)
# # Consider the CTest module, which creates targets and options!
# # Only needed if you want to enable submissions to a CDash server.
# include(CTest)
# endif()
add_subdirectory(rontgen)

# Adding the tests:
option(ENABLE_TESTING "Enable the tests" ${PROJECT_IS_TOP_LEVEL})

# option(ENABLE_FUZZING "Enable the fuzz tests" OFF)

# if(ENABLE_FUZZING)
# message(AUTHOR_WARNING "Building Fuzz Tests, using fuzzing sanitizer https://www.llvm.org/docs/LibFuzzer.html")
# add_subdirectory(tests/fuzz_tests)
# endif()

# set(CPACK_PACKAGE_FILE_NAME
# "${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}-${GIT_SHORT_SHA}-${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_CXX_COMPILER_ID}-${CMAKE_CXX_COMPILER_VERSION}"
# )

# include(CPack)