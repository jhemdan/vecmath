#include <vecmath/vector.hpp>
#include <vecmath/matrix.hpp>

#include <cmath>

namespace vcm
{
	const vec2 vec2::up = { 0, 1 };
	const vec2 vec2::down = { 0, -1 };
	const vec2 vec2::right = { 1, 0 };
	const vec2 vec2::left = { -1, 0 };

	vec2::vec2() : x(0), y(0) {}

	vec2::vec2(float all) : x(all), y(all) {}

	vec2::vec2(float x, float y) : x(x), y(y) {}

	vec2::vec2(const vec2& v) : x(v.x), y(v.y) {}

	vec2::vec2(const vec3& v) : x(v.x), y(v.y) {}

	vec2::vec2(const vec4& v) : x(v.x), y(v.y) {}

	float length(const vec2& v) 
	{
		return std::sqrt(v.x * v.x + v.y * v.y);
	}

	float length_squared(const vec2& v) 
	{
		return v.x * v.x + v.y * v.y;
	}

	float dot(const vec2& a, const vec2& b) 
	{
		return a.x * b.x + a.y * b.y;
	}

	vec2 normalize(const vec2& v) 
	{
		float len = length(v);
		if (len == 0)
			return v;

		return v * (1.0f / len);
	}

	vec2 clamp_length(const vec2& v, float maxLen) 
	{
		if (maxLen == 0)
			return v;

		float len = length(v);
		if (len < maxLen)
			return v;

		return v * (maxLen / len);
	}

	vec2 min(const vec2& a, const vec2& b) 
	{
		return { std::fmin(a.x, b.x), std::fmin(a.y, b.y) };
	}

	vec2 max(const vec2& a, const vec2& b) 
	{
		return { std::fmax(a.x, b.x), std::fmax(a.y, b.y) };
	}

	vec2 lerp(const vec2& a, const vec2& b, float t) 
	{
		return a + (b - a) * t;
	}

	const vec3 vec3::up = { 0, 1, 0 };
	const vec3 vec3::down = { 0, -1, 0 };
	const vec3 vec3::right = { 1, 0, 0 };
	const vec3 vec3::left = { -1, 0, 0 };
	const vec3 vec3::forward = { 0, 0, -1 };
	const vec3 vec3::back = { 0, 0, 1 };
	
	vec3::vec3() : x(0), y(0), z(0) {}

	vec3::vec3(float all) : x(all), y(all), z(all) {}

	vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {}

