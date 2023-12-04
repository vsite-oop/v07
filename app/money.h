#pragma once
#include <memory>
#include <istream>

namespace vsite::oop::v7 
{


class money {
	std::string handleOverflow();
	std::string handleUnderflow();
	int eur;
	int cnt;
public:
	money(int  e = 0, int c = 0);
	friend std::istream& operator >>(std::istream& s, money& m);
	money& operator +=(const money& rhs);
	money& operator -=(const money& rhs);
	friend std::ostream& operator <<(std::ostream&, money m);
	std::string ispis();
	int e();
	int c();

};

}
