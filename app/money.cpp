#include "money.h"
#include <algorithm>
#include <format>

namespace vsite::oop::v7
{
	int money::getKune() const {
		return totalMoney / 100;
	}
	int money::getLipe() const {
		return totalMoney % 100;
	}
	money money::operator- (const money& other) const{
		money result;
		result.totalMoney = totalMoney - other.totalMoney;
		return result;
	}
	money& money::operator-= (const money& other) {
		totalMoney -= other.totalMoney;
		return *this;
	}
	money money::operator+ (const money& other) const{
		money result;
		result.totalMoney = totalMoney + other.totalMoney;
		return result;
	}
	money& money::operator+= (const money& other) {
		totalMoney += other.totalMoney;
		return *this;
	}
	std::ostream& operator<< (std::ostream& os, const money& m) {
		if (m.getKune() == 0) return os << std::format("{:02d} lp", m.getLipe());
		if (m.getLipe() == 0) return os << std::format("{:02d} kn", m.getKune());
		return os << std::format("{:02d} kn, {:02d} lp", m.getKune(), m.getLipe());
	}
	std::istream& operator>> (std::istream& is, money& m) {
		int kn, lp;
		is >> kn >> lp;
		m.totalMoney = kn * 100 + lp;
		return is;
	}
}