	vec3::vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}

	vec3::vec3(const vec2& xy, float z) : x(xy[0]), y(xy[1]), z(z) {}

	vec3::vec3(float x, const vec2& yz) : x(x), y(yz[0]), z(yz[1]) {}

	vec3::vec3(const vec2& v) : x(v.x), y(v.y), z(0) {}

	vec3::vec3(const vec4& v) : x(v.x), y(v.y), z(v.z) {}

	float length(const vec3& v) 
	{
		return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	float length_squared(const vec3& v) 
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}

	float dot(const vec3& a, const vec3& b) 
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	vec3 normalize(const vec3& v) 
	{
		float len = length(v);
		if (len == 0)
			return v;

		return v * (1.0f / len);
	}

	vec3 clamp_length(const vec3& v, float maxLen) 
	{
		if (maxLen == 0) 
			return v;

		float len = length(v);
		if (len < maxLen)
			return v;

		return v * (maxLen / len);
	}

	vec3 min(const vec3& a, const vec3& b) 
	{
		return { std::fmin(a.x, b.x), std::fmin(a.y, b.y), std::fmin(a.z, b.z) };
	}

	vec3 max(const vec3& a, const vec3& b) 
	{
		return { std::fmax(a.x, b.x), std::fmax(a.y, b.y), std::fmax(a.z, b.z) };
	}

	vec3 lerp(const vec3& a, const vec3& b, float t) 
	{
		return a + (b - a) * t;
	}

	vec3 cross(const vec3& a, const vec3& b) 
	{
		return
		{
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		};
	}

	const vec4 vec4::up = { 0, 1, 0, 0 };
	const vec4 vec4::down = { 0, -1, 0, 0 };
	const vec4 vec4::right = { 1, 0, 0, 0 };
	const vec4 vec4::left = { -1, 0, 0, 0 };
	const vec4 vec4::forward = { 0, 0, -1, 0 };
	const vec4 vec4::back = { 0, 0, 1, 0 };
	
	vec4::vec4() : x(0), y(0), z(0), w(0) {}

	vec4::vec4(float all) : x(all), y(all), z(all), w(all) {}

	vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	vec4::vec4(const vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

	vec4::vec4(const vec3& xyz, float w) : x(xyz[0]), y(xyz[1]), z(xyz[2]), w(w) {}

	vec4::vec4(float x, const vec3& yzw) : x(x), y(yzw[0]), z(yzw[1]), w(yzw[2]) {}

	vec4::vec4(const vec2& xy, const vec2& zw) : x(xy[0]), y(xy[1]), z(zw[0]), w(zw[1]) {}

	vec4::vec4(const vec2& xy, float z, float w) : x(xy[0]), y(xy[1]), z(z), w(w) {}

	vec4::vec4(float x, const vec2& yz, float w) : x(x), y(yz[0]), z(yz[1]), w(w) {}

	vec4::vec4(float x, float y, const vec2& zw) : x(x), y(y), z(zw[0]), w(zw[1]) {}

	vec4::vec4(const vec2& v) : x(v.x), y(v.y), z(0), w(0) {}

	vec4::vec4(const vec3& v) : x(v.x), y(v.y), z(v.z), w(0) {}

	vec4::vec4(const quat& q) : x(q.x), y(q.y), z(q.z), w(q.w) {}

	float length(const vec4& v) 
	{
		return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	float length_squared(const vec4& v) 
	{
		return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	}

	float dot(const vec4& a, const vec4& b) 
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	vec4 normalize(const vec4& v) {
		float len = length(v);
		if (len == 0)
			return v;

		return v * (1.0f / len);
	}

	vec4 clamp_length(const vec4& v, float maxLen) {
		if (maxLen == 0)
			return v;

		float len = length(v);
		if (len < maxLen)
			return v;

		return v * (maxLen / len);
	}

	vec4 min(const vec4& a, const vec4& b) 
	{
		return { std::fmin(a.x, b.x), std::fmin(a.y, b.y), std::fmin(a.z, b.z), std::fmin(a.w, b.w) };
	}

	vec4 max(const vec4& a, const vec4& b) 
	{
		return { std::fmax(a.x, b.x), std::fmax(a.y, b.y), std::fmax(a.z, b.z), std::fmax(a.w, b.w) };
	}

	vec4 lerp(const vec4& a, const vec4& b, float t) 
	{
		return a + (b - a) * t;
	}
	
	quat::quat() : x(0), y(0), z(0), w(1) {}

	quat::quat(float all) : x(all), y(all), z(all), w(all) {}

	quat::quat(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	quat::quat(const quat& q) : x(q.x), y(q.y), z(q.z), w(q.w) {}

	quat::quat(const vec3& xyz, float w) : x(xyz[0]), y(xyz[1]), z(xyz[2]), w(w) {}

	quat::quat(float x, const vec3& yzw) : x(x), y(yzw[0]), z(yzw[1]), w(yzw[2]) {}

	quat::quat(const vec2& xy, const vec2& zw) : x(xy[0]), y(xy[1]), z(zw[0]), w(zw[1]) {}

	quat::quat(const vec2& xy, float z, float w) : x(xy[0]), y(xy[1]), z(z), w(w) {}

	quat::quat(float x, const vec2& yz, float w) : x(x), y(yz[0]), z(yz[1]), w(w) {}

	quat::quat(float x, float y, const vec2& zw) : x(x), y(y), z(zw[0]), w(zw[1]) {}

	quat::quat(const vec2& v) : x(v.x), y(v.y), z(0), w(1) {}

	quat::quat(const vec3& v) : x(v.x), y(v.y), z(v.z), w(1) {}

	quat::quat(const vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

	quat::quat(const mat3& mat) 
	{
		float trace = mat[0][0] + mat[1][1] + mat[2][2];

		if (trace > 0) 
		{
			float s = std::sqrt(trace + 1.0f) * 2;
			w = 0.25f * s;
			x = (mat[1][2] - mat[2][1]) / s;
			y = (mat[2][0] - mat[0][2]) / s;
			z = (mat[0][1] - mat[1][0]) / s;
		}
		else if ((mat[0][0] > mat[1][1]) && (mat[0][0] > mat[2][2])) 
		{
			float s = std::sqrt(1.0f + mat[0][0] - mat[1][1] - mat[2][2]) * 2;
			w = (mat[1][2] - mat[2][1]) / s;
			x = 0.25f * s;
			y = (mat[1][0] + mat[0][1]) / s;
			z = (mat[2][0] + mat[0][2]) / s;
		}
		else if (mat[1][1] > mat[2][2]) 
		{
			float s = std::sqrt(1.0f + mat[1][1] - mat[0][0] - mat[2][2]) * 2;
			w = (mat[2][0] - mat[0][2]) / s;
			x = (mat[1][0] + mat[0][1]) / s;
			y = 0.25f * s;
			z = (mat[2][1] + mat[1][2]) / s;
		}
		else {
			float s = std::sqrt(1.0f + mat[2][2] - mat[0][0] - mat[1][1]) * 2;
			w = (mat[0][1] - mat[1][0]) / s;
			x = (mat[2][0] + mat[0][2]) / s;
			y = (mat[2][1] + mat[1][2]) / s;
			z = 0.25f * s;
		}
	}

	float length(const quat& v) 
	{
		return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	float length_squared(const quat& v) 
	{
		return v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w;
	}

	float dot(const quat& a, const quat& b) 
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	quat normalize(const quat& v) 
	{
		float len = length(v);
		if (len == 0)
			return v;

		return v * (1.0f / len);
	}

	quat inverse(const quat& q) 
	{
		return quat(-q.x, -q.y, -q.z, q.w);
	}

	quat lerp(const quat& a, const quat& b, float t) 
	{
		return normalize(a * (1.0f - t) + b * t);
	}

	quat slerp(const quat& a, const quat& b, float t) 
	{
		if (t <= 0)
			return a;

		quat c;
		float d = dot(a, b);

		if (d < 0) 
		{
			d = -d;
			c = -b;
		}
		else 
		{
			c = b;
		}

		if (t >= 1)
			return c;

		//so we don't get a divide by zero error from sin(1)
		if (d > 0.995f) 
		{
			return lerp(a, c, t);
		}

		float angle = std::acos(d);
		return normalize((a * std::sin(angle * (1 - t)) + c * std::sin(angle * t)) * (1 / std::sin(angle)));
	}

	quat angle_axis(float angle, const vec3& axis) 
	{
		float a = angle * 0.5f;

		quat result = 
		{
			axis * std::sin(a),
			std::cos(a)
		};

		return normalize(result);
	}

	quat euler(const vec3& e) 
	{
		float hx = e.x * 0.5f;
		float hy = e.y * 0.5f;
		float hz = e.z * 0.5f;

		float c1 = std::cos(hy);
		float c2 = std::cos(hz);
		float c3 = std::cos(hx);

		float s1 = std::sin(hy);
		float s2 = std::sin(hz);
		float s3 = std::sin(hx);

		quat result = 
		{
			s1 * s2 * c3 + c1 * c2 * s3,
			s1 * c2 * c3 + c1 * s2 * s3,
			c1 * s2 * c3 - s1 * c2 * s3,
			c1 * c2 * c3 - s1 * s2 * s3
		};

		return normalize(result);
	}
}
