cmake_minimum_required(VERSION 3.12)

set(LIB_NAME A)

add_library(${LIB_NAME} SHARED)
target_compile_features(${LIB_NAME} PUBLIC cxx_std_20)
set_target_properties(${LIB_NAME} PROPERTIES CXX_STANDARD 20)
set_target_properties(${LIB_NAME} PROPERTIES CXX_EXTENSIONS YES)
set_target_properties(${LIB_NAME} PROPERTIES CXX_STANDARD_REQUIRED YES)

target_compile_options(${LIB_NAME} PRIVATE -Wall -Wextra -Wpedantic)

target_sources(${LIB_NAME} PRIVATE src/libA.cpp)

target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
