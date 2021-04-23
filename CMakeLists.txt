cmake_minimum_required(VERSION 3.14)

project(pool VERSION 1.0)

add_library(gfx STATIC
    lib/Window.h
    lib/Window.cpp
    lib/VertexBuffer.h
    lib/VertexBuffer.cpp
    lib/Mesh.h
    lib/Mesh.cpp
    lib/MeshObject.h
    lib/MeshObject.cpp
    lib/Shader.h
    lib/Shader.cpp
    lib/Scene.h
    lib/Scene.cpp
    lib/ResourceManager.h
    lib/ResourceManager.cpp
    lib/Camera.h
    lib/Camera.cpp
    lib/ShaderProgram.h
    lib/ShaderProgram.cpp
)
target_link_libraries(gfx -lglfw -lGL -lGLEW)

add_executable(pool src/main.cpp)
target_include_directories(pool PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(pool gfx)
