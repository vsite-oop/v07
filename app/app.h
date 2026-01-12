#pragma once
#include <cstddef>
#include <type_traits>

namespace vsite::oop::v6
{
	template <typename T>
	T minimum(T a, T b)
	{
		return (a < b) ? a : b;
	};

	template <typename T, std::size_t N>
	class fixed_array
	{
		T arr[N];

	public:
		constexpr std::size_t size() const
		{
			return N;
		}

		T operator[](std::size_t index) const
		{
			return arr[index];
		}
	};

	template <typename T>
	struct point {
		T x;
		T y;
	};
}