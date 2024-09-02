cmake_minimum_required(VERSION 3.26)
project(EventDriven)
set(CMAKE_CXX_STANDARD 17)

file(GLOB event_src
 "main.cpp"
 "*.cpp"
 "Events/*.cpp"
)

add_executable(
  ${PROJECT_NAME}
  ${event_src}
)
