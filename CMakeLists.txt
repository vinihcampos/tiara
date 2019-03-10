cmake_minimum_required(VERSION 3.13)

project(TIARA)

# use C++17
# --------------------------------------- #
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# libraries
# --------------------------------------- #
include_directories(include)

# source
# --------------------------------------- #
file(GLOB SRC_MAIN "src/*.cpp")

# executables
# --------------------------------------- #
add_executable(tiara ${SRC_MAIN})