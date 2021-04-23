#include <glm/gtx/transform.hpp>

#include "Scene.h"
#include "MeshObject.h"

namespace Ulm3D {

  Scene::Scene(unsigned width, unsigned height, Camera &camera)
    : m_width(width)
    , m_height(height)
    , m_camera(camera)
  {
    m_projectionMat = glm::perspective(
          glm::radians(45.0f), (float)width / (float)height, 1.0f, 100.0f);
  }

  void Scene::addObject(std::shared_ptr<MeshObject> object)
  {
    m_objects.push_back(object);
  }

  void Scene::render()
  {
    for (auto& obj : m_objects)
    {
      obj->draw(*this);
    }
  }

}
