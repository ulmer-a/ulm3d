#pragma once

#include <cstdint>
#include <memory>

namespace Graphics {

  struct Vertex
  {
    float pos_x, pos_y, pos_z;
  } __attribute__((packed));

  class VertexBuffer
  {
    public:
      VertexBuffer();

      void setData(Vertex* vertices, std::size_t vertexCount,
                   unsigned* indices, std::size_t indexCount);

      void bind();
      void unbind();
      void render();

    private:
      unsigned m_indexCount;
      unsigned m_vertexBuffer, m_vertexArray, m_indexBuffer;
  };

}



