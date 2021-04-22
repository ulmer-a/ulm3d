#pragma once

#include <cstdint>

namespace Graphics {

  class VertexBuffer
  {
    public:
      struct Vertex
      {
        float pos_x, pos_y, pos_z;
      } __attribute__((packed));

      VertexBuffer(Vertex* data, std::size_t vertexCount,
                   unsigned* indices, std::size_t indexCount);

      void bindVertexBuffer();
      void bindIndexBuffer();
      void drawTriangles();

    private:
      unsigned m_vertexBufferID, m_indexBufferID;
      unsigned m_vertexCount, m_indexCount;
  };

}



