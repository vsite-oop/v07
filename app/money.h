#pragma once
#include <iostream>

namespace vsite::oop::v7
{

	class money {
		int kn;
		int lp;
		friend std::istream& operator>>(std::istream&, money&);
		friend std::ostream& operator<< (std::ostream& os, const money& a);
	public:
		money();
		money(int a);
		money(int a, int b);
		money(double a);
		~money();
		operator double();
		money& operator+(double a);
		money& operator+=(double a);
		money& operator-(double a);
		money& operator-=(double a);
		money& operator+(const money& other);
		money& operator-(const money& other);
		money& operator+=(const money& other);
		money& operator-=(const money& other);
		std::string toString();
	};

}
