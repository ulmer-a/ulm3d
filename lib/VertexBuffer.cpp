#include <GL/glew.h>
#include <vector>

#include "VertexBuffer.h"
#include "Mesh.h"

namespace Ulm3D {

  VertexBuffer::VertexBuffer()
  {
    glGenVertexArrays(1, &m_vertexArray);
    glGenBuffers(1, &m_vertexBuffer);
    glGenBuffers(1, &m_indexBuffer);
  }

  void VertexBuffer::setData(Vertex *vertices, std::size_t vertexCount,
                             unsigned *indices, std::size_t indexCount)
  {
    m_indexCount = indexCount;
    bind();

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(Vertex),
                 vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned),
                 indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

    unbind();
  }

  void VertexBuffer::bind()
  {
    glBindVertexArray(m_vertexArray);
  }

  void VertexBuffer::unbind()
  {
    glBindVertexArray(0);
  }

  void VertexBuffer::render()
  {
    bind();
    glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, nullptr);
    unbind();
  }

}
