#pragma once

namespace vsite::oop::v6 
{
	template <typename T>
	T minimum(T a, T b)
	{
		if (a < b) return a;
		return b;	
	}

	template <typename T, int SIZE>
	class fixed_array {
		T arr[SIZE];
	public:
		size_t size() const {
			return SIZE;
		}

		T& operator [] (size_t i) {
			return arr[i];
		}
	};

	template <typename T>
	struct point {
		T x;
		T y;
	};
}
