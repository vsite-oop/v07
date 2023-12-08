#pragma once
#include <iostream>

namespace vsite::oop::v7 
{
	double operator ""_EUR(unsigned long long price);
	double operator ""_USD(unsigned long long price);
	class money {
		int kn = 0;
		int lp = 0;
		void checkflow();
		double get_price() const;

	public:
		money();
		money(int kuna, int lipa = 0);
		int get_kn() const;
		int get_lp() const;
		money& operator +=(const money& m);
		money& operator -=(const money& m);
		friend std::istream& operator>> (std::istream& is, money& m);
		friend std::ostream& operator<< (std::ostream& os, const money& m);
		double to_eur() const;
		double to_usd() const;
	};
	


}
