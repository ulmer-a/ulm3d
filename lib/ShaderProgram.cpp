#include <cstdio>
#include <cstdlib>

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "ShaderProgram.h"

namespace Ulm3D {

  ShaderProgram::ShaderProgram()
  {
    m_id = glCreateProgram();
  }

  ShaderProgram::~ShaderProgram()
  {
    glDeleteProgram(m_id);
  }

  void ShaderProgram::addShader(const Shader &shader)
  {
    glAttachShader(m_id, shader.getID());
  }

  unsigned ShaderProgram::getUniform(const char *name)
  {
    return glGetUniformLocation(m_id, name);
  }

  void ShaderProgram::setUniform(unsigned id, const glm::mat4 &mat)
  {
    glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(mat));
  }

  void ShaderProgram::link()
  {
    glLinkProgram(m_id);

    int success;
    char buffer[512];
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if(!success)
    {
      glGetProgramInfoLog(m_id, 512, NULL, buffer);
      fprintf(stderr, "ShaderProgram: link() failed\nerror: %s\n", buffer);
      exit(1);
    }
  }

  void ShaderProgram::use()
  {
    glUseProgram(m_id);
  }

}
