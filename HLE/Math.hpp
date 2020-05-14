#pragma once


#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

#define M_TAU 6.2831853071795864769252867666

#define CMP_TOLERANCE 0.00001

namespace hle
{
	namespace math
	{

		template <typename T>
		T degree_to_radian(const T deg);

		template <typename T>
		T radian_to_degree(const T rad);

		template <typename T>
		T lerp(const T from, const T to, const T val);

		template <typename T>
		bool is_approx_equal(const T x, const T y);

		template<typename T>
		T step(T val, T step);

	}
}

#include "Math.inl"