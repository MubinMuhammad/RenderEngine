cmake_minimum_required(VERSION 3.10)
project(RenderEngine)

file(
  GLOB_RECURSE
  lib_files
  ${CMAKE_SOURCE_DIR}/src/*.c
  ${CMAKE_SOURCE_DIR}/include/*.h
)

add_library(
  RenderEngine
  ${lib_files}
)

target_include_directories(
  RenderEngine PUBLIC
  ${CMAKE_SOURCE_DIR}/include/vendor/
  ${CMAKE_SOURCE_DIR}/include/
)

add_executable(Square   ${CMAKE_SOURCE_DIR}/examples/square.c)

if (UNIX)
target_link_libraries(
  Square PUBLIC
  ${CMAKE_SOURCE_DIR}/build/libRenderEngine.a
  -ldl
  -lGL
  -lglfw
  -lm
)
endif (UNIX)

if (WIN32)
target_link_libraries(
  Square PUBLIC
  ${CMAKE_SOURCE_DIR}/build/libRenderEngine.a
  -ldl
  -lOpenGL32
  -lgdi32
)
endif (WIN32)

target_include_directories(
  Square PUBLIC
  ${CMAKE_SOURCE_DIR}/include/vendor/
  ${CMAKE_SOURCE_DIR}/include/
)
