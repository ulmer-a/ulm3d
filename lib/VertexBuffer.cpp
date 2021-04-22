#include "VertexBuffer.h"

#include <GL/glew.h>

namespace Graphics {

  VertexBuffer::VertexBuffer(Vertex* data, std::size_t vertexCount,
                             unsigned* indices, std::size_t indexCount)
    : m_vertexCount(vertexCount)
    , m_indexCount(indexCount)
  {
    glGenBuffers(1, &m_vertexBufferID);
    glGenBuffers(1, &m_indexBufferID);

    // fill vertex buffer with data and set the layout
    bindVertexBuffer();
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(Vertex),
                 (void*)data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3,  0);

    bindIndexBuffer();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int),
                 indices, GL_STATIC_DRAW);
  }

  void VertexBuffer::bindVertexBuffer()
  {
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
  }

  void VertexBuffer::bindIndexBuffer()
  {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID);
  }

  void VertexBuffer::drawTriangles()
  {
    bindVertexBuffer();
    bindIndexBuffer();
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
  }

}
