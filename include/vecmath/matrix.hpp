#ifndef VECMATH_MATRIX_H
#define VECMATH_MATRIX_H

#include "vector.hpp"

namespace vcm 
{
	//2x2 matrix
	struct mat2 
	{
		//creates an identity matrix
		mat2();

		//creates a matrix with every component set to the value of 'all'
		explicit mat2(float all);

		//creates a matrix with column vectors 'a', and 'b'
		mat2(const vec2& a, const vec2& b);

		//creates a matrix from an existing matrix
		mat2(const mat2& other);

		//creates a matrix from an existing matrix
		explicit mat2(const mat3& other);

		//creates a matrix from an existing matrix
		explicit mat2(const mat4& other);

		vec2& operator[](unsigned i) { return m[i]; }
		vec2 operator[](unsigned i) const { return m[i]; }

		//returns the row vector at index 'i'
		vec2 row(unsigned i) const 
		{
			return vec2(m[0][i], m[1][i]);
		}

		bool operator==(const mat2& other) const { return m[0] == other.m[0] && m[1] == other.m[1]; }
		bool operator!=(const mat2& other) const { return m[0] != other.m[0] || m[1] != other.m[1]; }

		mat2 operator+(const mat2& other) const { return mat2(m[0] + other.m[0], m[1] + other.m[1]); }
		mat2 operator-(const mat2& other) const { return mat2(m[0] - other.m[0], m[1] - other.m[1]); }
		mat2 operator*(const float scalar) const { return mat2(m[0] * scalar, m[1] * scalar); }

		mat2 operator*(const mat2& other) const;
		vec2 operator*(const vec2& other) const;

		mat2& operator=(const mat2& other) 
		{
			m[0] = other.m[0];
			m[1] = other.m[1];

			return *this;
		}

		mat2& operator+=(const mat2& other) 
		{
			return (*this = (*this + other));
		}

		mat2& operator-=(const mat2& other) 
		{
			return (*this = (*this - other));
		}

		mat2& operator*=(const float scalar) 
		{
			return (*this = (*this * scalar));
		}

		mat2& operator*=(const mat2& other) 
		{
			return (*this = (*this * other));
		}

		mat2 operator-() const 
		{
			return mat2(-m[0], -m[1]);
		}

		vec2 m[2]; //columns
	};

	//returns 'm' transposed
	mat2 transpose(const mat2& m);

	//returns the determinant of 'm'
	float determinant(const mat2& m);

	//returns the inverse of 'm'
	mat2 inverse(const mat2& m);

	//returns a 2d rotation matrix from 'angle' (in radians)
	mat2 from_angle(float angle);
	
	//3x3 matrix
	struct mat3 
	{
		//creates an identity matrix
		mat3();

		//creates a matrix with every component set to the value of 'all'
		explicit mat3(float all);

		//creates a matrix with column vectors 'a', 'b', and 'c'
		mat3(const vec3& a, const vec3& b, const vec3& c);

		//creates a matrix from an existing matrix
		mat3(const mat3& other);

		//creates a matrix from an existing matrix
		explicit mat3(const mat2& other);

		//creates a matrix from an existing matrix
		explicit mat3(const mat4& other);

		//creates a rotation matrix from an existing quaternion
		explicit mat3(const quat& other);

		vec3& operator[](unsigned i) { return m[i]; }
		vec3 operator[](unsigned i) const { return m[i]; }

		//returns the row vector at index 'i'
		vec3 row(unsigned i) const 
		{
			return vec3(m[0][i], m[1][i], m[2][i]);
		}

		bool operator==(const mat3& other) const { return m[0] == other.m[0] && m[1] == other.m[1] && m[2] == other.m[2]; }
		bool operator!=(const mat3& other) const { return m[0] != other.m[0] || m[1] != other.m[1] || m[2] != other.m[2]; }

		mat3 operator+(const mat3& other) const { return mat3(m[0] + other.m[0], m[1] + other.m[1], m[2] + other.m[2]); }
		mat3 operator-(const mat3& other) const { return mat3(m[0] - other.m[0], m[1] - other.m[1], m[2] - other.m[2]); }
		mat3 operator*(const float scalar) const { return mat3(m[0] * scalar, m[1] * scalar, m[2] * scalar); }

