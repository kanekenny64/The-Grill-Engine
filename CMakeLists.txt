cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(THEGRILL)

include_directories(
	src
	contrib/include
	contrib/cl-windows-x86_64/include
)


link_directories(
	contrib/cl-windows-x86_64/lib
)


add_library(renderer
	src/renderer/Model.h
	src/renderer/Mesh.h src/renderer/Mesh.cpp
	src/renderer/Texture.h src/renderer/Texture.cpp
	src/renderer/Shader.h src/renderer/Shader.cpp
	
)

target_link_libraries(renderer SDL2 glew32 OpenGL32)

add_library(thegrill 
	src/thegrill/Core.cpp src/thegrill/Core.h
	src/thegrill/thegrill.h
	src/thegrill/Entity.cpp src/thegrill/Entity.h 
	src/thegrill/Component.h src/thegrill/Component.cpp
	src/thegrill/Transform.h
	src/thegrill/TriangleRenderer.h src/thegrill/TriangleRenderer.cpp
	src/thegrill/NonCopyable.h
	src/thegrill/Window.h src/thegrill/Window.cpp
	 
)

target_link_libraries(thegrill renderer)

add_executable(demo
	src/demo/main.cpp
)
target_link_libraries(demo thegrill)