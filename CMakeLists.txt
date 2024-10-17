cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(THEGRILL)

include_directories(
	src
	contrib/include
)

add_library(thegrill 
	src/thegrill/Core.cpp src/thegrill/Core.h
	src/thegrill/thegrill.h
	src/thegrill/Entity.cpp src/thegrill/Entity.h 
	src/thegrill/Component.h src/thegrill/Component.cpp
	src/thegrill/Transform.h
)


add_executable(demo
	src/demo/main.cpp
)
target_link_libraries(demo thegrill)