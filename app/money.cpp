#include "money.h"
#include <algorithm>

#include <sstream>  // bez ovoga mi javlja grešku za operator >> u liniji 28
#include <format>

namespace vsite::oop::v7
{
	/*===class money===*/
	money::money(int lp = 0) : lp(lp) {

	}

	money::money() : lp(0) {

	}

	int money::get() {
		return lp;
	}

	money& money::operator+=(const money& other) {
		lp += other.lp;
		return *this;
	}

	money& money::operator-=(const money& other) {
		lp -= other.lp;
		return* this;
	}

	std::istream& operator>>(std::istream& is, money& m) {
		int kn;
		is >> kn >> m.lp;
		kn *= 100;
		m.lp += kn;
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const money& m) {
		int kn = m.lp / 100;
		int lp = m.lp % 100;
		os << std::format("{} kn, {:02} lp", kn, lp);
		return os;
	}
}
