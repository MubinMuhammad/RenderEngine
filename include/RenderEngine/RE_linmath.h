#ifndef RE_LINMATH_H
#define RE_LINMATH_H

#include <math.h>
#include <string.h>

#include "RE_types.h"

void  RE_vec4_add       (RE_vec4 r, RE_vec4 const a, RE_vec4 const b);
void  RE_vec4_sub       (RE_vec4 r, RE_vec4 const a, RE_vec4 const b);
void  RE_vec4_scale     (RE_vec4 r, RE_vec4 const v,   float s);
float RE_vec4_mul_inner (RE_vec4 const a, RE_vec4 const b);
float RE_vec4_len       (RE_vec4 const v);
void  RE_vec4_norm      (RE_vec4 r, RE_vec4 const v);
void  RE_vec4_min       (RE_vec4 r, RE_vec4 const a, RE_vec4 const b);
void  RE_vec4_max       (RE_vec4 r, RE_vec4 const a, RE_vec4 const b);
void  RE_vec4_dup       (RE_vec4 r, RE_vec4 const s);

void  RE_vec3_add       (RE_vec3 r, RE_vec3 const a, RE_vec3 const b);
void  RE_vec3_sub       (RE_vec3 r, RE_vec3 const a, RE_vec3 const b);
void  RE_vec3_scale     (RE_vec3 r, RE_vec3 const v,   float s);
float RE_vec3_mul_inner (RE_vec3 const a, RE_vec3 const b);
float RE_vec3_len       (RE_vec3 const v);
void  RE_vec3_norm      (RE_vec3 r, RE_vec3 const v);
void  RE_vec3_min       (RE_vec3 r, RE_vec3 const a, RE_vec3 const b);
void  RE_vec3_max       (RE_vec3 r, RE_vec3 const a, RE_vec3 const b);
void  RE_vec3_dup       (RE_vec3 r, RE_vec3 const s);

void  RE_vec2_add       (RE_vec2 r, RE_vec2 const a, RE_vec2 const b);
void  RE_vec2_sub       (RE_vec2 r, RE_vec2 const a, RE_vec2 const b);
void  RE_vec2_scale     (RE_vec2 r, RE_vec2 const v,   float s);
float RE_vec2_mul_inner (RE_vec2 const a, RE_vec2 const b);
float RE_vec2_len       (RE_vec2 const v);
void  RE_vec2_norm      (RE_vec2 r, RE_vec2 const v);
void  RE_vec2_min       (RE_vec2 r, RE_vec2 const a, RE_vec2 const b);
void  RE_vec2_max       (RE_vec2 r, RE_vec2 const a, RE_vec2 const b);
void  RE_vec2_dup       (RE_vec2 r, RE_vec2 const s);


void  RE_vec3_mul_cross             (RE_vec3 r,   RE_vec3 const a, RE_vec3 const b);
void  RE_vec3_reflect               (RE_vec3 r,   RE_vec3 const v, RE_vec3 const n);
void  RE_vec4_mul_cross             (RE_vec4 r,   RE_vec4 const a, RE_vec4 const b);
void  RE_vec4_reflect               (RE_vec4 r,   RE_vec4 const v, RE_vec4 const n);
void  RE_mat4x4_identity            (RE_mat4x4 M);
void  RE_mat4x4_dup                 (RE_mat4x4 M, RE_mat4x4 const N);
void  RE_mat4x4_row                 (RE_vec4 r,   RE_mat4x4 const M, int i);
void  RE_mat4x4_col                 (RE_vec4 r,   RE_mat4x4 const M, int i);
void  RE_mat4x4_transpose           (RE_mat4x4 M, RE_mat4x4 const N);
void  RE_mat4x4_add                 (RE_mat4x4 M, RE_mat4x4 const a, RE_mat4x4 const b);
void  RE_mat4x4_sub                 (RE_mat4x4 M, RE_mat4x4 const a, RE_mat4x4 const b);
void  RE_mat4x4_scale               (RE_mat4x4 M, RE_mat4x4 const a, float k);
void  RE_mat4x4_scale_aniso         (RE_mat4x4 M, RE_mat4x4 const a, float x, float y, float z);
void  RE_mat4x4_mul                 (RE_mat4x4 M, RE_mat4x4 const a, RE_mat4x4 const b);
void  RE_mat4x4_mul_vec4            (RE_vec4 r,   RE_mat4x4 const M, RE_vec4 const v);
void  RE_mat4x4_translate           (RE_mat4x4 T, float x, float y, float z);
void  RE_mat4x4_translate_in_place  (RE_mat4x4 M, float x, float y, float z);
void  RE_mat4x4_from_vec3_mul_outer (RE_mat4x4 M, RE_vec3 const a, RE_vec3 const b);
void  RE_mat4x4_rotate              (RE_mat4x4 R, RE_mat4x4 const M, float x, float y, float z, float angle);
void  RE_mat4x4_rotate_X            (RE_mat4x4 Q, RE_mat4x4 const M, float angle);
void  RE_mat4x4_rotate_Y            (RE_mat4x4 Q, RE_mat4x4 const M, float angle);
void  RE_mat4x4_rotate_Z            (RE_mat4x4 Q, RE_mat4x4 const M, float angle);
void  RE_mat4x4_invert              (RE_mat4x4 T, RE_mat4x4 const M);
void  RE_mat4x4_orthonormalize      (RE_mat4x4 R, RE_mat4x4 const M);
void  RE_mat4x4_frustum             (RE_mat4x4 M, float l, float r, float b, float t, float n, float f);
void  RE_mat4x4_ortho               (RE_mat4x4 M, float l, float r, float b, float t, float n, float f);
void  RE_mat4x4_perspective         (RE_mat4x4 m, float y_fov, float aspect, float n, float f);
void  RE_mat4x4_look_at             (RE_mat4x4 m, RE_vec3 const eye, RE_vec3 const center, RE_vec3 const up);


#define quat_add        vec3_add
#define quat_sub        vec3_sub
#define quat_norm       vec3_norm
#define quat_scale      vec3_scale
#define quat_mul_inner  vec3_mul_inner

void  RE_quat_identity    (RE_quat q);
void  RE_quat_mul         (RE_quat r, RE_quat const p, RE_quat const q);
void  RE_quat_conj        (RE_quat r, RE_quat const q);
void  RE_quat_rotate      (RE_quat r, float angle, RE_vec3 const axis);
void  RE_quat_mul_vec3    (RE_vec3 r, RE_quat const q, RE_vec3 const v);
void  RE_mat4x4_from_quat (RE_mat4x4 M, RE_quat const q);
void  RE_mat4x4o_mul_quat (RE_mat4x4 R, RE_mat4x4 const M, RE_quat const q);
void  RE_quat_from_mat4x4 (RE_quat q, RE_mat4x4 const M);
void  RE_mat4x4_arcball   (RE_mat4x4 R, RE_mat4x4 const M, RE_vec2 const _a, RE_vec2 const _b, float s);

#endif
