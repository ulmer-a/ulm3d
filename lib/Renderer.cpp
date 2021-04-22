#include "Renderer.h"

#include <GL/glew.h>

namespace Graphics {
  namespace Renderer {

    void drawTriangles(unsigned count)
    {
      glDrawElements(GL_TRIANGLES, count * 3, GL_UNSIGNED_INT, nullptr);
    }

  }
}
