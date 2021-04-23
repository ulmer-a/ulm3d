#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>

#include "Shader.h"

namespace Ulm3D {

  class ShaderProgram
  {
    public:
      /* Creates and deletes an OpenGL shader program object */
      ShaderProgram();
      ~ShaderProgram();

      /* Every shader has to be attached to a ShaderProgram,
       * so it can be linked and used. After calling addShader(),
       * the Shader object can be disposed. */
      void addShader(const Shader& shader);

      /* Get a handle to a uniform by it's name */
      unsigned getUniform(const char* name);

      /* Set uniform with value 'id' to the specified value, so
       * the new value becomes available in the shader program. */
      void setUniform(unsigned id, float value);
      void setUniform(unsigned id, const glm::vec2& vec);
      void setUniform(unsigned id, const glm::vec3& vec);
      void setUniform(unsigned id, const glm::mat4& mat);

      void link();
      void use();

    private:
      unsigned m_id;
  };

}
