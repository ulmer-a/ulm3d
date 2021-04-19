#include <cstdio>

#include "Window.h"
#include "Mesh.h"

int main()
{
  Graphics::Window::init(1024, 768, "OpenGL Pool");

  Graphics::Mesh poolTable("data/table.obj");
  Graphics::Mesh poolball("data/poolball.obj");

  Graphics::Window::exec();
}
