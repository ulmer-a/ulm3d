#include <cstdio>
#include <cstdlib>
#include <utility>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.h"
#include "Scene.h"

static GLFWwindow* s_window;
static unsigned s_width, s_height;
static Ulm3D::Scene* s_scene = nullptr;

void Ulm3D::Window::create(unsigned width, unsigned height,
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

void Ulm3D::Window::exec()
{
  while (!glfwWindowShouldClose(s_window))
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (s_scene)
      s_scene->render();

    glfwSwapBuffers(s_window);
    glfwPollEvents();
  }

  glfwTerminate();
}

void Ulm3D::Window::setScene(Ulm3D::Scene *scene)
{
  s_scene = scene;
}
