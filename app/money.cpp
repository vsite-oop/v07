#include "money.h"
#include <algorithm>
#include<math.h>

namespace vsite::oop::v7
{
	money::money(int e, int c) {
		eur = e;
		cent = c;
		if (cent > 100)	money::overflow();
		if (cent < 0)	money::underflow();
	}

	money& money::operator+=(const money& other) {
		eur += other.eur;
		cent += other.cent;
		if (cent > 100) {
			money::overflow();
		}
		return *this;
	}
	money& money::operator-=(const money& other) {
		eur -= other.eur;
		cent -= other.cent;
		if (cent < 0) {
			money::underflow();
		}
		return *this;
	}


	std::istream& operator>>(std::istream& input, money& m) {
		int e, c;
		input >> e >> c;
		m.eur = e;
		m.cent = c;
		return input;
	}

	std::ostream& operator<<(std::ostream& output, const money& m) {
		output << m.eur << " eur, " << m.cent << " cent";
		return output;
	}

	void money::overflow() {
		uint32_t a = cent / 100;
		eur += a;
		cent %= 100;
	}

	void money::underflow() {
		if (cent > -100) {
			cent = abs(cent);
		}
		else {
			int a = cent / 100;
			eur += a;
			cent -= a * 100;
		}
	}




}