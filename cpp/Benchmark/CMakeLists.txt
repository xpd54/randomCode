cmake_minimum_required(VERSION 3.26)
project(G_benchmark)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)

add_executable(${PROJECT_NAME} "src/main.cpp")
include_directories(lib/**/)
add_subdirectory(lib/benchmark)
target_link_libraries(${PROJECT_NAME} PRIVATE 
  benchmark
)