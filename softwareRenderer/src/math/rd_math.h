#pragma once
#include <math.h>

namespace MATH
{
	class vec2
	{
	public:
		vec2(float tx = 0.0f, float ty = 0.0f)
			:x(tx), y(ty) {}
		vec2(float val)
			:x(val), y(val) {}
		vec2(const vec2&) = default;

		float manitude()
		{
			return sqrt(x * x + y * y);
		}
		vec2 normalize()
		{
			float tmp = this->manitude();
			return vec2(x / tmp, y / tmp);
		}

		vec2 operator+(const vec2& other)
		{
			return vec2(this->x + other.x, this->y + other.y);
		}
		vec2 operator-(const vec2& other)
		{
			return vec2(this->x - other.x, this->y - other.y);
		}
		vec2 operator*(const float k)
		{
			return vec2(k * this->x, k * this->y);
		}
		vec2 operator/(const float k)
		{
			if (k == 0.0f)
				return vec2(0.0f, 0.0f);
			return vec2(this->x / k, this->y / k);
		}
		void operator+=(const vec2& other)
		{
			this->x += other.x;
			this->y += other.y;
		}
		void operator-=(const vec2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
		}
		void operator*=(const float k)
		{
			this->x *= k;
			this->y *= k;
		}
		void operator/=(const float k)
		{
			if (k == 0.0f)
			{
				this->x = 0.0f;
				this->y = 0.0f;
			}
			else
			{
				this->x /= k;
				this->y /= k;
			}
		}
		vec2 operator+()
		{
			return *this;
		}
		vec2 operator-()
		{
			return vec2(-this->x, -this->y);
		}
	public:
		float x, y;
	};

	class vec3
	{
	public:
		vec3(float tx = 0.0f, float ty = 0.0f, float tz = 0.0f)
			:x(tx), y(ty), z(tz) {}
		vec3(float val)
			:x(val), y(val), z(val) {}
		vec3(const vec3&) = default;
		float dot(const vec3& other)
		{
			return this->x * other.x + this->y * other.y + this->z * other.z;
		}
		vec3 product(const vec3& other)
		{
			float tx = this->y * other.z - this->z * other.y;
			float ty = this->z * other.x - this->x * other.z;
			float tz = this->x * other.y - this->y * other.x;
			return vec3(tx, ty, tz);
		}

		float manitude()
		{
			return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
		}
		vec3 normalize()
		{
			float temp = this->manitude();
			return vec3(this->x / temp, this->y / temp, this->z / temp);
		}

		vec3 operator+(const vec3& other)
		{
			return vec3(this->x + other.x, this->y + other.y, this->z + other.z);
		}
		vec3 operator-(const vec3& other)
		{
			return vec3(this->x - other.x, this->y - other.y, this->z - other.z);
		}
		vec3 operator*(const float k)
		{
			return vec3(k * this->x, k * this->y, k * this->z);
		}
		vec3 operator/(const float k)
		{
			if (k == 0.0f)
				return vec3(0.0f, 0.0f, 0.0f);
			return vec3(this->x / k, this->y / k, this->z / k);
		}
		void operator+=(const vec3& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}
		void operator-=(const vec3& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}
		void operator*=(const float k)
		{
			this->x *= k;
			this->y *= k;
			this->z *= k;
		}
		void operator/=(const float k)
		{
			if (k == 0.0f)
			{
				this->x = 0.0f;
				this->y = 0.0f;
				this->z = 0.0f;
			}
			else
			{
				this->x /= k;
				this->y /= k;
				this->z /= k;
			}
		}
		vec3 operator+()
		{
			return *this;
		}
		vec3 operator-()
		{
			return vec3(-this->x, -this->y, -this->z);
		}

	public:
		float x, y, z;
	};

	class vec4
	{
	public:
		vec4(float tx = 0.0f, float ty = 0.0f, float tz = 0.0f, float tw = 0.0f)
			:x(tx), y(ty), z(tz), w(tw){}
		vec4(float val)
			:x(val), y(val), z(val), w(val){}
		vec4(const vec4&) = default;

		float dot(const vec4& other)
		{
			return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
		}
		float manitude()
		{
			return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
		}
		vec4 normalize()
		{
			float temp = this->manitude();
			return vec4(this->x / temp, this->y / temp, this->z / temp, this->w / temp);
		}

		vec4 operator+(const vec4& other)
		{
			return vec4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
		}
		vec4 operator-(const vec4& other)
		{
			return vec4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
		}
		vec4 operator*(const float k)
		{
			return vec4(k * this->x, k * this->y, k * this->z, k * this->w);
		}
		vec4 operator/(const float k)
		{
			if (k == 0.0f)
				return vec4(0.0f, 0.0f, 0.0f);
			return vec4(this->x / k, this->y / k, this->z / k, this->w / k);
		}
		void operator+=(const vec4& other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
		}
		void operator-=(const vec4& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
		}
		void operator*=(const float k)
		{
			this->x *= k;
			this->y *= k;
			this->z *= k;
			this->w *= k;
		}
		void operator/=(const float k)
		{
			if (k == 0.0f)
			{
				this->x = 0.0f;
				this->y = 0.0f;
				this->z = 0.0f;
				this->w = 0.0f;
			}
			else
			{
				this->x /= k;
				this->y /= k;
				this->z /= k;
				this->w /= k;
			}
		}
		vec4 operator+()
		{
			return *this;
		}
		vec4 operator-()
		{
			return vec4(-this->x, -this->y, -this->z, -this->w);
		}

	public:
		float x, y, z, w;
	};

	class mat4
	{

	};
}