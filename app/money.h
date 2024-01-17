#pragma once
#include <ostream>
#include <istream>

namespace vsite::oop::v7 
{
	class money {
		int totalMoney;
	public:
		money(int kune = 0, int lipe = 0) : totalMoney(kune * 100 + lipe) {}
		int getKune() const;
		int getLipe() const;
		money operator-(const money& other) const;
		money& operator-= (const money& other);
		money operator+(const money& other) const;
		money& operator+= (const money& other);
		friend std::ostream& operator<< (std::ostream& os, const money& other);
		friend std::istream& operator>> (std::istream& is, money& other);
	};
}