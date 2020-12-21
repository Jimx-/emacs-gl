cmake_minimum_required(VERSION 3.11)

project(emacs-gl)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

find_package(OpenGL REQUIRED COMPONENTS GLX)

include_directories(${CONAN_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${PROJECT_BINARY_DIR}/imgui
        )

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

set(GL_MODULE_SRCLIST
        gl-module.c
        emacs-module-helpers.c
        glenums.c
        glfuncs.c
        texture.c
        gui.cpp
        ${PROJECT_BINARY_DIR}/imgui/imgui_impl_opengl3.cpp
        )

add_library(gl-module MODULE ${GL_MODULE_SRCLIST})
set_target_properties(gl-module PROPERTIES
  C_STANDARD 99
  POSITION_INDEPENDENT_CODE ON
  PREFIX ""
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
  )

target_link_libraries(gl-module CONAN_PKG::glad OpenGL::GLX CONAN_PKG::stb
                                CONAN_PKG::imgui)
