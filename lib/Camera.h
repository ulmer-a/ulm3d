#pragma once

#include <glm/glm.hpp>

namespace Ulm3D {

  class Camera
  {
    public:
      Camera(glm::vec3 pos, glm::vec3 posLookAt = glm::vec3(0.0f, 0.0f, 0.0f),
             glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f));

      void setCameraPos(glm::vec3 position);
      void setLookatPos(glm::vec3 lookAt);
      void setUpVector(glm::vec3 upVector);

      inline const glm::mat4& getViewMat() const { return m_viewMatrix; }

    private:
      void updateViewMat();

    private:
      glm::vec3 m_pos, m_posLookAt, m_upVector;
      glm::mat4 m_viewMatrix;
  };

}
