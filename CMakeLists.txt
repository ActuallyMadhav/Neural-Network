cmake_minimum_required(VERSION 3.10)
project(neural_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# local headers
include_directories(include)

# Hint for Homebrew on Apple Silicon
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")

# add google test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

# enable testing
enable_testing()

# Main application sources (excluding main.cpp)
file(GLOB_RECURSE SOURCES "src/**/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Create a library with core functionality
add_library(neural_core ${SOURCES})

# include eigen library
find_package(Eigen3 REQUIRED NO_MODULE)

add_executable(app
    src/main.cpp
)

# Link the target
target_link_libraries(app 
    PRIVATE Eigen3::Eigen
    PRIVATE neural_core
)

# Tests
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(run_tests ${TEST_SOURCES})
target_link_libraries(run_tests PRIVATE neural_core gtest gtest_main)

# Register tests
include(GoogleTest)
gtest_discover_tests(run_tests)

# Performance for MNIST
if(APPLE)
    target_compile_options(app PRIVATE -O3 -march=native -ffast-math)
endif()