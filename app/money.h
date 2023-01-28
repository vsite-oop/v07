#pragma once
#include <iostream>

namespace vsite::oop::v7
{

	class money {
		int kn;
		int lp;
		friend std::istream& operator>>(std::istream&, money&);
		friend std::ostream& operator<< (std::ostream& os, money& a);
	public:
		money(int a = 0, int b = 0);
		money(double a);
		~money();
		operator double();
		money& operator+(const money& other);
		money& operator-(const money& other);
		money& operator+=(const money& other);
		money& operator-=(const money& other);
		std::string toString();
	};

}
