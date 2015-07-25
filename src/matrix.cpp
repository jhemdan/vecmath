#include <vecmath/matrix.hpp>

#include <cmath>

namespace vcm
{
	mat2::mat2() 
	{
		m[0] = { 1, 0 };
		m[1] = { 0, 1 };
	}

	mat2::mat2(float all) 
	{
		m[0] = { all };
		m[1] = { all };
	}

	mat2::mat2(const vec2& a, const vec2& b) 
	{
		m[0] = a;
		m[1] = b;
	}

	mat2::mat2(const mat2& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
	}

	mat2::mat2(const mat3& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
	}

	mat2::mat2(const mat4& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
	}

	mat2 mat2::operator*(const mat2& other) const 
	{
		mat2 result;

		auto row0 = row(0);
		auto row1 = row(1);

		result.m[0][0] = dot(row0, other.m[0]);
		result.m[0][1] = dot(row1, other.m[0]);

		result.m[1][0] = dot(row0, other.m[1]);
		result.m[1][1] = dot(row1, other.m[1]);

		return result;
	}

	vec2 mat2::operator*(const vec2& other) const 
	{
		vec2 result;

		result.x = dot(row(0), other);
		result.y = dot(row(1), other);

		return result;
	}

	mat2 transpose(const mat2& m) 
	{
		return mat2(m.row(0), m.row(1));
	}

	float determinant(const mat2& m) 
	{
		return m[0][0] * m[1][1] - m[1][0] * m[0][1];
	}

	mat2 inverse(const mat2& m) 
	{
		auto dt = determinant(m);
		if (dt == 0)
			return m;

		mat2 result;

		result.m[0][0] = m.m[1][1];
		result.m[0][1] = -m.m[0][1];
		result.m[1][0] = -m.m[1][0];
		result.m[1][1] = m.m[0][0];

		return result * (1.0f / dt);
	}

	mat2 from_angle(float angle) 
	{
		mat2 result = 
		{
			{ std::cos(angle), std::sin(angle) },
			{ -std::sin(angle), std::cos(angle) }
		};

		return result;
	}
	
	mat3::mat3() 
	{
		m[0] = { 1, 0, 0 };
		m[1] = { 0, 1, 0 };
		m[2] = { 0, 0, 1 };
	}

	mat3::mat3(float all) 
	{
		m[0] = { all };
		m[1] = { all };
		m[2] = { all };
	}

	mat3::mat3(const vec3& a, const vec3& b, const vec3& c) 
	{
		m[0] = a;
		m[1] = b;
		m[2] = c;
	}

	mat3::mat3(const mat3& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
		m[2] = other.m[2];
	}

	mat3::mat3(const mat2& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
		m[2] = { 0, 0, 1 };
	}

	mat3::mat3(const mat4& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
		m[2] = other.m[2];
	}

	mat3::mat3(const quat& other) 
	{
		quat q = normalize(other);

		m[0] = 
		{
			1 - 2 * q.y * q.y - 2 * q.z * q.z,
			2 * q.x * q.y + 2 * q.z * q.w,
			2 * q.x * q.z - 2 * q.y * q.w
		};

		m[1] = 
		{
			2 * q.x * q.y - 2 * q.z * q.w,
			1 - 2 * q.x * q.x - 2 * q.z * q.z,
			2 * q.y * q.z + 2 * q.x * q.w
		};

		m[2] = 
		{
			2 * q.x * q.z + 2 * q.y * q.w,
			2 * q.y * q.z - 2 * q.x * q.w,
			1 - 2 * q.x * q.x - 2 * q.y * q.y
		};
	}

	mat3 mat3::operator*(const mat3& other) const 
	{
		mat3 result;

		auto row0 = row(0);
		auto row1 = row(1);
		auto row2 = row(2);

		result.m[0][0] = dot(row0, other.m[0]);
		result.m[0][1] = dot(row1, other.m[0]);
		result.m[0][2] = dot(row2, other.m[0]);

		result.m[1][0] = dot(row0, other.m[1]);
		result.m[1][1] = dot(row1, other.m[1]);
		result.m[1][2] = dot(row2, other.m[1]);

		result.m[2][0] = dot(row0, other.m[2]);
		result.m[2][1] = dot(row1, other.m[2]);
		result.m[2][2] = dot(row2, other.m[2]);

		return result;
	}

	vec3 mat3::operator*(const vec3& other) const 
	{
		vec3 result;

		result.x = dot(row(0), other);
		result.y = dot(row(1), other);
		result.z = dot(row(2), other);

		return result;
	}

	mat3 transpose(const mat3& m) 
	{
		return mat3(m.row(0), m.row(1), m.row(2));
	}

	float determinant(const mat3& m) 
	{
		float result =
			(m[0][0] * determinant(mat2({ m[1][1], m[1][2] }, { m[2][1], m[2][2] }))) -
			(m[1][0] * determinant(mat2({ m[0][1], m[0][2] }, { m[2][1], m[2][2] }))) +
			(m[2][0] * determinant(mat2({ m[0][1], m[0][2] }, { m[1][1], m[1][2] })));

		return result;
	}

