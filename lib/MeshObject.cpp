#include "Scene.h"
#include "Mesh.h"
#include "MeshObject.h"
#include "ShaderProgram.h"

namespace Ulm3D {

  MeshObject::MeshObject(const char *meshFile, ShaderProgram *shader)
    : m_mesh(std::make_shared<Mesh>(meshFile))
    , m_shader(shader)
  {
    getUniforms();
  }

  MeshObject::MeshObject(std::shared_ptr<Mesh> mesh, ShaderProgram* shader)
      : m_mesh(mesh)
      , m_shader(shader)
  {
    getUniforms();
  }

  void MeshObject::draw(const Scene &scene)
  {
    m_shader->use();

    auto mvpMat = scene.getProjectionMat() * scene.getViewMat();
    m_shader->setUniform(u_mvp, mvpMat);

    m_mesh->render();
  }

  void MeshObject::getUniforms()
  {
    if (m_shader)
    {
      m_shader->use();
      u_mvp = m_shader->getUniform("u_MVP");
    }
  }

}
