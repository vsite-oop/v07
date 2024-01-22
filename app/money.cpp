#include "money.h"
#include <algorithm>
#include<iostream>
#include<iomanip>
namespace vsite::oop::v7
{

	money& money::operator+= (const money& m) {
		total += m.total;
		return *this;
	}


	money& money::operator-= (const money& m) {
		total -= m.total;
		return *this;
	}

	money::money(int euri, int centi) {
		total = (euri * 100) + centi;
	}


	std::istream& operator >> (std::istream& is, money& m) {
		int euri; int centi;
		is >> euri >> centi;
		m.total = euri * 100 + centi;
		return is;
	}

	std::ostream& operator << (std::ostream& os, const money& m) {
		int euri; int centi;
		euri = m.total / 100;
		centi = m.total % 100;
		if (centi == 0) {
			os << euri << " E.";
			return os;
		}
		else if (euri == 0)
		{
			os << centi << " c.";
			return os;
		}
		else {
			os << euri << " E i " << centi << " c.";
			return os;
		}
	}
}