	mat3 inverse(const mat3& m) 
	{
		float dt = determinant(m);
		if (dt == 0)
			return m;

		mat3 result;

		result[0][0] = determinant(mat2({ m[1][1], m[1][2] }, { m[2][1], m[2][2] }));
		result[0][1] = -determinant(mat2({ m[1][0], m[1][2] }, { m[2][0], m[2][2] }));
		result[0][2] = determinant(mat2({ m[1][0], m[1][1] }, { m[2][0], m[2][1] }));

		result[1][0] = -determinant(mat2({ m[0][1], m[0][2] }, { m[2][1], m[2][2] }));
		result[1][1] = determinant(mat2({ m[0][0], m[0][2] }, { m[2][0], m[2][2] }));
		result[1][2] = -determinant(mat2({ m[0][0], m[0][1] }, { m[2][0], m[2][1] }));

		result[2][0] = determinant(mat2({ m[0][1], m[0][2] }, { m[1][1], m[1][2] }));
		result[2][1] = -determinant(mat2({ m[0][0], m[0][2] }, { m[1][0], m[1][2] }));
		result[2][2] = determinant(mat2({ m[0][0], m[0][1] }, { m[1][0], m[1][1] }));

		return transpose(result) * (1.0f / dt);
	}

	mat3 look_rotation(const vec3& fwd, const vec3& up) 
	{
		auto r = cross(fwd, up);
		auto u = cross(r, fwd);

		return mat3(normalize(r), normalize(u), normalize(-fwd));
	}
	
	mat4::mat4() 
	{
		m[0] = { 1, 0, 0, 0 };
		m[1] = { 0, 1, 0, 0 };
		m[2] = { 0, 0, 1, 0 };
		m[3] = { 0, 0, 0, 1 };
	}

	mat4::mat4(float all) 
	{
		m[0] = { all };
		m[1] = { all };
		m[2] = { all };
		m[3] = { all };
	}

	mat4::mat4(const vec4& a, const vec4& b, const vec4& c, const vec4& d) 
	{
		m[0] = a;
		m[1] = b;
		m[2] = c;
		m[3] = d;
	}

	mat4::mat4(const mat4& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
		m[2] = other.m[2];
		m[3] = other.m[3];
	}

	mat4::mat4(const mat2& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
		m[2] = { 0 };
		m[3] = { 0 };
	}

	mat4::mat4(const mat3& other) 
	{
		m[0] = other.m[0];
		m[1] = other.m[1];
		m[2] = other.m[2];
		m[3] = { 0, 0, 0, 1 };
	}

	mat4 mat4::operator*(const mat4& other) const 
	{
		mat4 result;

		auto row0 = row(0);
		auto row1 = row(1);
		auto row2 = row(2);
		auto row3 = row(3);

		result.m[0][0] = dot(row0, other.m[0]);
		result.m[0][1] = dot(row1, other.m[0]);
		result.m[0][2] = dot(row2, other.m[0]);
		result.m[0][3] = dot(row3, other.m[0]);

		result.m[1][0] = dot(row0, other.m[1]);
		result.m[1][1] = dot(row1, other.m[1]);
		result.m[1][2] = dot(row2, other.m[1]);
		result.m[1][3] = dot(row3, other.m[1]);

		result.m[2][0] = dot(row0, other.m[2]);
		result.m[2][1] = dot(row1, other.m[2]);
		result.m[2][2] = dot(row2, other.m[2]);
		result.m[2][3] = dot(row3, other.m[2]);

		result.m[3][0] = dot(row0, other.m[3]);
		result.m[3][1] = dot(row1, other.m[3]);
		result.m[3][2] = dot(row2, other.m[3]);
		result.m[3][3] = dot(row3, other.m[3]);

		return result;
	}

	vec4 mat4::operator*(const vec4& other) const 
	{
		vec4 result;

		result.x = dot(row(0), other);
		result.y = dot(row(1), other);
		result.z = dot(row(2), other);
		result.w = dot(row(3), other);

		return result;
	}

	mat4 transpose(const mat4& m) 
	{
		return mat4(m.row(0), m.row(1), m.row(2), m.row(3));
	}

	float determinant(const mat4& m) 
	{
		float result =
			(m[0][0] * determinant(mat3({ m[1][1], m[1][2], m[1][3] }, { m[2][1], m[2][2], m[2][3] }, { m[3][1], m[3][2], m[3][3] }))) -
			(m[1][0] * determinant(mat3({ m[0][1], m[0][2], m[0][3] }, { m[2][1], m[2][2], m[2][3] }, { m[3][1], m[3][2], m[3][3] }))) +
			(m[2][0] * determinant(mat3({ m[0][1], m[0][2], m[0][3] }, { m[1][1], m[1][2], m[1][3] }, { m[3][1], m[3][2], m[3][3] }))) -
			(m[3][0] * determinant(mat3({ m[0][1], m[0][2], m[0][3] }, { m[1][1], m[1][2], m[1][3] }, { m[2][1], m[2][2], m[2][3] })));

		return result;
	}

