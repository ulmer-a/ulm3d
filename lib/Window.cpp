#include "Window.h"

#include <cstdio>
#include <cstdlib>
#include <utility>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

static GLFWwindow* s_window;
static unsigned s_width, s_height;
static void (*resizeCallback)(unsigned width, unsigned height) = nullptr;
static void (*drawCallback)() = nullptr;

void Graphics::Window::create(unsigned width, unsigned height,
                              const std::string &title)
{
  if (!glfwInit())
  {
    fprintf(stderr, "glfw: init failed\n");
    exit(1);
  }

  s_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  if (!s_window)
  {
    glfwTerminate();
    fprintf(stderr, "glfw: window creation failed\n");
    exit(1);
  }

  glfwMakeContextCurrent(s_window);

  s_width = width;
  s_height = height;

  auto err = glewInit();
  if (err != GLEW_OK)
  {
    printf("GLEW: error: initialization failed\n");
    exit(1);
  }
}

void Graphics::Window::setDrawCallback(void (*draw)())
{
  drawCallback = draw;
}

void Graphics::Window::exec()
{
  while (!glfwWindowShouldClose(s_window))
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(drawCallback)
      drawCallback();

    glfwSwapBuffers(s_window);
    glfwPollEvents();
  }

  glfwTerminate();
}
