cmake_minimum_required(VERSION 3.12)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

if (WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

add_executable(test)
target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_sources(test PRIVATE src/main_test.cpp)
target_sources(test PRIVATE ${CMAKE_SOURCE_DIR}/src/main.cpp)

include(GoogleTest)

gtest_discover_tests(test)

