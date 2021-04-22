#include <cstdio>

#include "Window.h"
#include "Mesh.h"
#include "VertexBuffer.h"

static Graphics::Mesh *poolTable, *poolball;

int main()
{
  Graphics::Window::create(800, 600, "OpenGL Pool");

  poolTable = new Graphics::Mesh("data/table.obj");
  poolball = new Graphics::Mesh("data/poolball.obj");

  Graphics::Window::setDrawCallback([]() {
    poolTable->draw();
  });
  Graphics::Window::exec();
}
