
#include <cstdio>
#include <cstdlib>

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "ShaderProgram.h"
#include "ResourceManager.h"


namespace Ulm3D {

  Shader::Shader(const char* filename,
                 Shader::ShaderType type)
    : m_type(type)
  {
    m_shaderID = glCreateShader(type);

    std::string sourceCode = ResourceManager::readFile(filename);
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
}
