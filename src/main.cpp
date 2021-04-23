#include <cstdio>

#include "Window.h"
#include "Mesh.h"
#include "ShaderProgram.h"
#include "Camera.h"
#include "Scene.h"

#include <glm/gtx/transform.hpp>

std::vector<std::shared_ptr<Ulm3D::Mesh>> s_scene;

int main()
{
  unsigned width = 800, height = 600;
  Ulm3D::Window::create(width, height, "OpenGL Pool");

  // create a camera looking towards the origin
  Ulm3D::Camera camera(glm::vec3(3.0f, 2.0f, -2.0f));

  // Setup a vertex shader
  Ulm3D::ShaderProgram shaders;
  {
    Ulm3D::Shader vertexShader("data/shader/vertex1.glsl", Ulm3D::Shader::VertexShader);
    shaders.addShader(vertexShader);

    Ulm3D::Shader fragShader("data/shader/fragment1.glsl", Ulm3D::Shader::FragmentShader);
    shaders.addShader(fragShader);

    shaders.link();
  }

  // create a scene consisting of two objects
  Ulm3D::Scene scene(width, height, camera);
  scene.addObject(std::make_shared<Ulm3D::MeshObject>("data/table.obj", &shaders));
  scene.addObject(std::make_shared<Ulm3D::MeshObject>("data/poolball.obj", &shaders));

  Ulm3D::Window::setScene(&scene);
  Ulm3D::Window::exec();
}
