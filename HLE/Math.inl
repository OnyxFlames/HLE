#pragma once

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
			return rad * M_PI / static_cast<T>(180.0);
		}

		template<typename T>
		inline T lerp(const T from, const T to, const T val)
		{
			return from + (to - from) * val;
		}

		template<typename T>
		inline bool is_approx_equal(const T x, const T y)
		{
			if (x == y)
				return true;

			const T tolerance = std::abs(x) * CMP_TOLERANCE;

			if (tolerance < CMP_TOLERANCE)
				tolerance = CMP_TOLERANCE;

			return abs(x - y) < tolerance;
		}

		template<typename T>
		inline T step(T val, T step)
		{
			if (step != 0)
				val = std::floor(val / step + static_cast<T>(0.5)) * step;
			return val;
		}

	}
}