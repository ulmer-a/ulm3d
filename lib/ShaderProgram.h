#pragma once

#include <string>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>

namespace Graphics {

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

      Shader(const char *filename,
             ShaderType type);

      static std::string fromFile(const char *filename);

    protected:
      unsigned getID() const { return m_shaderID; }

    private:
      ShaderType m_type;
      unsigned m_shaderID;
  };

  class ShaderProgram
  {
    public:
      ShaderProgram();
      ~ShaderProgram();

      void addShader(const Shader& shader);

      unsigned getUniform(const char* name);
      void uniformMat4(unsigned id, const glm::mat4& mat);

      void link();
      void use();

    private:
      unsigned m_id;
  };

}
