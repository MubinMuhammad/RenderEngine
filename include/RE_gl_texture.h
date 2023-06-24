#ifndef RE_TEXTURE_H
#define RE_TEXTURE_H

#include "glad/glad.h"

typedef enum RE_texture_type {
  RE_TEXTURE_PNG,
  RE_TEXTURE_JPG,
  RE_TEXTURE_TGA
} RE_texture_type;

typedef struct RE_texture {
  int width;
  int height;
  
  unsigned char *data;
  int color_channels;

  int texture_index;
  unsigned int id;

} RE_texture;

RE_texture RE_texture_create(const char *texture_path, RE_texture_type texture_type);
void       RE_texture_bind(RE_texture texture, int texture_slot);
void       RE_texture_terminate(RE_texture *texture);

#endif
