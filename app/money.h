#pragma once
#include <iostream>

namespace vsite::oop::v7
{

	class money {
	public:
		money() : eur(0), cent(0) {}
		money(int eur): eur(eur), cent(0) {}
		money(int eur, int cent);
		~money() = default;

		void calculate();
		double get_total_amount();

		money operator+=(money& other);
		money operator-=(money& other);

		friend std::istream& operator>>(std::istream& is, money& m);
		friend std::ostream& operator<<(std::ostream& os, const money& m);

	private:
		int eur;
		int cent;
	};

}
