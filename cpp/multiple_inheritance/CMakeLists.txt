cmake_minimum_required(VERSION 3.26)
project(Panda)
set(CMAKE_CXX_STANDARD 17)
file(GLOB src_file
  "main.cpp"
  "ZooAnimal/*.cpp"
  "ZooAnimal/**/*.cpp"
  "Endangered/*.cpp"
)
add_executable(${PROJECT_NAME} ${src_file})