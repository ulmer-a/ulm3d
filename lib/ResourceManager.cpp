#include "ResourceManager.h"

namespace ResourceManager {

  std::string readFile(const char *filename)
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

}
