cmake_minimum_required(VERSION 3.10)

list(APPEND SFML_LIBS sfml-system)
list(APPEND SFML_LIBS sfml-window)
list(APPEND SFML_LIBS sfml-network)
list(APPEND SFML_LIBS sfml-graphics)

set(EIGEN3_INCLUDE_DIR "$ENV{EIGEN3_INCLUDE_DIR}")
set(CMAKE_MODULE_PATH "$ENV{EIGEN3_DIR}")
set(INCLUDE_DIR include)

# set(HEADER_FILES ${INCLUDE_DIR}/Actor.hpp)

find_package(Eigen3 3.3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

project(2D_DSGA)

include_directories(${INCLUDE_DIR})
file(GLOB SOURCES "src/*.cpp")
add_executable(2d_dsga ${SOURCES})

# target_include_directories(2d_dsga PRIVATE ${INCLUDE_DIR})
target_link_libraries(2d_dsga PUBLIC ${SFML_LIBS} ${EIGEN_LIBS})
