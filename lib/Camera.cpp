#include <glm/gtx/transform.hpp>
#include "Camera.h"

namespace Ulm3D {

  Camera::Camera(glm::vec3 pos, glm::vec3 posLookAt, glm::vec3 upVector)
    : m_pos(pos)
    , m_posLookAt(posLookAt)
    , m_upVector(upVector)
  {
    updateViewMat();
  }

  void Camera::setCameraPos(glm::vec3 position)
  {
    m_pos = position;
    updateViewMat();
  }

  void Camera::setLookatPos(glm::vec3 lookAt)
  {
    m_posLookAt = lookAt;
    updateViewMat();
  }

  void Camera::setUpVector(glm::vec3 upVector)
  {
    m_upVector = m_upVector;
    updateViewMat();
  }

  void Camera::updateViewMat()
  {
    /* Compute the camera coordinate system base vectors
     * and return the coordinate transformation matrix. */
    m_viewMatrix = glm::lookAt(m_pos, m_posLookAt, m_upVector);
  }

}
