#include "money.h"
#include <algorithm>
//#include <format>

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
		m.centi = (eur * 100) + ct;
		return input;
	}
	std::ostream& operator<<(std::ostream& output, const money& m) {
		auto eur = m.centi / 100;
		auto ct = m.centi % 100;
		if (eur != 0) {
			output << eur << " Eura";
			if (ct != 0) {
				output << ',';
			}
		}
		if (ct != 0) {
			if (eur <= 0 && ct > 0) {
				output << abs(ct) << " centi";
			}
			else if (eur == 0 && ct < 0) {
				output << ct << " centi";
			}
			else if (eur < 0 && ct < 0) {
				output << abs(ct) << " centi";
			}
			else {
				output << ct << " centi";
			}
		}
		if (eur == 0 && ct == 0) {
			output << eur << " Eura" << ct << " centi";
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