#include <cstdio>

#include "Window.h"
#include "Mesh.h"
#include "VertexBuffer.h"

static Graphics::Mesh *poolTable, *poolball;

int main()
{
  Graphics::Window::init(1024, 768, "OpenGL Pool");

  poolball = new Graphics::Mesh("data/poolball.obj");
  poolTable = new Graphics::Mesh("data/table.obj");

  Graphics::Window::setDrawCallback([]() {
    poolTable->draw();
  });
  Graphics::Window::exec();
}
