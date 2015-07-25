#ifndef VECMATH_VECTOR_H
#define VECMATH_VECTOR_H

#include "fwd.hpp"

namespace vcm
{	
	//2 component vector
	struct vec2 
	{
		//creates a vector with all components equal to zero
		vec2();

		//creates a vector with all components equal to 'all'
		vec2(float all);

		vec2(float x, float y);

		//creates a vector from an existing vector
		vec2(const vec2& v);

		//creates a vector with all components set to the corresponding components of 'v'
		vec2(const vec3& v);

		//creates a vector with all components set to the corresponding components of 'v'
		vec2(const vec4& v);

		float& operator[](unsigned i) { return m[i]; }
		float operator[](unsigned i) const { return m[i]; }

		bool operator==(const vec2& other) const { return x == other.x && y == other.y; }
		bool operator!=(const vec2& other) const { return x != other.x || y != other.y; }

		vec2 operator+(const vec2& other) const { return vec2(x + other.x, y + other.y); }
		vec2 operator-(const vec2& other) const { return vec2(x - other.x, y - other.y); }
		vec2 operator*(const vec2& other) const { return vec2(x * other.x, y * other.y); }
		vec2 operator/(const vec2& other) const { return vec2(x / other.x, y / other.y); }

		vec2 operator*(float scalar) const { return vec2(x * scalar, y * scalar); }
		vec2 operator/(float scalar) const { return vec2(x / scalar, y / scalar); }

		vec2& operator=(const vec2& other) 
		{
			x = other.x;
			y = other.y;

			return *this;
		}

		vec2& operator+=(const vec2& other) 
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		vec2& operator-=(const vec2& other) 
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		vec2& operator*=(const vec2& other) 
		{
			x *= other.x;
			y *= other.y;

			return *this;
		}

		vec2& operator/=(const vec2& other) 
		{
			x /= other.x;
			y /= other.y;

			return *this;
		}

		vec2& operator*=(float scalar) 
		{
			x *= scalar;
			y *= scalar;

			return *this;
		}

		vec2& operator/=(float scalar) 
		{
			x /= scalar;
			y /= scalar;

			return *this;
		}

		vec2 operator-() const 
		{
			return vec2(-x, -y);
		}

		union 
		{
			struct { float x, y; };
			float m[2];
		};
		
		static const vec2 up;
		static const vec2 down;
		static const vec2 right;
		static const vec2 left;
	};

	//returns the length of vector, 'v'
	float length(const vec2& v);

	//returns the squared length of vector, 'v' (faster than length(v))
	float length_squared(const vec2& v);

	//returns the dot product of 'a' and 'b'
	float dot(const vec2& a, const vec2& b);

	//returns 'v', normalized
	vec2 normalize(const vec2& v);

	//returns 'v' with its length clamped to a maximum value of 'maxLen'
	vec2 clamp_length(const vec2& v, float maxLen);

	//returns a vector with the largest components of 'a' and 'b'
	vec2 max(const vec2& a, const vec2& b);

	//returns a vector with the smallest components of 'a' and 'b'
	vec2 min(const vec2& a, const vec2& b);

	//returns the result 'a' and 'b' interpolated by a factor of 't'
	vec2 lerp(const vec2& a, const vec2& b, float t);
	
	//3 component vector
	struct vec3 
	{
		//creates a vector with all components equal to zero
		vec3();

		//creates a vector with all components equal to 'all'
		vec3(float all);

		vec3(float x, float y, float z);

		//creates a vector from an existing vector
		vec3(const vec3& v);

		vec3(const vec2& xy, float z);
		vec3(float x, const vec2& yz);

		//creates a vector with the components equal to the corresponding components of 'v'
		vec3(const vec2& v);

		//creates a vector with the components equal to the corresponding components of 'v'
		vec3(const vec4& v);

		float& operator[](unsigned i) { return m[i]; }
		float operator[](unsigned i) const { return m[i]; }

		bool operator==(const vec3& other) const { return x == other.x && y == other.y && z == other.z; }
		bool operator!=(const vec3& other) const { return x != other.x || y != other.y || z != other.z; }

		vec3 operator+(const vec3& other) const { return vec3(x + other.x, y + other.y, z + other.z); }
		vec3 operator-(const vec3& other) const { return vec3(x - other.x, y - other.y, z - other.z); }
		vec3 operator*(const vec3& other) const { return vec3(x * other.x, y * other.y, z * other.z); }
		vec3 operator/(const vec3& other) const { return vec3(x / other.x, y / other.y, z / other.z); }

