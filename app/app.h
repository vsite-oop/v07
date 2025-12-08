#pragma once

namespace vsite::oop::v6 
{
	template <typename V>
	V minimum(const V& a, const V& b) {
		return (a < b) ? a : b;
	} // u testu je ""s pa znamo da radimo sa stringovima, nema potrebe za char* slucaj



	template <typename T,size_t N> // T -> type, N -> kolicina
	class fixed_array {
		private:
			T arr[N];
	public:
		unsigned long long size() const {
			return N;
		}
		T& operator[](const size_t index) {
			return arr[index];
		}

	};


	// UserDefined type da produ testovi
	template<typename T>
	struct point {
		T x{}, y{};
	};

}