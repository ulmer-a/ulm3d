#pragma once

#include <string>

namespace Ulm3D {

  class Scene;

  namespace Window {

    void create(unsigned width, unsigned height, const std::string& title);

    void setScene(Scene* scene);

    void exec();

  }
}
