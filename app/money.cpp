#include "money.h"
#include <algorithm>
#include <iomanip>
#include <format>

namespace vsite::oop::v7
{
	money::money() :kn(0), lp(0) {};

	money::money(int a) :kn(a), lp(0) {};

	money::money(int a, int b) :kn(a), lp(b) {};

	money::money(double a) :kn(int(a)), lp((a - kn) * 100) {};

	money::~money() {};

	money::operator double() {
		return kn + double(lp) / 100;
	}

	money& money::operator+(double a) {
		double temp = double(kn) + double(lp) / 100;
		temp += a;
		kn = int(temp);
		lp = (temp - kn) * 100;
		if (lp > 99) {
			lp -= 100;
			++kn;
		}
		return *this;
	};

	money& money::operator+=(double a) {
		double temp = double(kn) + double(lp) / 100;
		temp += a;
		kn = int(temp);
		lp = (temp - kn) * 100;
		if (lp > 99) {
			lp -= 100;
			++kn;
		}
		return *this;
	};

	money& money::operator-(double a) {
		double temp = double(kn) + double(lp) / 100;
		temp -= a;
		kn = int(temp);
		lp = (temp - kn) * 100;
		if (lp < 0) {
			lp += 100;
			--kn;
		}
		if (kn < 0) {
			kn = 0;
			lp = 0;
		}
		return *this;
	};

	money& money::operator-=(double a) {
		double temp = double(kn) + double(lp) / 100;
		temp -= a;
		kn = int(temp);
		lp = (temp - kn) * 100;
		if (lp < 0) {
			lp += 100;
			--kn;
		}
		if (kn < 0) {
			kn = 0;
			lp = 0;
		}
		return *this;
	}

	money& money::operator+(const money& other) {
		kn += other.kn;
		lp += other.lp;
		if (lp > 99) {
			lp -= 100;
			++kn;
		}
		return *this;
	}

	money& money::operator+=(const money& other) {
		kn += other.kn;
		lp += other.lp;
		if (lp > 99) {
			lp -= 100;
			++kn;
		}
		return *this;
	};

	money& money::operator-(const money& other) {
		kn -= other.kn;
		lp -= other.lp;
		if (lp < 0) {
			lp += 100;
			--kn;
		}
		if (kn < 0) {
			kn = 0;
			lp = 0;
		}
		return *this;
	}

	money& money::operator-=(const money& other) {
		kn -= other.kn;
		lp -= other.lp;
		if (lp < 0) {
			lp += 100;
			--kn;
		}
		if (kn < 0) {
			kn = 0;
			lp = 0;
		}
		return *this;
	};

	std::string money::toString() {
		if (lp == 0) {
			return std::format("{:02} kn", kn);
		}
		if (kn == 0) {
			return std::format("{:02} lp", lp);
		}
		return std::format("{:02} kn, {:02} lp", kn, lp);
	}

	std::istream& operator>>(std::istream& is, money& m) {
		is >> m.kn >> m.lp;
		return is;
	}

	std::ostream& operator<< (std::ostream& os, const money& m) {
		if (m.lp == 0) {
			os << std::setw(2) << std::setfill('0') << m.kn << " kn";
		}
		else if (m.kn == 0) {
			os << std::setw(2) << std::setfill('0') << m.lp << " lp";
		}
		else {
			os << std::setw(2) << std::setfill('0') << m.kn << " kn, " << std::setw(2) << std::setfill('0') << m.lp << " lp";
		}
		return os;
	}


}