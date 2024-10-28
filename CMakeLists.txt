cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(THEGRILL)

include_directories(
	src
	contrib/include
)

link_directories(
	contrib/lib
)

add_library(thegrill 
	src/thegrill/Core.cpp src/thegrill/Core.h
	src/thegrill/thegrill.h
	src/thegrill/Entity.cpp src/thegrill/Entity.h 
	src/thegrill/Component.h src/thegrill/Component.cpp
	src/thegrill/Transform.h
	src/thegrill/TriangleRenderer.h src/thegrill/TriangleRenderer.cpp
	src/thegrill/Model.h
	src/thegrill/Mesh.h src/thegrill/Mesh.cpp
	src/thegrill/Texture.h src/thegrill/Texture.cpp
	src/thegrill/Shader.h src/thegrill/Shader.cpp
	src/thegrill/NonCopyable.h
)

target_link_libraries(thegrill SDL2 glew32 OpenGL32)

add_executable(demo
	src/demo/main.cpp
)
target_link_libraries(demo thegrill)