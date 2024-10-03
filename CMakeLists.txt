cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(THEGRILL)

include_directories(
	src
)

add_library(thegrill 
	src/thegrill/dummy.cpp src/thegrill/dummy.h
)


add_executable(demo
	src/demo/main.cpp
)
target_link_libraries(demo thegrill)