#pragma once
#include <math.h>

class vec3_t {
public:
	float x, y, z;
	vec3_t(float x, float y, float z);
	vec3_t();
public:
	inline float DotProduct(const vec3_t& x) { return this->x * x.x + this->y * x.y + this->z * x.z; }
	float GetDistance(const vec3_t& x);
public:
	vec3_t operator+(const vec3_t& x);
	vec3_t operator-(const vec3_t& x);
};

class vec2_t {
public:
	float x, y;
	vec2_t(float x, float y);
	vec2_t();
public:
	vec2_t operator+(const vec2_t& x);
	vec2_t operator-(const vec2_t& x);
};