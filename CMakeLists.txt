cmake_minimum_required(VERSION 3.10)
project(RenderEngine)

file(
  GLOB_RECURSE
  lib_files
  ${CMAKE_SOURCE_DIR}/src/*.c
  ${CMAKE_SOURCE_DIR}/include/RenderEngine/*.h
)

add_library(
  RenderEngine
  ${lib_files}
)

target_include_directories(
  RenderEngine PUBLIC
  ${CMAKE_SOURCE_DIR}/vendor/
  ${CMAKE_SOURCE_DIR}/include/RenderEngine/
)

add_executable(square   ${CMAKE_SOURCE_DIR}/examples/square.c)
add_executable(texture   ${CMAKE_SOURCE_DIR}/examples/texture.c)

if (UNIX)
target_link_libraries(
  square PUBLIC
  ${CMAKE_SOURCE_DIR}/build/libRenderEngine.a
  ${CMAKE_SOURCE_DIR}/lib/linux_wayland/libglfw3.a
  -lwayland-client
  -ldl
  -lGL
  -lm
)
target_link_libraries(
  texture PUBLIC
  ${CMAKE_SOURCE_DIR}/build/libRenderEngine.a
  ${CMAKE_SOURCE_DIR}/lib/linux_wayland/libglfw3.a
  -lwayland-client
  -ldl
  -lGL
  -lm
)
endif (UNIX)

if (WIN32)
target_link_libraries(
  square PUBLIC
  ${CMAKE_SOURCE_DIR}/build/libRenderEngine.a
  -ldl
  -lOpenGL32
  -lgdi32
  ${CMAKE_SOURCE_DIR}/lib/libglfw3.a
)
endif (WIN32)

target_include_directories(
  square PUBLIC
  ${CMAKE_SOURCE_DIR}/vendor/
  ${CMAKE_SOURCE_DIR}/include/RenderEngine/
)
target_include_directories(
  texture PUBLIC
  ${CMAKE_SOURCE_DIR}/vendor/
  ${CMAKE_SOURCE_DIR}/include/RenderEngine/
)

