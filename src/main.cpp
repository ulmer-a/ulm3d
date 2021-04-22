#include <cstdio>

#include "Window.h"
#include "Mesh.h"

std::vector<std::shared_ptr<Graphics::Mesh>> s_scene;

int main()
{
  Graphics::Window::create(800, 600, "OpenGL Pool");

  s_scene.push_back(std::make_shared<Graphics::Mesh>("data/table.obj"));
  s_scene.push_back(std::make_shared<Graphics::Mesh>("data/poolball.obj"));

  Graphics::Window::setDrawCallback([]() {
    for (auto& obj : s_scene)
    {
      obj->render();
    }
  });
  Graphics::Window::exec();
}
