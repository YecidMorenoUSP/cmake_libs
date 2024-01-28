# CMAKE_LIBS

### ImGui Support

```shell

set(imgui_DIR  ${cmake_libs}/imgui)

find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)

set(IMGUI_FILES_CPP ${imgui_DIR}/interfaces/imgui_interface_glfw_opengl2.cpp
                    ${imgui_DIR}/imgui/backends/imgui_impl_glfw.cpp 
                    ${imgui_DIR}/imgui/backends/imgui_impl_opengl2.cpp)

include_directories(${PROJECT_NAME} ${imgui_DIR}/imgui
                                    ${imgui_DIR}/imgui/backends
                                    ${imgui_DIR}/interfaces)

```


### Hot to install
1. Run de next comand in your shell to download cmake_libs repository

    ```shell
    git clone {this-repository} --recursive
    ```
2. Build the **libraries** and **config.cmake** files
   
  ```shell
  cd cmake_libs
  mkdir build
  cd build
  cmake ..
  make [your library]
  ```

### How to use
1. without install libraries, is very important set the variable in cmake enviroment, like this:
   ```shell
   set(cmake_libs_DIR  [your intall directory])
   ```
2. Modify your CMakeLists.txt, use the test files located in **[your library]/test/**

### How to run a test
1. run this comand in your shell
```shell
  cd [test root directory]
  mkdir build
  cd build
  cmake ..
  make 
  [./Name of example]
  ```

## Acknowledgements
Thanks to the ImGui development team for create this fantastic GUI library [Dear ImGui](https://github.com/ocornut/imgui).
