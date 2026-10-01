cmake_minimum_required(VERSION 3.12)

#project(main CXX)
set(EXECUTE_NAME main.exe)

add_executable(${EXECUTE_NAME})
target_compile_features(${EXECUTE_NAME} PUBLIC cxx_std_20)
set_target_properties(${EXECUTE_NAME} PROPERTIES CXX_STANDARD 20)
set_target_properties(${EXECUTE_NAME} PROPERTIES CXX_EXTENSIONS YES)
set_target_properties(${EXECUTE_NAME} PROPERTIES CXX_STANDARD_REQUIRED YES)

target_compile_options(${EXECUTE_NAME} PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(${EXECUTE_NAME} PRIVATE A)

target_sources(${EXECUTE_NAME} PRIVATE main.cpp)

