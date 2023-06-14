#include "RE_linmath.h"

void  RE_vec4_add(RE_vec4 r, RE_vec4 const a, RE_vec4 const b) {
	for(int i = 0; i < 4; i++)
		r[i] = a[i] + b[i];
}
void  RE_vec4_sub(RE_vec4 r, RE_vec4 const a, RE_vec4 const b) {
	for(int i = 0; i < 4; i++)
		r[i] = a[i] - b[i];
}
void  RE_vec4_scale(RE_vec4 r, RE_vec4 const v,   float s) {
  for (int i = 0; i < 4; i++)
      r[i] = v[i] * s;
}
float RE_vec4_mul_inner(RE_vec4 const a, RE_vec4 const b) {
  float p = 0.0f;
  for (int i = 0; i < 4; i++)
      p += b[i] * a[i];
  return p;
}
float RE_vec4_len(RE_vec4 const v) {
  return sqrt(RE_vec4_mul_inner(v, v));
}
void  RE_vec4_norm(RE_vec4 r, RE_vec4 const v) {
	float k = 1.0f / RE_vec4_len(v);
	RE_vec4_scale(r, v, k);
}
void  RE_vec4_min(RE_vec4 r, RE_vec4 const a, RE_vec4 const b) {
	for (int i = 0; i < 4; i++)
		r[i] = a[i] < b[i] ? a[i] : b[i];
}
void  RE_vec4_max(RE_vec4 r, RE_vec4 const a, RE_vec4 const b) {
	for (int i = 0; i < 4; i++)
		r[i] = a[i] > b[i] ? a[i] : b[i];
}
void  RE_vec4_dup(RE_vec4 r, RE_vec4 const s) {
	for (int i = 0; i < 4; i++)
		r[i] = s[i];
}


void  RE_vec3_add(RE_vec3 r, RE_vec3 const a, RE_vec3 const b) {
	for(int i = 0; i < 3; i++)
		r[i] = a[i] + b[i];
}
void  RE_vec3_sub(RE_vec3 r, RE_vec3 const a, RE_vec3 const b) {
	for(int i = 0; i < 3; i++)
		r[i] = a[i] - b[i];
}
void  RE_vec3_scale(RE_vec3 r, RE_vec3 const v,   float s) {
  for (int i = 0; i < 3; i++)
    r[i] = v[i] * s;
}
float RE_vec3_mul_inner(RE_vec3 const a, RE_vec3 const b) {
  float p = 0.0f;
  for (int i = 0; i < 3; i++)
    p += b[i] * a[i];
  return p;
}
float RE_vec3_len(RE_vec3 const v) {
  return sqrt(RE_vec3_mul_inner(v, v));
}
void  RE_vec3_norm(RE_vec4 r, RE_vec3 const v) {
	float k = 1.0f / RE_vec3_len(v);
	RE_vec3_scale(r, v, k);
}
void  RE_vec3_min(RE_vec3 r, RE_vec3 const a, RE_vec3 const b) {
	for (int i = 0; i < 3; i++)
		r[i] = a[i] < b[i] ? a[i] : b[i];
}
void  RE_vec3_max(RE_vec3 r, RE_vec3 const a, RE_vec3 const b) {
	for (int i = 0; i < 3; i++)
		r[i] = a[i] > b[i] ? a[i] : b[i];
}
void  RE_vec3_dup(RE_vec3 r, RE_vec3 const s) {
	for (int i = 0; i < 3; i++)
		r[i] = s[i];
}


void  RE_vec2_add(RE_vec2 r, RE_vec2 const a, RE_vec2 const b) {
	for(int i = 0; i < 2; i++)
		r[i] = a[i] + b[i];
}
void  RE_vec2_sub(RE_vec2 r, RE_vec2 const a, RE_vec2 const b) {
	for(int i = 0; i < 2; i++)
		r[i] = a[i] - b[i];
}
void  RE_vec2_scale(RE_vec2 r, RE_vec2 const v,   float s) {
  for (int i = 0; i < 2; i++)
    r[i] = v[i] * s;
}
float RE_vec2_mul_inner(RE_vec2 const a, RE_vec2 const b) {
  float p = 0.0f;
  for (int i = 0; i < 2; i++)
    p += b[i] * a[i];
  return p;
}
float RE_vec2_len(RE_vec2 const v) {
  return sqrt(RE_vec2_mul_inner(v, v));
}
void  RE_vec2_norm(RE_vec2 r, RE_vec2 const v) {
	float k = 1.0f / RE_vec2_len(v);
	RE_vec2_scale(r, v, k);
}
void  RE_vec2_min(RE_vec2 r, RE_vec2 const a, RE_vec2 const b) {
	for (int i = 0; i < 2; i++)
		r[i] = a[i] < b[i] ? a[i] : b[i];
}
void  RE_vec2_max(RE_vec2 r, RE_vec2 const a, RE_vec2 const b) {
	for (int i = 0; i < 2; i++)
		r[i] = a[i] > b[i] ? a[i] : b[i];
}
void  RE_vec2_dup(RE_vec2 r, RE_vec2 const s) {
	for (int i = 0; i < 2; i++)
		r[i] = s[i];
}




