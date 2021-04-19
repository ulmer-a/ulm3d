#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <string>

namespace Graphics {

  struct Face
  {
    unsigned v1, v2, v3;
    unsigned t1, t2, t3;
    unsigned n1, n2, n3;
  };

  class Mesh
  {
    public:
      Mesh(const std::string& objFile);

    private:
      std::vector<glm::vec3> m_vertices;
      std::vector<glm::vec2> m_texCoords;
      std::vector<glm::vec3> m_normals;
      std::vector<Face> m_triangles;
  };

}
