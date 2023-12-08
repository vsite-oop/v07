#include "money.h"
#include <algorithm>

namespace vsite::oop::v7
{
	double operator ""_EUR(unsigned long long price) {
		return price / 7.53;
	}

	double operator ""_USD(unsigned long long price) {
		return price / 6.98;
	}

	money::money(int kuna, int lipa) : kn(kuna), lp(lipa) {
		money::checkflow();
	}

	int money::get_kn() const{
		return kn;
	}

	int money::get_lp() const{
		return lp;
	}

	void money::checkflow() {
		kn += lp < 0 ? -1 - lp / 100 : lp / 100;
		lp = lp < 0 ? 100 + lp % 100 : lp % 100;
	}

	double money::get_price() const {
		return (kn * 100 + lp) / 100.;
	}

	money& money::operator +=(const money& m) {
		kn += m.kn;
		lp += m.lp;
		money::checkflow();
		return *this;
	}

	money& money::operator -=(const money& m) {
		kn -= m.kn;
		lp -= m.lp;
		money::checkflow();
		return *this;
	}

	std::istream& operator>> (std::istream& is, money& m) {
		is >> m.kn >> m.lp;
		return is;
	}

	std::ostream& operator<< (std::ostream& os, const money& m) {
		int kn = m.kn;
		int lp = m.lp;
		if (lp == 0) {
			os << kn << " kn";
		}else if (kn == 0) {
			os << lp  << " lp";
		}else {
			os << kn << " kn, " << lp << " lp";
		}
		return os;
	}

	double money::to_eur() const {
		return money::get_price() * 1_EUR;
	}

	double money::to_usd() const {
		return money::get_price() * 1_USD;
	}
};