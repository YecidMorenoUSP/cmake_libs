cmake_minimum_required (VERSION 3.6)
project(imgui)

set(IMGUI_DIRECTORY imgui)

file(GLOB IMGUI_FILES_CPP_1 ${IMGUI_DIRECTORY}/*.cpp)

set(IMGUI_FILES_CPP ${IMGUI_FILES_CPP_1} ${IMGUI_FILES_CPP_2})


set(IMGUI_HEADER_FILES "")

LIST(APPEND IMGUI_HEADER_FILES "${CMAKE_HOME_DIRECTORY}/imgui/imgui") 
LIST(APPEND IMGUI_HEADER_FILES "${CMAKE_HOME_DIRECTORY}/imgui/imgui/backends") 
LIST(APPEND IMGUI_HEADER_FILES "${CMAKE_HOME_DIRECTORY}/imgui/interfaces") 

set(IMGUI_HEADER_FILES ${IMGUI_HEADER_FILES} CACHE INTERNAL "_IMGUI_HEADER_FILES")
set(IMGUI_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/imgui CACHE STRING "_IMGUI_SOURCE_DIR")

message(STATUS "Home:   ${CMAKE_CURRENT_BINARY_DIR} ")
foreach(imgui_header_file $CACHE{IMGUI_HEADER_FILES})
  message(STATUS "IMGUI_HEADER_FILES='${imgui_header_file}'")
endforeach()




add_library(imgui STATIC)
target_include_directories(imgui PRIVATE ${IMGUI_HEADER_FILES})
target_sources(imgui PRIVATE ${IMGUI_FILES_CPP})

install(TARGETS imgui
    EXPORT imguiConfig
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})


export(TARGETS
        imgui
        NAMESPACE imgui::
    FILE "${CMAKE_HOME_DIRECTORY}/imgui/imguiConfig.cmake"
)

install(EXPORT
        imguiConfig
    DESTINATION "${CMAKE_INSTALL_DATADIR}/imgui/cmake"
    NAMESPACE imgui::
)


