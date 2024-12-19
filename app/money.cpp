#include "money.h"
#include <iomanip>
#include <algorithm>

namespace vsite::oop::v7
{

	money::money(int _eur, int _cent) : eur(_eur), cent(_cent) {
		calculate();
	}

	void money::calculate() {
		if (cent >= 100) {
			eur += cent / 100;
			cent %= 100;
		}
		else if (cent < 0) {
			int tmp = (-cent + 99) / 100;
			eur -= tmp;
			cent += tmp * 100;
		}
	}

	int money::get_total_cents() {
		return eur * 100 + cent;
	}

	money money::operator+=(money& other) {

		this->eur += other.eur;
		this->cent += other.cent;

		calculate();

		return *this;
	}
	money money::operator-=(money& other) {

		this->eur -= other.eur;
		this->cent -= other.cent;

		calculate();

		return *this;
	}

	std::istream& operator>>(std::istream& is, money& m) {

		is >> m.eur >> m.cent;

		m.calculate();

		return is;
	}

	std::ostream& operator<<(std::ostream& os, const money& m) {
		if (m.eur) {
			os << m.eur << " eur";
		}
		if (m.eur && m.cent) {
			os << ", ";
		}
		if (m.cent) {
			os << std::setw(2) << std::setfill('0') << m.cent << " cent";
		}

		return os;
	}
}