project(reader)
include_directories(include)
add_executable(${PROJECT_NAME} main.cpp)
set(Boost_ROOT "/opt/homebrew/Cellar/boost/1.86.0_2")
set(Boost_INCLUDE_DIR "/opt/homebrew/Cellar/boost/1.86.0_2/include")
set(Boost_LIBRARY_DIR "/opt/homebrew/Cellar/boost/1.86.0_2/lib")
find_package(
    Boost ${BOOST_MIN_VERSION} REQUIRED
    COMPONENTS ${BOOST_REQUIRED_COMPONENTS}
)
target_link_libraries(${PROJECT_NAME} PUBLIC  
    Boost::filesystem
    Boost::optional
)
target_include_directories(${PROJECT_NAME} PRIVATE include)