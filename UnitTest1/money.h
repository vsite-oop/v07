#pragma once
#include <iostream>

namespace vsite::oop::v7 
{

	class money {
		int centi;
		friend std::istream& operator>>(std::istream&, money&);
		friend std::ostream& operator<<(std::ostream&, const money&);
	public:
		money(int euro = 0, int centi = 0);
		money(const money& other);

		int	getEuro() const;
		int getCenti() const;

		money& operator+=(const money& other);
		money& operator-=(const money& other);
		~money() = default;
};

}
