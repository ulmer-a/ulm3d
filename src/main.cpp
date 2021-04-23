#include <cstdio>

#include "Window.h"
#include "Mesh.h"
#include "ShaderProgram.h"

std::vector<std::shared_ptr<Graphics::Mesh>> s_scene;

int main()
{
  Graphics::Window::create(800, 600, "OpenGL Pool");

  s_scene.push_back(std::make_shared<Graphics::Mesh>("data/table.obj"));
  s_scene.push_back(std::make_shared<Graphics::Mesh>("data/poolball.obj"));

  Graphics::ShaderProgram shaderProg;
  {
    Graphics::Shader vertexShader(
          "data/shader/vertex1.glsl", Graphics::Shader::VertexShader);
    shaderProg.addShader(vertexShader);
    shaderProg.link();
  }
  shaderProg.use();

  Graphics::Window::setDrawCallback([]() {
    for (auto& obj : s_scene)
    {
      obj->render();
    }
  });
  Graphics::Window::exec();
}
