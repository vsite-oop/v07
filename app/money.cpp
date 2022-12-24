#include "money.h"
#include <algorithm>

#include <sstream>  // >>
#include <format>

namespace vsite::oop::v7
{
	/*===class money===*/
	money::money(unsigned lp = 0) : lp(lp) {

	}

	money::money() : lp(0) {

	}

	money& money::operator+=(const money& other) {
		lp += other.lp;
		return *this;
	}

	money& money::operator-=(const money& other) {
		if (lp < other.lp)  // Amount of money can't be negative value.
			lp = 0;
		else
			lp -= other.lp;
		return* this;
	}

	std::istream& operator>>(std::istream& is, money& m) {
		unsigned kn;
		is >> kn >> m.lp;
		kn *= 100;
		m.lp += kn;
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const money& m) {
		unsigned kn = m.lp / 100;
		unsigned lp = m.lp % 100;
		if (lp == 0) {
			os << std::format("{} kn", kn);  // Default.
		}
		else if (kn == 0) {
			os << std::format("{:02} lp", lp);
		}
		else {
			os << std::format("{} kn, {:02} lp", kn, lp);
		}
		return os;
	}
}

/*N.B.

Ako želim imati dva data membera - kune i lipe, a želim moæi
konstruktoru predati samo jedan argument (kao što je u mainu
"money total(0)", onda ne smiju oba imati zadanu vrijednost jer onda
kompajler ne zna za kojeg želim poslati vrijednost, nego onda moram
imati jednoga, npr. kune, bez zadane vrijednosti pa dok pri pozivu
konstruktora šaljem jednu vrijednost ona æe otiæi u argument bez zadane
vrijednosti.*/
