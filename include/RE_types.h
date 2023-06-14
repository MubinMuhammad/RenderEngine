#ifndef RE_TYPES_H
#define RE_TYPES_H

typedef int                      i32;
typedef short int                i16;
typedef long long int            i64;
typedef char                     i8;
typedef unsigned char            u8;
typedef unsigned short int       u16;
typedef unsigned int             u32;
typedef unsigned long long int   u64;
typedef float                    f32;
typedef double                   f64;

typedef float RE_vec4  [4];
typedef float RE_vec3  [3];
typedef float RE_vec2  [2];
typedef int   RE_ivec4 [4];
typedef int   RE_ivec3 [3];
typedef int   RE_ivec2 [2];
typedef float RE_quat  [4];
typedef float RE_mat4x4[4][4];
typedef float RE_mat3x3[3][3];
typedef float RE_mat2x2[2][2];

#endif
