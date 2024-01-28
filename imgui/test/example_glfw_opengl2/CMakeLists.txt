# cmake_minimum_required (VERSION 3.6)

project(example_glfw_opengl2)

set(cmake_libs_DIR  ../../..)

###################
## include imgui ##
###################
set(imgui_DIR  ${cmake_libs_DIR}/imgui)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(imgui REQUIRED)

set(IMGUI_FILES_CPP ${imgui_DIR}/interfaces/imgui_interface_glfw_opengl2.cpp
                    ${imgui_DIR}/imgui/backends/imgui_impl_glfw.cpp 
                    ${imgui_DIR}/imgui/backends/imgui_impl_opengl2.cpp)

include_directories(${PROJECT_NAME} ${imgui_DIR}/imgui
                                    ${imgui_DIR}/imgui/backends
                                    ${imgui_DIR}/interfaces)


###################
##    Compile    ##
###################
file(GLOB "${PROJECT_NAME}_SOURCES" *.cpp)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES} ${IMGUI_FILES_CPP})

target_link_libraries(${PROJECT_NAME} glfw GL imgui::imgui)

# install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
