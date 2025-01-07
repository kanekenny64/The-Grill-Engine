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
	src/renderer/Renderer.h
	
)

target_link_libraries(renderer SDL2 glew32 OpenGL32)

add_library(thegrill 
	src/thegrill/Core.cpp src/thegrill/Core.h
	src/thegrill/thegrill.h
	src/thegrill/Entity.cpp src/thegrill/Entity.h 
	src/thegrill/Component.h src/thegrill/Component.cpp
	src/thegrill/Transform.h src/thegrill/Transform.cpp
	src/thegrill/TriangleRenderer.h src/thegrill/TriangleRenderer.cpp
	src/thegrill/NonCopyable.h
	src/thegrill/Window.h src/thegrill/Window.cpp
	src/thegrill/Resource.h src/thegrill/Resource.cpp
	src/thegrill/Resources.h src/thegrill/Resources.cpp
	src/thegrill/Texture.h src/thegrill/Texture.cpp
	src/thegrill/Model.h src/thegrill/Model.cpp
	src/thegrill/SoundSystem.h src/thegrill/SoundSystem.cpp
	src/thegrill/SoundSource.h src/thegrill/SoundSource.cpp
	src/thegrill/AudioListener.h src/thegrill/AudioListener.cpp
	src/thegrill/Input.h src/thegrill/Input.cpp
	src/thegrill/Keyboard.h src/thegrill/Keyboard.cpp
	src/thegrill/Mouse.h src/thegrill/Mouse.cpp
	src/thegrill/Audio.h src/thegrill/Audio.cpp
	src/thegrill/BoxCollider.h src/thegrill/BoxCollider.cpp
	src/thegrill/RigidBody.h src/thegrill/RigidBody.cpp
	src/thegrill/MeshCollider.h src/thegrill/MeshCollider.cpp
	src/thegrill/Camera.h src/thegrill/Camera.cpp
	src/thegrill/GUI.h src/thegrill/GUI.cpp
	src/thegrill/Mouse.h src/thegrill/Mouse.cpp
	
	 
)

target_link_libraries(thegrill renderer OpenAL32)

add_executable(demo
	src/demo/main.cpp
)
target_link_libraries(demo thegrill)