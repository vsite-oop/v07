#pragma once

#include<iostream>

namespace vsite::oop::v7
{

	class money {
	private:
		int kn;
		int lp;

	public:
		money(int kn = 0, int lp = 0);

		friend std::istream& operator>> (std::istream&, money&);
		friend std::ostream& operator<< (std::ostream&, const money&);

		money& operator+= (const money&);
		money& operator-= (const money&);

		int kune() const;
		int lipe() const;
	};

}