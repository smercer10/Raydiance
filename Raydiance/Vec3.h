#pragma once

#include <cmath>
#include <iostream>

using std::sqrt;

class Vec3
{
public:
	double e[3];

	Vec3() : e{ 0, 0, 0 } {}
	Vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	// Unary minus
	Vec3 operator-() const { return { -e[0], -e[1], -e[2] }; }

	// Read-only access to const vector elements
	double operator[](int i) const { return e[i]; }

	// Read/write access to non-const vector elements
	double& operator[](int i) { return e[i]; }

	Vec3 operator+=(const Vec3& v)
	{
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];

		return *this;
	}

	Vec3 operator*=(const double t)
	{
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;

		return *this;
	}

	Vec3 operator/=(const double t)
	{
		return *this *= 1 / t;
	}

	double length_squared() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	double length() const
	{
		return sqrt(length_squared());
	}
};

// Type alises
using Point3 = Vec3;
using Color = Vec3;

// Write to output stream in ppm format
inline std::ostream& operator<<(std::ostream& out, const Vec3& v)
{
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v)
{
	return { u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2] };
}

inline Vec3 operator-(const Vec3& u, const Vec3& v)
{
	return { u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2] };
}

// Hadamard product
inline Vec3 operator*(const Vec3& u, const Vec3& v)
{
	return { u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2] };
}

// Scalar * vector
inline Vec3 operator*(double t, const Vec3& v)
{
	return { t * v.e[0], t * v.e[1], t * v.e[2] };
}

// Vector * scalar
inline Vec3 operator*(const Vec3& v, double t)
{
	return t * v; // Reuse scalar * vector overload
}

inline Vec3 operator/(Vec3 v, double t)
{
	return (1 / t) * v; // Reuse scalar * vector overload
}

inline double dot(const Vec3& u, const Vec3& v)
{
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline Vec3 cross(const Vec3& u, const Vec3& v)
{
	return {
		u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]
	};
}

inline Vec3 unit_vector(Vec3 v)
{
	return v / v.length();
}