	mat4 inverse(const mat4& m) 
	{
		float dt = determinant(m);
		if (dt == 0)
			return m;

		mat4 result;

		result[0][0] = determinant(mat3({ m[1][1], m[1][2], m[1][3] }, { m[2][1], m[2][2], m[2][3] }, { m[3][1], m[3][2], m[3][3] }));
		result[0][1] = -determinant(mat3({ m[1][0], m[1][2], m[1][3] }, { m[2][0], m[2][2], m[2][3] }, { m[3][0], m[3][2], m[3][3] }));
		result[0][2] = determinant(mat3({ m[1][0], m[1][1], m[1][3] }, { m[2][0], m[2][1], m[2][3] }, { m[3][0], m[3][1], m[3][3] }));
		result[0][3] = -determinant(mat3({ m[1][0], m[1][1], m[1][2] }, { m[2][0], m[2][1], m[2][2] }, { m[3][0], m[3][1], m[3][2] }));

		result[1][0] = -determinant(mat3({ m[0][1], m[0][2], m[0][3] }, { m[2][1], m[2][2], m[2][3] }, { m[3][1], m[3][2], m[3][3] }));
		result[1][1] = determinant(mat3({ m[0][0], m[0][2], m[0][3] }, { m[2][0], m[2][2], m[2][3] }, { m[3][0], m[3][2], m[3][3] }));
		result[1][2] = -determinant(mat3({ m[0][0], m[0][1], m[0][3] }, { m[2][0], m[2][1], m[2][3] }, { m[3][0], m[3][1], m[3][3] }));
		result[1][3] = determinant(mat3({ m[0][0], m[0][1], m[0][2] }, { m[2][0], m[2][1], m[2][2] }, { m[3][0], m[3][1], m[3][2] }));

		result[2][0] = determinant(mat3({ m[0][1], m[0][2], m[0][3] }, { m[1][1], m[1][2], m[1][3] }, { m[3][1], m[3][2], m[3][3] }));
		result[2][1] = -determinant(mat3({ m[0][0], m[0][2], m[0][3] }, { m[1][0], m[1][2], m[1][3] }, { m[3][0], m[3][2], m[3][3] }));
		result[2][2] = determinant(mat3({ m[0][0], m[0][1], m[0][3] }, { m[1][0], m[1][1], m[1][3] }, { m[3][0], m[3][1], m[3][3] }));
		result[2][3] = -determinant(mat3({ m[0][0], m[0][1], m[0][2] }, { m[1][0], m[1][1], m[1][2] }, { m[3][0], m[3][1], m[3][2] }));

		result[3][0] = -determinant(mat3({ m[0][1], m[0][2], m[0][3] }, { m[1][1], m[1][2], m[1][3] }, { m[2][1], m[2][2], m[2][3] }));
		result[3][1] = determinant(mat3({ m[0][0], m[0][2], m[0][3] }, { m[1][0], m[1][2], m[1][3] }, { m[2][0], m[2][2], m[2][3] }));
		result[3][2] = -determinant(mat3({ m[0][0], m[0][1], m[0][3] }, { m[1][0], m[1][1], m[1][3] }, { m[2][0], m[2][1], m[2][3] }));
		result[3][3] = determinant(mat3({ m[0][0], m[0][1], m[0][2] }, { m[1][0], m[1][1], m[1][2] }, { m[2][0], m[2][1], m[2][2] }));

		return transpose(result) * (1.0f / dt);
	}

	mat4 compose(const vec3& tran, const quat& rot) 
	{
		mat4 result = mat3(rot);
		result.m[3] = { tran, 1 };

		return result;
	}

	mat4 compose(const vec3& tran, const quat& rot, const vec3& scale) 
	{
		mat4 result = mat3(rot);
		result.m[0] *= scale.x;
		result.m[1] *= scale.y;
		result.m[2] *= scale.z;
		result.m[3] = { tran, 1 };

		return result;
	}

	mat4 perspective(float fov, float aspect, float znear, float zfar) 
	{
		mat4 result;
		float f = std::tan(fov * 0.5f);

		result.m[0][0] = 1.0f / (aspect * f);
		result.m[1][1] = 1.0f / f;
		result.m[2][2] = -(zfar + znear) / (zfar - znear);
		result.m[2][3] = -1;
		result.m[3][2] = -(2 * zfar * znear) / (zfar - znear);
		result.m[3][3] = 0;

		return result;
	}

	mat4 orthographic(float left, float right, float bottom, float top, float znear, float zfar) 
	{
		mat4 result;

		result.m[0][0] = 2.0f / (right - left);
		result.m[1][1] = 2.0f / (top - bottom);
		result.m[2][2] = -2.0f / (zfar - znear);
		result.m[3][0] = -(right + left) / (right - left);
		result.m[3][1] = -(top + bottom) / (top - bottom);
		result.m[3][2] = -(zfar + znear) / (zfar - znear);
		result.m[3][3] = 1;

		return result;
	}

	mat4 look_at(const vec3& start, const vec3& end, const vec3& up) 
	{
		mat4 result = look_rotation(end - start, up);
		result.m[3] = { start, 1 };
		return result;
	}
}
