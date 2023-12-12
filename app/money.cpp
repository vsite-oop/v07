#include "money.h"
#include <algorithm>

namespace vsite::oop::v7
{
	money::money(int eur, int ct) {
		if (eur >= 0) {
			centi = eur * 100 + ct;
		}
		else {
			centi = eur * 100 + ct * -1;
		}
	}
	money::money(const money& other) {
		centi = other.centi;
	}
	int money::getEuro() const {
		return centi / 100;
	}
	int money::getCenti() const {
		return centi % 100;
	}
	std::istream& operator>>(std::istream& input, money& m) {
		int eur;
		int ct;
		input >> eur >> ct;
		m = money(eur, ct);
		return input;
	}
	std::ostream& operator<<(std::ostream& output, const money& m) {
		auto eur = m.getEuro();
		auto ct = m.getCenti();
		if (eur != 0) {
			output << eur << " Eura";
			if (ct != 0) {
				output << ", ";
			}
		}
		if (ct != 0) {
			output << ct << " centi";
		}
		if (eur == 0 && ct == 0) {
			output << "0 Eura, 0 centi";
		}
		return output;
	}
	money& money::operator+=(const money& other) {
		centi += other.centi;
		return *this;
	}

	money& money::operator-=(const money& other) {
		centi -= other.centi;
		return *this;
	}
}