cmake_minimum_required(VERSION 3.18.3)

set(PROJECT_NAME TikhonovRegularizationSolver)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 3.4 REQUIRED NO_MODULE)

include_directories(include)

set(SOURCES

	src/main.cpp
	src/MatrixLoader.cpp
	src/RegularizationSolver.cpp
)

add_executable(main ${SOURCES})