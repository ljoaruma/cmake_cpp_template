cmake_minimum_required(VERSION 3.12)

## gtestのダウンロードとビルド

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

if (WIN32)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()


# main

add_executable(main-gtest)

## コンパイルオプション

target_compile_features(main-gtest PUBLIC cxx_std_20)
set_target_properties(main-gtest PROPERTIES CXX_STANDARD 20)
set_target_properties(main-gtest PROPERTIES CXX_EXTENSIONS YES)
set_target_properties(main-gtest PROPERTIES CXX_STANDARD_REQUIRED YES)

target_compile_options(main-gtest PRIVATE -Wall -Wextra -Wpedantic)

target_include_directories(main-gtest PRIVATE ${CMAKE_SOURCE_DIR}/src)

## リンクオプション

## gtestオプション

target_compile_options(main-gtest PRIVATE -coverage -O0 -g)
target_link_options(main-gtest PRIVATE -coverage)

target_link_libraries(main-gtest GTest::gtest)
target_link_libraries(main-gtest GTest::gmock)
target_link_libraries(main-gtest GTest::gtest_main)

gtest_discover_tests(main-gtest)

# main ソース

target_sources(main-gtest PRIVATE src/main_test.cpp)

# カバレッジ集計用のカスタムターゲット定義
find_program(LCOV_PATH lcov)
if(LCOV_PATH)
    add_custom_target(generate_coverage_info
        COMMAND ${LCOV_PATH} --ignore-errors mismatch --rc branch_coverage=1 --directory ${CMAKE_BINARY_DIR} --capture --output-file ${CMAKE_BINARY_DIR}/coverage_all.info
        COMMAND ${LCOV_PATH} --extract ${CMAKE_BINARY_DIR}/coverage_all.info "${CMAKE_SOURCE_DIR}/tests/*" --extract ${CMAKE_BINARY_DIR}/coverage_all.info "${CMAKE_SOURCE_DIR}/src/*" --ignore-errors unused --rc branch_coverage=1 --output-file ${CMAKE_BINARY_DIR}/coverage.info
        COMMENT "Generating LCOV coverage info file..."
    )
endif()
