#include "money.h"
#include <algorithm>
#include<math.h>

namespace vsite::oop::v7
{
		money::money(int e,  int c) {
		eur = e;
		cent = c;
		if (cent > 100)	money::overflow();
		if (cent < -100)	money::underflow();
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
		cent += eur * 100;
		eur = 0;
		cent -= other.cent;
		cent -= (other.eur * 100);
		eur = cent / 100;
		cent %= 100;
		if (cent < 0) {
			money::underflow();
		}
		return *this;
	}


	std::istream& operator>>(std::istream& input, money& m) {
		input >> m.eur >> m.cent;
		return input;
	}

	std::ostream& operator<<(std::ostream& output, const money& m) {
		if (m.eur != 0) {
			output << m.eur << " eur";
			if (m.cent != 0) {
				output << ", " << m.cent << " cent";
			}
			return output;
		}
		if (m.cent != 0) {
			output << m.cent << " cent";
		}
		return output;
	}

	void money::overflow() {
		uint32_t a = cent / 100;
		eur += a;
		cent %= 100;
	}

	void money::underflow() {
			int a = cent / 100;
			eur += a;
			cent -= a * 100;
			if(cent<0 && eur>0){
				eur -= 1;
				cent += 100;
			}
			else if (cent < 0 && eur < 0) {
				cent = abs(cent);
			}

	}




}