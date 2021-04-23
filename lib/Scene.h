#pragma once

#include <vector>
#include <memory>
#include <glm/glm.hpp>

#include "Camera.h"
#include "MeshObject.h"

namespace Ulm3D {

  class Scene
  {
    public:
      Scene(unsigned width, unsigned height, Camera& camera);

      void addObject(std::shared_ptr<MeshObject> object);

      inline const glm::mat4& getProjectionMat() const
      {
        return m_projectionMat;
      }

      inline const glm::mat4& getViewMat() const
      {
        return m_camera.getViewMat();
      }

      void render();

      void updateProjectionMat();
      void resized(unsigned width, unsigned height);

    private:
      const Camera& m_camera;
      glm::mat4 m_VP, m_projectionMat;
      unsigned m_width, m_height;

      std::vector<std::shared_ptr<MeshObject>> m_objects;

  };

}
