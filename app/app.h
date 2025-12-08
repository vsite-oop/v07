#pragma once

namespace vsite::oop::v6 
{
	template<typename T>
	T minimum(T a, T b) 
	{
		return (a < b) ? a : b;
	}

	template<typename T, size_t N>
	class fixed_array {

		T data[N];

	public:
		size_t size() const {
			return N;
		}
		T& operator[](size_t index) {
			return data[index];
		}
	};

	template<typename T>
	struct point {
		T x;
		T y;
	};
}
