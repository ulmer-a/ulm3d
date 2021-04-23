#include "ShaderProgram.h"

#include <cstdio>
#include <cstdlib>

#include <GL/glew.h>

namespace Graphics {

  Shader::Shader(const char* filename,
                 Shader::ShaderType type)
    : m_type(type)
  {
    m_shaderID = glCreateShader(type);

    std::string sourceCode = fromFile(filename);
    const char* source = sourceCode.c_str();
    glShaderSource(m_shaderID, 1, &source, nullptr);
    glCompileShader(m_shaderID);

    int success;
    char buffer[512];
    glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
      glGetShaderInfoLog(m_shaderID, 512, NULL, buffer);
      fprintf(stderr, "Shader compilation failed\nerror: %s\n", buffer);
      exit(1);
    }
  }

  std::string Shader::fromFile(const char *filename)
  {
    FILE* f = fopen(filename, "r");
    if (!f)
    {
      fprintf(stderr, "error: cannot open file: %s\n", filename);
      exit(1);
    }

    static const std::size_t bufferSize = 1024*32;
    char* buffer = (char*)alloca(bufferSize);
    std::size_t len = fread(buffer, 1, bufferSize, f);
    buffer[len] = 0;

    return std::string(buffer);
  }

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