		mat3 operator*(const mat3& other) const;
		vec3 operator*(const vec3& other) const;

		mat3& operator=(const mat3& other) 
		{
			m[0] = other.m[0];
			m[1] = other.m[1];
			m[2] = other.m[2];

			return *this;
		}

		mat3& operator+=(const mat3& other) 
		{
			return (*this = (*this + other));
		}

		mat3& operator-=(const mat3& other) 
		{
			return (*this = (*this - other));
		}

		mat3& operator*=(const float scalar) 
		{
			return (*this = (*this * scalar));
		}

		mat3& operator*=(const mat3& other) 
		{
			return (*this = (*this * other));
		}

		mat3 operator-() const 
		{
			return mat3(-m[0], -m[1], -m[2]);
		}

		vec3 m[3]; //columns
	};

	//returns 'm' transposed
	mat3 transpose(const mat3& m);

	//returns the determinant of 'm'
	float determinant(const mat3& m);

	//returns the inverse of 'm'
	mat3 inverse(const mat3& m);

	//creates a rotation matrix from a forward vector, 'fwd' and an up vector, 'up'
	mat3 look_rotation(const vec3& fwd, const vec3& up = vec3::up);
	
	//4x4 matrix
	struct mat4 
	{
		//creates an identity matrix
		mat4();

		//creates a matrix with every component set to the value of 'all'
		explicit mat4(float all);

		//creates a matrix from column vectors 'a', 'b', 'c', and 'd'
		mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d);

		//creates a matrix from an existing matrix
		mat4(const mat4& other);

		//creates a matrix from an existing matrix
		explicit mat4(const mat2& other);

		//creates a matrix from an existing matrix
		explicit mat4(const mat3& other);

		vec4& operator[](unsigned i) { return m[i]; }
		vec4 operator[](unsigned i) const { return m[i]; }

		//returns the row vector at index 'i'
		vec4 row(unsigned i) const 
		{
			return vec4(m[0][i], m[1][i], m[2][i], m[3][i]);
		}

		bool operator==(const mat4& other) const { return m[0] == other.m[0] && m[1] == other.m[1] && m[2] == other.m[2] && m[3] == other.m[3]; }
		bool operator!=(const mat4& other) const { return m[0] != other.m[0] || m[1] != other.m[1] || m[2] != other.m[2] || m[3] != other.m[3]; }

		mat4 operator+(const mat4& other) const { return mat4(m[0] + other.m[0], m[1] + other.m[1], m[2] + other.m[2], m[3] + other.m[3]); }
		mat4 operator-(const mat4& other) const { return mat4(m[0] - other.m[0], m[1] - other.m[1], m[2] - other.m[2], m[3] - other.m[3]); }
		mat4 operator*(const float scalar) const { return mat4(m[0] * scalar, m[1] * scalar, m[2] * scalar, m[3] * scalar); }

		mat4 operator*(const mat4& other) const;
		vec4 operator*(const vec4& other) const;

		mat4& operator=(const mat4& other) 
		{
			m[0] = other.m[0];
			m[1] = other.m[1];
			m[2] = other.m[2];
			m[3] = other.m[3];

			return *this;
		}

		mat4& operator+=(const mat4& other) 
		{
			return (*this = (*this + other));
		}

		mat4& operator-=(const mat4& other) 
		{
			return (*this = (*this - other));
		}

		mat4& operator*=(const float scalar) 
		{
			return (*this = (*this * scalar));
		}

		mat4& operator*=(const mat4& other) 
		{
			return (*this = (*this * other));
		}

		mat4 operator-() const 
		{
			return mat4(-m[0], -m[1], -m[2], -m[3]);
		}

