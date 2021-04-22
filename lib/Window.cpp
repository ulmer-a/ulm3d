#include "Window.h"

#include <cstdio>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <GL/glew.h>


static sf::Window* s_window;
static unsigned s_width, s_height;
static void (*resizeCallback)(unsigned width, unsigned height) = nullptr;
static void (*drawCallback)() = nullptr;


void Graphics::Window::setDrawCallback(void (*draw)())
{
  drawCallback = draw;
}

void Graphics::Window::init(unsigned width, unsigned height, const std::string &title)
{
  s_window = new sf::Window(sf::VideoMode(width, height), title);

  s_width = width;
  s_height = height;

  s_window->setVerticalSyncEnabled(true);
  s_window->setActive(true);

  auto err = glewInit();
  if (err != GLEW_OK)
  {
    printf("GLEW: error: initialization failed\n");
    exit(1);
  }
}

void Graphics::Window::exec()
{
  bool running = true;
  while (running)
  {
    sf::Event event;
    while (s_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        running = false;
      }
      else if (event.type == sf::Event::Resized)
      {
        s_width = event.size.width;
        s_height = event.size.height;

        glViewport(0, 0, s_width, s_height);

        if (resizeCallback)
          resizeCallback(s_width, s_height);
      }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(drawCallback)
      drawCallback();

    s_window->display();
  }
}
