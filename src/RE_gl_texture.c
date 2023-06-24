#include "RE_gl_texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

RE_texture RE_texture_create(const char *texture_path, RE_texture_type texture_type) {
  stbi_set_flip_vertically_on_load(1);

  RE_texture texture;
  texture.data = stbi_load(texture_path, &texture.width, 
                           &texture.height, &texture.color_channels, 
                           texture_type == RE_TEXTURE_JPG ||
                           texture_type == RE_TEXTURE_TGA ? 3 : 
                           texture_type == RE_TEXTURE_PNG ? 4 : 0);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

  glGenTextures(1, &texture.id);
  glBindTexture(GL_TEXTURE_2D, texture.id);

  if (texture.data) {
    glTexImage2D(GL_TEXTURE_2D, 0, 
                 texture_type == RE_TEXTURE_JPG || 
                 texture_type == RE_TEXTURE_TGA ? 
                 GL_RGB8 : GL_RGBA8, 
                 texture.width, texture.height, 0, 
                 texture_type == RE_TEXTURE_JPG || 
                 texture_type == RE_TEXTURE_TGA ? 
                 GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, texture.data);

    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else {
    printf("__RENDER_ENGINE_ERROR: Cannot find Image. Or invalid format.");
    exit(-1);
  }

  glBindTexture(GL_TEXTURE_2D, 0);
  stbi_image_free(texture.data);
  
  return texture;
}

void RE_texture_bind(RE_texture texture, int texture_slot) {
  glActiveTexture(GL_TEXTURE0 + texture_slot);
  glBindTexture(GL_TEXTURE_2D, texture.id);
}

void RE_texture_terminate(RE_texture *texture) {
  glDeleteTextures(1, &texture->id);
}