		vec4 m[4]; //columns
	};

	//returns 'm' transposed
	mat4 transpose(const mat4& m);

	//returns the determinant of 'm'
	float determinant(const mat4& m);

	//returns the inverse of 'm'
	mat4 inverse(const mat4& m);

	//returns a transform matrix (translation * rotation) from a starting position
	//'start', looking at an ending position, 'end', with an up vector of 'up'
	mat4 look_at(const vec3& start, const vec3& end, const vec3& up = vec3::up);

	//creates a transform matrix (translation * rotation) from 'tran' and 'rot'
	mat4 compose(const vec3& tran, const quat& rot);

	//creates a transform matrix (translation * rotation * scale) from 'tran', 'rot', and 'scale'
	mat4 compose(const vec3& tran, const quat& rot, const vec3& scale);

	//creates a perspective projection matrix
	//with a field of view of the value 'fov' (in radians)
	//with an aspect ratio of 'aspect'
	//with a near clipping value of 'znear'
	//and a far clipping value of 'zfar'
	mat4 perspective(float fov, float aspect, float znear, float zfar);

	//creates an orthographic projection matrix
	//with the x axis ranging from left to right
	//with the y axis ranging from bottom to top
	//and the z axis ranging from znear to zfar
	mat4 orthographic(float left, float right, float bottom, float top, float znear, float zfar);

    //INLINE CONSTRUCTORS

    //MAT2

    inline mat2::mat2()
    {
        m[0] = { 1, 0 };
        m[1] = { 0, 1 };
    }

    inline mat2::mat2(float all)
    {
        m[0] = vcm::vec2{ all };
        m[1] = vcm::vec2{ all };
    }

    inline mat2::mat2(const vec2& a, const vec2& b)
    {
        m[0] = a;
        m[1] = b;
    }

    inline mat2::mat2(const mat2& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
    }

    inline mat2::mat2(const mat3& other)
    {
        m[0] = (vcm::vec2)other.m[0];
        m[1] = (vcm::vec2)other.m[1];
    }

    inline mat2::mat2(const mat4& other)
    {
        m[0] = (vcm::vec2)other.m[0];
        m[1] = (vcm::vec2)other.m[1];
    }

    //MAT3

    inline mat3::mat3()
    {
        m[0] = { 1, 0, 0 };
        m[1] = { 0, 1, 0 };
        m[2] = { 0, 0, 1 };
    }

    inline mat3::mat3(float all)
    {
        m[0] = vcm::vec3{ all };
        m[1] = vcm::vec3{ all };
        m[2] = vcm::vec3{ all };
    }

    inline mat3::mat3(const vec3& a, const vec3& b, const vec3& c)
    {
        m[0] = a;
        m[1] = b;
        m[2] = c;
    }

    inline mat3::mat3(const mat3& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
    }

    inline mat3::mat3(const mat2& other)
    {
        m[0] = (vcm::vec3)other.m[0];
        m[1] = (vcm::vec3)other.m[1];
        m[2] = { 0, 0, 1 };
    }

    inline mat3::mat3(const mat4& other)
    {
        m[0] = (vcm::vec3)other.m[0];
        m[1] = (vcm::vec3)other.m[1];
        m[2] = (vcm::vec3)other.m[2];
    }

    //MAT4

    inline mat4::mat4()
    {
        m[0] = { 1, 0, 0, 0 };
        m[1] = { 0, 1, 0, 0 };
        m[2] = { 0, 0, 1, 0 };
        m[3] = { 0, 0, 0, 1 };
    }

    inline mat4::mat4(float all)
    {
        m[0] = vcm::vec4{ all };
        m[1] = vcm::vec4{ all };
        m[2] = vcm::vec4{ all };
        m[3] = vcm::vec4{ all };
    }

    inline mat4::mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d)
    {
        m[0] = a;
        m[1] = b;
        m[2] = c;
        m[3] = d;
    }

    inline mat4::mat4(const mat4& other)
    {
        m[0] = other.m[0];
        m[1] = other.m[1];
        m[2] = other.m[2];
        m[3] = other.m[3];
    }

    inline mat4::mat4(const mat2& other)
    {
        m[0] = (vcm::vec4)other.m[0];
        m[1] = (vcm::vec4)other.m[1];
        m[2] = { 0, 0, 1, 0 };
        m[3] = { 0, 0, 0, 1 };
    }

    inline mat4::mat4(const mat3& other)
    {
        m[0] = (vcm::vec4)other.m[0];
        m[1] = (vcm::vec4)other.m[1];
        m[2] = (vcm::vec4)other.m[2];
        m[3] = { 0, 0, 0, 1 };
    }
}

#endif
