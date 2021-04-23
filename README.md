## Ulm3D

Small OpenGL 3D rendering framework I use to play around with OpenGL. Features include:

* Can load meshes from Wavefront OBJ files
* Can load vertex and fragment shaders from disk and use them
* Standard rendering pipeline using Model-View-Projection matrices

### Dependencies
* GLFW Window library
* GLEW OpenGL loader library
* GLM OpenGL math library

For now, you'll have to download them and install them on your system. In the future,
these will be included in the project's source tree directly using git submodules. That
allows these packages to be statically linked into the binary.

### Building
Follow the standard `cmake` build routine.

```
$ mkdir build && cd build
$ cmake ..
$ make -j
```

### Running
Make sure that when you run the binary, the data directory is in the working directory. It
includes shader sources and mesh data.
