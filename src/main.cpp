#include <cstdio>

#include "Window.h"
#include "Mesh.h"
#include "ShaderProgram.h"

#include <glm/gtx/transform.hpp>

std::vector<std::shared_ptr<Graphics::Mesh>> s_scene;

int main()
{
  unsigned width = 800, height = 600;
  Graphics::Window::create(width, height, "OpenGL Pool");

  s_scene.push_back(std::make_shared<Graphics::Mesh>("data/table.obj"));
  s_scene.push_back(std::make_shared<Graphics::Mesh>("data/poolball.obj"));

  Graphics::ShaderProgram shaderProg;
  {
    Graphics::Shader vertexShader(
          "data/shader/vertex1.glsl", Graphics::Shader::VertexShader);
    shaderProg.addShader(vertexShader);
    shaderProg.link();
  }
  auto mvpId = shaderProg.getUniform("u_MVP");
  shaderProg.use();

  auto view = glm::lookAt(
    glm::vec3(0.1f, 2.0f, -5.0f), // camera
    glm::vec3(0.0f, 0.0f, 0.0f),  // lookat point
    glm::vec3(0.0f, 1.0f, 0.0f)   // up-Vector
  );
  auto projection = glm::perspective(glm::radians(45.0f), (float)width/(float)height,
                                     1.0f, 100.0f);
  auto mvp = projection * view;
  shaderProg.uniformMat4(mvpId, mvp);

  Graphics::Window::setDrawCallback([]() {
    for (auto& obj : s_scene)
    {
      obj->render();
    }
  });
  Graphics::Window::exec();
}
