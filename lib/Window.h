#pragma once

#include <string>

namespace Graphics {
  namespace Window {

    void create(unsigned width, unsigned height, const std::string& title);

    void setDrawCallback(void (*draw)());

    void exec();

  }
}
