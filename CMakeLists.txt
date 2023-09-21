cmake_minimum_required(VERSION 3.10)

# set the project name
project(StringConversion)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_definitions("_UNICODE" "UNICODE")

add_definitions(-D_AFXDLL)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest)

add_subdirectory(StringUtil)
add_subdirectory(StringUtilTests)