		vec3 operator*(float scalar) const { return vec3(x * scalar, y * scalar, z * scalar); }
		vec3 operator/(float scalar) const { return vec3(x / scalar, y / scalar, z / scalar); }

		vec3& operator=(const vec3& other) 
		{
			x = other.x;
			y = other.y;
			z = other.z;

			return *this;
		}

		vec3& operator+=(const vec3& other) 
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		vec3& operator-=(const vec3& other) 
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		vec3& operator*=(const vec3& other) 
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

		vec3& operator/=(const vec3& other) 
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;

			return *this;
		}

		vec3& operator*=(float scalar) 
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;

			return *this;
		}

		vec3& operator/=(float scalar) 
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;

			return *this;
		}

		vec3 operator-() const 
		{
			return vec3(-x, -y, -z);
		}

		union 
		{
			struct { float x, y, z; };
			float m[3];
		};
		
		static const vec3 up;
		static const vec3 down;
		static const vec3 right;
		static const vec3 left;
		static const vec3 forward;
		static const vec3 back;
	};

	//returns the length of vector, 'v'
	float length(const vec3& v);

	//returns the squared length of vector, 'v' (faster than length(v))
	float length_squared(const vec3& v);

	//returns the dot product of 'a' and 'b'
	float dot(const vec3& a, const vec3& b);

	//returns 'v', normalized
	vec3 normalize(const vec3& v);

	//returns 'v' with its length clamped to a maximum value of 'maxLen'
	vec3 clamp_length(const vec3& v, float maxLen);

	//returns a vector with the largest components of 'a' and 'b'
	vec3 max(const vec3& a, const vec3& b);

	//returns a vector with the smallest components of 'a' and 'b'
	vec3 min(const vec3& a, const vec3& b);

	//returns the result 'a' and 'b' interpolated by a factor of 't'
	vec3 lerp(const vec3& a, const vec3& b, float t);

	//returns the cross product of 'a' and 'b'
	vec3 cross(const vec3& a, const vec3& b);
	
	//4 component vector
	struct vec4 
	{
		//creates a vector with all components equal to zero
		vec4();

		//creates a vector with all components equal to 'all'
		vec4(float all);

		vec4(float x, float y, float z, float w);

		//creates a vector from an existing vector
		vec4(const vec4& v);

		vec4(const vec3& xyz, float w);
		vec4(float x, const vec3& yzw);
		vec4(const vec2& xy, const vec2& zw);
		vec4(const vec2& xy, float z, float w);
		vec4(float x, const vec2& yz, float w);
		vec4(float x, float y, const vec2& zw);

		//creates a vector with all components set to the corresponding components of 'v'
		vec4(const vec2& v);

		//creates a vector with all components set to the corresponding components of 'v'
		vec4(const vec3& v);

		//creates a vector with all components set to the corresponding components of 'q'
		vec4(const quat& q);

		float& operator[](unsigned i) { return m[i]; }
		float operator[](unsigned i) const { return m[i]; }

		bool operator==(const vec4& other) const { return x == other.x && y == other.y && z == other.z && w == other.w; }
		bool operator!=(const vec4& other) const { return x != other.x || y != other.y || z != other.z || w != other.w; }

		vec4 operator+(const vec4& other) const { return vec4(x + other.x, y + other.y, z + other.z, w + other.w); }
		vec4 operator-(const vec4& other) const { return vec4(x - other.x, y - other.y, z - other.z, w - other.w); }
		vec4 operator*(const vec4& other) const { return vec4(x * other.x, y * other.y, z * other.z, w * other.w); }
		vec4 operator/(const vec4& other) const { return vec4(x / other.x, y / other.y, z / other.z, w / other.w); }

		vec4 operator*(float scalar) const { return vec4(x * scalar, y * scalar, z * scalar, w * scalar); }
		vec4 operator/(float scalar) const { return vec4(x / scalar, y / scalar, z / scalar, w / scalar); }

		vec4& operator=(const vec4& other) 
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;

			return *this;
		}

		vec4& operator+=(const vec4& other) 
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		vec4& operator-=(const vec4& other) 
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		vec4& operator*=(const vec4& other) 
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;

			return *this;
		}

		vec4& operator/=(const vec4& other) 
		{
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;

			return *this;
		}

		vec4& operator*=(float scalar) 
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;

			return *this;
		}

		vec4& operator/=(float scalar) 
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;

			return *this;
		}

		vec4 operator-() const 
		{
			return vec4(-x, -y, -z, -w);
		}

		union 
		{
			struct { float x, y, z, w; };
			float m[4];
		};

		static const vec4 up;
		static const vec4 down;
		static const vec4 right;
		static const vec4 left;
		static const vec4 forward;
		static const vec4 back;
	};

	//returns the length of vector, 'v'
	float length(const vec4& v);

	//returns the squared length of vector, 'v' (faster than length(v))
	float length_squared(const vec4& v);

	//returns the dot product of 'a' and 'b'
	float dot(const vec4& a, const vec4& b);

	//returns 'v', normalized
	vec4 normalize(const vec4& v);

	//returns 'v' with its length clamped to a maximum value of 'maxLen'
	vec4 clamp_length(const vec4& v, float maxLen);

	//returns a vector with the largest components of 'a' and 'b'
	vec4 max(const vec4& a, const vec4& b);

	//returns a vector with the smallest components of 'a' and 'b'
	vec4 min(const vec4& a, const vec4& b);

	//returns the result 'a' and 'b' interpolated by a factor of 't'
	vec4 lerp(const vec4& a, const vec4& b, float t);
	
	//4 element rotation vector
	struct quat 
	{
		//creates an identity quaternion
		quat();

		//creates a quaternion with every component set to 'all'
		quat(float all);

		quat(float x, float y, float z, float w);

		//creates a quaternion from an existing quaternion, 'q'
		quat(const quat& q);

		quat(const vec3& xyz, float w);
		quat(float x, const vec3& yzw);
		quat(const vec2& xy, const vec2& zw);
		quat(const vec2& xy, float z, float w);
		quat(float x, const vec2& yz, float w);
		quat(float x, float y, const vec2& zw);

		//creates a quaternion with the first two components equal to the components of v
		quat(const vec2& v);

		//creates a quaternion with the first two components equal to the components of v
		quat(const vec3& v);

		//creates a quaternion with the components equal to the components of v
		quat(const vec4& v);

		//creates a quaternion from an existing rotation matrix
		quat(const mat3& mat);

		float& operator[](unsigned i) { return m[i]; }
		float operator[](unsigned i) const { return m[i]; }

		bool operator==(const quat& other) const { return x == other.x && y == other.y && z == other.z && w == other.w; }
		bool operator!=(const quat& other) const { return x != other.x || y != other.y || z != other.z || w != other.w; }

		quat operator+(const quat& other) const { return quat(x + other.x, y + other.y, z + other.z, w + other.w); }
		quat operator-(const quat& other) const { return quat(x - other.x, y - other.y, z - other.z, w - other.w); }
		quat operator*(float scalar) const { return quat(x * scalar, y * scalar, z * scalar, w * scalar); }
		quat operator/(float scalar) const { return quat(x / scalar, y / scalar, z / scalar, w / scalar); }

		quat operator*(const quat& other) const 
		{
			quat result = {
				w * other.x + x * other.w + y * other.z - z * other.y,
				w * other.y - x * other.z + y * other.w + z * other.x,
				w * other.z + x * other.y - y * other.x + z * other.w,
				w * other.w - x * other.x - y * other.y - z * other.z
			};

			return result;
		}

		quat& operator=(const quat& other) 
		{
			x = other.x;
			y = other.y;
			z = other.z;
			w = other.w;

			return *this;
		}

		quat& operator+=(const quat& other) 
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		quat& operator-=(const quat& other) 
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

		quat& operator*=(const quat& other) 
		{
			return (*this = (*this * other));
		}

		quat& operator*=(float scalar) 
		{
			x *= scalar;
			y *= scalar;
			z *= scalar;
			w *= scalar;

			return *this;
		}

		quat& operator/=(float scalar) 
		{
			x /= scalar;
			y /= scalar;
			z /= scalar;
			w /= scalar;

			return *this;
		}

		quat operator-() const 
		{
			return quat(-x, -y, -z, -w);
		}

		union 
		{
			struct { float x, y, z, w; };
			float m[4];
		};
	};

	//returns the length of quaternion, 'q'
	float length(const quat& q);

	//returns the squared length of quaternion, 'q' (faster than length)
	float length_squared(const quat& q);

	//returns the dot product of two quaternions, 'a', and 'b'
	float dot(const quat& a, const quat& b);

	//returns 'q', normalized
	quat normalize(const quat& q);

	//returns the inverse of 'q'
	quat inverse(const quat& q);

	//returns the result of 'a' and 'b' interpolated by a factor of 't'
	quat lerp(const quat& a, const quat& b, float t);

	//returns the result of 'a' and 'b' spherically interpolated by a factor of 't'
	quat slerp(const quat& a, const quat& b, float t);

	//returns a quaternion from an 'angle' (in radians) about an 'axis'
	quat angle_axis(float angle, const vec3& axis);

	//returns a quaternion from euler angles
	quat euler(const vec3& euler);
}

#endif
