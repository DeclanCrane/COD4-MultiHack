#include "Vec.h"

vec3_t::vec3_t(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3_t::vec3_t() 
{
	this->x = 0.f;
	this->y = 0.f;
	this->z = 0.f;
}

float vec3_t::GetDistance(const vec3_t& x)
{
	return sqrtf((powf(this->x - x.x, 2) + powf(this->y - x.y, 2) + powf(this->z - x.z, 2)));
}

vec3_t vec3_t::operator+(const vec3_t& x)
{
	return vec3_t(this->x + x.x, this->y + x.y, this->z + x.z);
}

vec3_t vec3_t::operator-(const vec3_t& x)
{
	return vec3_t(this->x - x.x, this->y - x.y, this->z - x.z);
}




/* Vec 2 */
vec2_t::vec2_t(float x, float y)
{
	this->x = x;
	this->y = y;
}

vec2_t::vec2_t()
{
	this->x = 0.f;
	this->y = 0.f;
}

vec2_t vec2_t::operator+(const vec2_t& x)
{
	return vec2_t(this->x + x.x, this->y + x.y);
}

vec2_t vec2_t::operator-(const vec2_t& x)
{
	return vec2_t(this->x - x.x, this->y - x.y);
}