void  RE_vec3_mul_cross(RE_vec3 r,   RE_vec3 const a, RE_vec3 const b) {
	r[0] = a[1]*b[2] - a[2]*b[1];
	r[1] = a[2]*b[0] - a[0]*b[2];
	r[2] = a[0]*b[1] - a[1]*b[0];
}
void  RE_vec3_reflect(RE_vec3 r,   RE_vec3 const v, RE_vec3 const n) {
	float p = 2.0f * RE_vec3_mul_inner(v, n);
	for(int i = 0; i < 3 ; i++)
		r[i] = v[i] - p * n[i];
}
void  RE_vec4_mul_cross(RE_vec4 r,   RE_vec4 const a, RE_vec4 const b) {
	r[0] = a[1]*b[2] - a[2]*b[1];
	r[1] = a[2]*b[0] - a[0]*b[2];
	r[2] = a[0]*b[1] - a[1]*b[0];
	r[3] = 1.f;
}
void  RE_vec4_reflect(RE_vec4 r,   RE_vec4 const v, RE_vec4 const n) {
	float p  = 2.0f * RE_vec4_mul_inner(v, n);
	for(int i = 0; i < 4; i++)
		r[i] = v[i] - p * n[i];
}
void  RE_mat4x4_identity(RE_mat4x4 M) {
	for (int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			M[i][j] = i == j ? 1.0f : 0.0f;
}
void  RE_mat4x4_dup(RE_mat4x4 M, RE_mat4x4 const N) {
	for(int i = 0; i < 4; i++)
		RE_vec4_dup(M[i], N[i]);
}
void  RE_mat4x4_row(RE_vec4 r, RE_mat4x4 const M, int i) {
	for(int k=0; k<4; ++k)
		r[k] = M[k][i];
}
void  RE_mat4x4_col(RE_vec4 r, RE_mat4x4 const M, int i) {
	for(int k = 0; k < 4; k++)
		r[k] = M[i][k];
}
void  RE_mat4x4_transpose(RE_mat4x4 M, RE_mat4x4 const N) {
	for(int j = 0; j < 4; j++)
		for(int i = 0; i < 4; i++)
			M[i][j] = N[j][i];
}
void  RE_mat4x4_add(RE_mat4x4 M, RE_mat4x4 const a, RE_mat4x4 const b) {
	for(int i=0; i<4; ++i)
		RE_vec4_add(M[i], a[i], b[i]);
}
void  RE_mat4x4_sub(RE_mat4x4 M, RE_mat4x4 const a, RE_mat4x4 const b) {
	for(int i = 0; i < 4; i++)
		RE_vec4_sub(M[i], a[i], b[i]);
}
void  RE_mat4x4_scale(RE_mat4x4 M, RE_mat4x4 const a, float k) {
	for(int i = 0; i < 4; i++)
		RE_vec4_scale(M[i], a[i], k);
}
void  RE_mat4x4_scale_aniso(RE_mat4x4 M, RE_mat4x4 const a, float x, float y, float z) {
	RE_vec4_scale(M[0], a[0], x);
	RE_vec4_scale(M[1], a[1], y);
	RE_vec4_scale(M[2], a[2], z);
	RE_vec4_dup(M[3], a[3]);
}
void  RE_mat4x4_mul(RE_mat4x4 M, RE_mat4x4 const a, RE_mat4x4 const b) {
	RE_mat4x4 temp;
	int k, r, c;
	for(c=0; c<4; ++c) 
		for(r=0; r<4; ++r) {
			temp[c][r] = 0.f;
			for(k=0; k<4; ++k)
				temp[c][r] += a[k][r] * b[c][k];
		}
	RE_mat4x4_dup(M, temp);
}
void  RE_mat4x4_mul_vec4(RE_vec4 r,   RE_mat4x4 const M, RE_vec4 const v) {
	for(int j = 0; j < 4; j++) {
		r[j] = 0.f;
		for(int i = 0; i < 4; i++)
			r[j] += M[i][j] * v[i];
	}
}
void  RE_mat4x4_translate(RE_mat4x4 T, float x, float y, float z) {
	RE_mat4x4_identity(T);
	T[3][0] = x;
	T[3][1] = y;
	T[3][2] = z;
}
void  RE_mat4x4_translate_in_place(RE_mat4x4 M, float x, float y, float z) {
	RE_vec4 t = {x, y, z, 0};
	RE_vec4 r;
	for (int i = 0; i < 4; i++) {
		RE_mat4x4_row(r, M, i);
		M[3][i] += RE_vec4_mul_inner(r, t);
	}
}
void  RE_mat4x4_from_vec3_mul_outer(RE_mat4x4 M, RE_vec3 const a, RE_vec3 const b) {
	for(int i = 0; i < 4; i++) 
		for(int j = 0; j < 4; j++)
		M[i][j] = i < 3 && j < 3 ? a[i] * b[j] : 0.f;
}
void  RE_mat4x4_rotate(RE_mat4x4 R, RE_mat4x4 const M, float x, float y, float z, float angle) {
	float s = sinf(angle);
	float c = cosf(angle);
	RE_vec3 u = {x, y, z};

	if(RE_vec3_len(u) > 1e-4) {
		RE_vec3_norm(u, u);
		RE_mat4x4 T;
		RE_mat4x4_from_vec3_mul_outer(T, u, u);

		RE_mat4x4 S = {
			{    0,  u[2], -u[1], 0},
			{-u[2],     0,  u[0], 0},
			{ u[1], -u[0],     0, 0},
			{    0,     0,     0, 0}
		};
		RE_mat4x4_scale(S, S, s);

		RE_mat4x4 C;
		RE_mat4x4_identity(C);
		RE_mat4x4_sub(C, C, T);

		RE_mat4x4_scale(C, C, c);

		RE_mat4x4_add(T, T, C);
		RE_mat4x4_add(T, T, S);

		T[3][3] = 1.f;
		RE_mat4x4_mul(R, M, T);
	} else {
		RE_mat4x4_dup(R, M);
	}
}
void  RE_mat4x4_rotate_X(RE_mat4x4 Q, RE_mat4x4 const M, float angle) {
	float s = sinf(angle);
	float c = cosf(angle);
	RE_mat4x4 R = {
		{1.f, 0.f, 0.f, 0.f},
		{0.f,   c,   s, 0.f},
		{0.f,  -s,   c, 0.f},
		{0.f, 0.f, 0.f, 1.f}
	};
	RE_mat4x4_mul(Q, M, R);
}
void  RE_mat4x4_rotate_Y(RE_mat4x4 Q, RE_mat4x4 const M, float angle) {
	float s = sinf(angle);
	float c = cosf(angle);
	RE_mat4x4 R = {
		{   c, 0.f,  -s, 0.f},
		{ 0.f, 1.f, 0.f, 0.f},
		{   s, 0.f,   c, 0.f},
		{ 0.f, 0.f, 0.f, 1.f}
	};
	RE_mat4x4_mul(Q, M, R);
}
void  RE_mat4x4_rotate_Z(RE_mat4x4 Q, RE_mat4x4 const M, float angle) {
	float s = sinf(angle);
	float c = cosf(angle);
	RE_mat4x4 R = {
		{   c,   s, 0.f, 0.f},
		{  -s,   c, 0.f, 0.f},
		{ 0.f, 0.f, 1.f, 0.f},
		{ 0.f, 0.f, 0.f, 1.f}
	};
	RE_mat4x4_mul(Q, M, R);
}
void  RE_mat4x4_invert(RE_mat4x4 T, RE_mat4x4 const M) {
	float s[6];
	float c[6];
	s[0] = M[0][0]*M[1][1] - M[1][0]*M[0][1];
	s[1] = M[0][0]*M[1][2] - M[1][0]*M[0][2];
	s[2] = M[0][0]*M[1][3] - M[1][0]*M[0][3];
	s[3] = M[0][1]*M[1][2] - M[1][1]*M[0][2];
	s[4] = M[0][1]*M[1][3] - M[1][1]*M[0][3];
	s[5] = M[0][2]*M[1][3] - M[1][2]*M[0][3];

	c[0] = M[2][0]*M[3][1] - M[3][0]*M[2][1];
	c[1] = M[2][0]*M[3][2] - M[3][0]*M[2][2];
	c[2] = M[2][0]*M[3][3] - M[3][0]*M[2][3];
	c[3] = M[2][1]*M[3][2] - M[3][1]*M[2][2];
	c[4] = M[2][1]*M[3][3] - M[3][1]*M[2][3];
	c[5] = M[2][2]*M[3][3] - M[3][2]*M[2][3];
	
	/* Assumes it is invertible */
	float idet = 1.0f/( s[0]*c[5]-s[1]*c[4]+s[2]*c[3]+s[3]*c[2]-s[4]*c[1]+s[5]*c[0] );
	
	T[0][0] = ( M[1][1] * c[5] - M[1][2] * c[4] + M[1][3] * c[3]) * idet;
	T[0][1] = (-M[0][1] * c[5] + M[0][2] * c[4] - M[0][3] * c[3]) * idet;
	T[0][2] = ( M[3][1] * s[5] - M[3][2] * s[4] + M[3][3] * s[3]) * idet;
	T[0][3] = (-M[2][1] * s[5] + M[2][2] * s[4] - M[2][3] * s[3]) * idet;

	T[1][0] = (-M[1][0] * c[5] + M[1][2] * c[2] - M[1][3] * c[1]) * idet;
	T[1][1] = ( M[0][0] * c[5] - M[0][2] * c[2] + M[0][3] * c[1]) * idet;
	T[1][2] = (-M[3][0] * s[5] + M[3][2] * s[2] - M[3][3] * s[1]) * idet;
	T[1][3] = ( M[2][0] * s[5] - M[2][2] * s[2] + M[2][3] * s[1]) * idet;

	T[2][0] = ( M[1][0] * c[4] - M[1][1] * c[2] + M[1][3] * c[0]) * idet;
	T[2][1] = (-M[0][0] * c[4] + M[0][1] * c[2] - M[0][3] * c[0]) * idet;
	T[2][2] = ( M[3][0] * s[4] - M[3][1] * s[2] + M[3][3] * s[0]) * idet;
	T[2][3] = (-M[2][0] * s[4] + M[2][1] * s[2] - M[2][3] * s[0]) * idet;

	T[3][0] = (-M[1][0] * c[3] + M[1][1] * c[1] - M[1][2] * c[0]) * idet;
	T[3][1] = ( M[0][0] * c[3] - M[0][1] * c[1] + M[0][2] * c[0]) * idet;
	T[3][2] = (-M[3][0] * s[3] + M[3][1] * s[1] - M[3][2] * s[0]) * idet;
	T[3][3] = ( M[2][0] * s[3] - M[2][1] * s[1] + M[2][2] * s[0]) * idet;
}
void  RE_mat4x4_orthonormalize(RE_mat4x4 R, RE_mat4x4 const M) {
	RE_mat4x4_dup(R, M);
	float s = 1.f;
	RE_vec3 h;

	RE_vec3_norm(R[2], R[2]);
	
	s = RE_vec3_mul_inner(R[1], R[2]);
	RE_vec3_scale(h, R[2], s);
	RE_vec3_sub(R[1], R[1], h);
	RE_vec3_norm(R[1], R[1]);

	s = RE_vec3_mul_inner(R[0], R[2]);
	RE_vec3_scale(h, R[2], s);
	RE_vec3_sub(R[0], R[0], h);

	s = RE_vec3_mul_inner(R[0], R[1]);
	RE_vec3_scale(h, R[1], s);
	RE_vec3_sub(R[0], R[0], h);
	RE_vec3_norm(R[0], R[0]);
}
void  RE_mat4x4_frustum(RE_mat4x4 M, float l, float r, float b, float t, float n, float f) {
	M[0][0] = 2.f*n/(r-l);
	M[0][1] = M[0][2] = M[0][3] = 0.f;
	
	M[1][1] = 2.f*n/(t-b);
	M[1][0] = M[1][2] = M[1][3] = 0.f;

	M[2][0] = (r+l)/(r-l);
	M[2][1] = (t+b)/(t-b);
	M[2][2] = -(f+n)/(f-n);
	M[2][3] = -1.f;
	
	M[3][2] = -2.f*(f*n)/(f-n);
	M[3][0] = M[3][1] = M[3][3] = 0.f;
}
void  RE_mat4x4_ortho(RE_mat4x4 M, float l, float r, float b, float t, float n, float f) {
	M[0][0] = 2.f/(r-l);
	M[0][1] = M[0][2] = M[0][3] = 0.f;

	M[1][1] = 2.f/(t-b);
	M[1][0] = M[1][2] = M[1][3] = 0.f;

	M[2][2] = -2.f/(f-n);
	M[2][0] = M[2][1] = M[2][3] = 0.f;
	
	M[3][0] = -(r+l)/(r-l);
	M[3][1] = -(t+b)/(t-b);
	M[3][2] = -(f+n)/(f-n);
	M[3][3] = 1.f;
}
void  RE_mat4x4_perspective(RE_mat4x4 m, float y_fov, float aspect, float n, float f) {
	/* NOTE: Degrees are an unhandy unit to work with.
	 * RE_linmath.h uses radians for everything! */
	float const a = 1.f / tanf(y_fov / 2.f);

	m[0][0] = a / aspect;
	m[0][1] = 0.f;
	m[0][2] = 0.f;
	m[0][3] = 0.f;

	m[1][0] = 0.f;
	m[1][1] = a;
	m[1][2] = 0.f;
	m[1][3] = 0.f;

	m[2][0] = 0.f;
	m[2][1] = 0.f;
	m[2][2] = -((f + n) / (f - n));
	m[2][3] = -1.f;

	m[3][0] = 0.f;
	m[3][1] = 0.f;
	m[3][2] = -((2.f * f * n) / (f - n));
	m[3][3] = 0.f;
}
void  RE_mat4x4_look_at(RE_mat4x4 m, RE_vec3 const eye, RE_vec3 const center, RE_vec3 const up) {
	/* Adapted from Android's OpenGL Matrix.java.                        */
	/* See the OpenGL GLUT documentation for gluLookAt for a description */
	/* of the algorithm. We implement it in a straightforward way:       */

	/* TODO: The negation of of can be spared by swapping the order of
	 *       operands in the following cross products in the right way. */
	RE_vec3 f;
	RE_vec3_sub(f, center, eye);	
	RE_vec3_norm(f, f);	
	
	RE_vec3 s;
	RE_vec3_mul_cross(s, f, up);
	RE_vec3_norm(s, s);

	RE_vec3 t;
	RE_vec3_mul_cross(t, s, f);

	m[0][0] =  s[0];
	m[0][1] =  t[0];
	m[0][2] = -f[0];
	m[0][3] =   0.f;

	m[1][0] =  s[1];
	m[1][1] =  t[1];
	m[1][2] = -f[1];
	m[1][3] =   0.f;

	m[2][0] =  s[2];
	m[2][1] =  t[2];
	m[2][2] = -f[2];
	m[2][3] =   0.f;

	m[3][0] =  0.f;
	m[3][1] =  0.f;
	m[3][2] =  0.f;
	m[3][3] =  1.f;

	RE_mat4x4_translate_in_place(m, -eye[0], -eye[1], -eye[2]);
}



void  RE_quat_identity(RE_quat q) {
	q[0] = q[1] = q[2] = 0.f;
	q[3] = 1.f;
}
void  RE_quat_mul(RE_quat r, RE_quat const p, RE_quat const q) {
	RE_vec3 w, tmp;

	RE_vec3_mul_cross(tmp, p, q);
	RE_vec3_scale(w, p, q[3]);
	RE_vec3_add(tmp, tmp, w);
	RE_vec3_scale(w, q, p[3]);
	RE_vec3_add(tmp, tmp, w);

	RE_vec3_dup(r, tmp);
	r[3] = p[3]*q[3] - RE_vec3_mul_inner(p, q);
}
void  RE_quat_conj(RE_quat r, RE_quat const q) {
	for(int i = 0; i < 3; i++)
		r[i] = -q[i];
	r[3] = q[3];
}
void  RE_quat_rotate(RE_quat r, float angle, RE_vec3 const axis) {
    RE_vec3 axis_norm;
    RE_vec3_norm(axis_norm, axis);
    float s = sinf(angle / 2);
    float c = cosf(angle / 2);
    RE_vec3_scale(r, axis_norm, s);
    r[3] = c;
}
void  RE_quat_mul_vec3(RE_vec3 r, RE_quat const q, RE_vec3 const v) {
	/*
	 * Method by Fabian 'ryg' Giessen (of Farbrausch)
	t = 2 * cross(q.xyz, v)
	v' = v + q.w * t + cross(q.xyz, t)
	 */

	RE_vec3 t;
	RE_vec3 q_xyz = {q[0], q[1], q[2]};
	RE_vec3 u = {q[0], q[1], q[2]};

	RE_vec3_mul_cross(t, q_xyz, v);
	RE_vec3_scale(t, t, 2);

	RE_vec3_mul_cross(u, q_xyz, t);
	RE_vec3_scale(t, t, q[3]);

	RE_vec3_add(r, v, t);
	RE_vec3_add(r, r, u);
}
void  RE_mat4x4_from_quat(RE_mat4x4 M, RE_quat const q) {
	float a = q[3];
	float b = q[0];
	float c = q[1];
	float d = q[2];
	float a2 = a*a;
	float b2 = b*b;
	float c2 = c*c;
	float d2 = d*d;
	
	M[0][0] = a2 + b2 - c2 - d2;
	M[0][1] = 2.f*(b*c + a*d);
	M[0][2] = 2.f*(b*d - a*c);
	M[0][3] = 0.f;

	M[1][0] = 2*(b*c - a*d);
	M[1][1] = a2 - b2 + c2 - d2;
	M[1][2] = 2.f*(c*d + a*b);
	M[1][3] = 0.f;

	M[2][0] = 2.f*(b*d + a*c);
	M[2][1] = 2.f*(c*d - a*b);
	M[2][2] = a2 - b2 - c2 + d2;
	M[2][3] = 0.f;

	M[3][0] = M[3][1] = M[3][2] = 0.f;
	M[3][3] = 1.f;
}
void  RE_mat4x4o_mul_quat(RE_mat4x4 R, RE_mat4x4 const M, RE_quat const q) {
	/* NOTE: The way this is written only works for orthogonal matrices. */
	/* TODO: Take care of non-orthogonal case. */
	RE_quat_mul_vec3(R[0], q, M[0]);
	RE_quat_mul_vec3(R[1], q, M[1]);
	RE_quat_mul_vec3(R[2], q, M[2]);

	R[3][0] = R[3][1] = R[3][2] = 0.f;
	R[0][3] = M[0][3];
	R[1][3] = M[1][3];
	R[2][3] = M[2][3];
	R[3][3] = M[3][3];  // typically 1.0, but here we make it general
}
void  RE_quat_from_mat4x4(RE_quat q, RE_mat4x4 const M) {
	float r=0.f;

	int perm[] = { 0, 1, 2, 0, 1 };
	int *p = perm;

	for(int i = 0; i < 3; i++) {
		float m = M[i][i];
		if( m < r )
			continue;
		m = r;
		p = &perm[i];
	}

	r = sqrtf(1.f + M[p[0]][p[0]] - M[p[1]][p[1]] - M[p[2]][p[2]] );

	if(r < 1e-6) {
		q[0] = 1.f;
		q[1] = q[2] = q[3] = 0.f;
		return;
	}

	q[0] = r/2.f;
	q[1] = (M[p[0]][p[1]] - M[p[1]][p[0]])/(2.f*r);
	q[2] = (M[p[2]][p[0]] - M[p[0]][p[2]])/(2.f*r);
	q[3] = (M[p[2]][p[1]] - M[p[1]][p[2]])/(2.f*r);
}
void  RE_mat4x4_arcball(RE_mat4x4 R, RE_mat4x4 const M, RE_vec2 const _a, RE_vec2 const _b, float s) {
	RE_vec2 a; memcpy(a, _a, sizeof(a));
	RE_vec2 b; memcpy(b, _b, sizeof(b));
	
	float z_a = 0.;
	float z_b = 0.;

	if(RE_vec2_len(a) < 1.)
		z_a = sqrtf(1. - RE_vec2_mul_inner(a, a));
	else
		RE_vec2_norm(a, a);

	if(RE_vec2_len(b) < 1.) 
		z_b = sqrtf(1. - RE_vec2_mul_inner(b, b));
	else
		RE_vec2_norm(b, b);
	
	RE_vec3 a_ = {a[0], a[1], z_a};
	RE_vec3 b_ = {b[0], b[1], z_b};

	RE_vec3 c_;
	RE_vec3_mul_cross(c_, a_, b_);

	float const angle = acos(RE_vec3_mul_inner(a_, b_)) * s;
	RE_mat4x4_rotate(R, M, c_[0], c_[1], c_[2], angle);
}
