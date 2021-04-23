#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>

namespace Ulm3D {

  class ShaderProgram;

  class Shader
  {
      friend class ShaderProgram;

    public:
      enum ShaderType
      {
        VertexShader = GL_VERTEX_SHADER,
        FragmentShader = GL_FRAGMENT_SHADER
      };

      /* Create and compile a shader given it's filename. */
      Shader(const char *filename, ShaderType type);

    protected:
      /* for internal use: provide ShaderProgram with the
       * OpenGL-internal id of the Shader so it can be attached
       * and linked.  */
      unsigned getID() const { return m_shaderID; }

    private:
      ShaderType m_type;
      unsigned m_shaderID;
  };

}
