cmake_minimum_required(VERSION 3.14)

project(pool VERSION 1.0)

add_library(gfx STATIC
    lib/Renderer.h
    lib/Window.h
    lib/Window.cpp
    lib/Mesh.cpp
)
target_link_libraries(gfx -lsfml-window -lsfml-system -lGL -lGLEW)

add_executable(pool src/main.cpp)
target_include_directories(pool PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(pool gfx)
