#pragma once

#include <memory>
#include "Mesh.h"

namespace Ulm3D {

  class Scene;
  class ShaderProgram;

  class MeshObject
  {
    public:
      MeshObject(const char* meshFile, ShaderProgram* shader = nullptr);
      MeshObject(std::shared_ptr<Mesh> mesh, ShaderProgram* shader = nullptr);

      void draw(const Scene& scene);

    private:
      void getUniforms();

    private:
      ShaderProgram* m_shader;
      unsigned u_mvp;
      std::shared_ptr<Mesh> m_mesh;
  };

}
