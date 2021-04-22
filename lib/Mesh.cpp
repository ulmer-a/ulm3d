#include "Mesh.h"

#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

#include "VertexBuffer.h"

namespace Graphics {

  Mesh::Mesh(const std::string &objFile)
  {
    std::ifstream f(objFile, std::ios::in);
    if (!f)
    {
      printf("cannot open file: %s\n", objFile.c_str());
      exit(1);
    }

    std::string line;
    while (std::getline(f, line))
    {
      if (line.substr(0, 2) == "v ")
      {
        std::istringstream vStream(line.substr(2));
        float x, y, z;
        vStream >> x;
        vStream >> y;
        vStream >> z;
        m_vertices.push_back({x, y, z});
      }
      else if (line.substr(0, 2) == "vt")
      {
        std::istringstream vtStream(line.substr(2));
        double x, y;
        vtStream >> x;
        vtStream >> y;
        m_texCoords.push_back(glm::vec2(x, y));
      }
      else if (line.substr(0, 2) == "vn")
      {
        std::istringstream vnStream(line.substr(2));
        double x, y, z;
        vnStream >> x;
        vnStream >> y;
        vnStream >> z;
        m_normals.push_back(glm::vec3(x, y, z));
      }
      else if (line.substr(0, 2) == "f ")
      {
        unsigned v1, v2, v3;
        unsigned t1, t2, t3;
        unsigned n1, n2, n3;

        const char* cline = line.c_str();
        sscanf(cline, "f %i/%i/%i %i/%i/%i %i/%i/%i",
               &v1, &t1, &n1,
               &v2, &t2, &n2,
               &v3, &t3, &n3);

        Face face;
        face.v1 = v1 - 1;
        face.v2 = v2 - 1;
        face.v3 = v3 - 1;
        face.t1 = t1 - 1;
        face.t2 = t2 - 1;
        face.t3 = t3 - 1;
        face.n1 = n1 - 1;
        face.n2 = n2 - 1;
        face.n3 = n3 - 1;

        m_indices.push_back(face.v1);
        m_indices.push_back(face.v2);
        m_indices.push_back(face.v3);
        m_triangles.push_back(face);
      }
    }

    printf("%s: mesh loaded: %zu vertices, %zu triangles\n",
           objFile.c_str(), m_vertices.size(), m_triangles.size());

    setData(m_vertices.data(), m_vertices.size(),
            m_indices.data(), m_indices.size());
  }
}
