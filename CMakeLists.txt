cmake_minimum_required(VERSION 3.13)

project(TIARA)

include(FetchContent)

# general configs
# --------------------------------------- #
set(YAML_CPP_BUILD_TESTS CACHE BOOL OFF)

# dependencies
# --------------------------------------- #
FetchContent_Declare(yamlcpp
    GIT_REPOSITORY  https://github.com/jbeder/yaml-cpp
    GIT_TAG         562aefc114938e388457e6a531ed7b54d9dc1b62 # 0.6.2
)
FetchContent_GetProperties(yamlcpp)
if (NOT yamlcpp_POPULATED)
    FetchContent_Populate(yamlcpp)
    add_subdirectory(${yamlcpp_SOURCE_DIR} ${yamlcpp_BINARY_DIR})
endif()

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
target_link_libraries(tiara yaml-cpp)