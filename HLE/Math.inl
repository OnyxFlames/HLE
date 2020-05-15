#include "Math.hpp"
#pragma once

#include <algorithm>

namespace hle
{
	namespace math
	{
		template<typename T>
		inline T degree_to_radian(const T deg)
		{
			return deg * M_PI / static_cast<T>(180.0);
		}

		template<typename T>
		inline T radian_to_degree(const T rad)
		{
			return rad * static_cast<T>(180.0) / M_PI;
		}

		template<typename T>
		T clamp(const T val, const T min, const T max)
		{
			return (val < min) ? min : (max < val) ? max : val;
		}

		template<typename T>
		inline T lerp(const T from, const T to, const T val)
		{
			return from + (to - from) * val;
		}

		template<typename T>
		inline T lerp_angle(const T from, const T to, const T val)
		{
			const T diff = std::fmod(to - from, static_cast<T>(M_TAU));
			const T dist = std::fmod(static_cast<T>(2.0) * diff, M_TAU) - diff;
			return from + dist * val;
		}

		template<typename T>
		inline bool is_approx_equal(const T x, const T y)
		{
			if (x == y)
				return true;

			T tolerance = static_cast<T>(std::fabs(static_cast<T>(x))) * static_cast<T>(CMP_TOLERANCE);

			if (tolerance < CMP_TOLERANCE)
				tolerance = static_cast<T>(CMP_TOLERANCE);

			return std::fabs(x - y) < tolerance;
		}

		template<typename T>
		inline T step(T val, T step)
		{
			if (step != 0)
				val = std::floor(val / step + static_cast<T>(0.5)) * step;
			return val;
		}

		template<typename T>
		inline T smoothstep(T from, T to, T val)
		{
			if (is_approx_equal(from, to))
				return from;

			T x = clamp((val - from) / (to - from), static_cast<T>(0), static_cast<T>(1));

			return x * x * (static_cast<T>(3.0) - static_cast<T>(2.0) * x);
		}
	}
}