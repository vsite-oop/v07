#include "money.h"
#include <iostream>
#include <format>

namespace vsite::oop::v7
{
	money::money(int kn, int lp){
		if (kn >= 0) {
			lipe = kn * 100 + lp;
		}
		else if (kn < 0) {
			lipe = kn * 100 + lp * -1;
		}
	}

	money::money(const money& other){
		lipe = other.lipe;
	}

	int money::get_kune() const
	{
		return lipe / 100;
	}

	int money::get_lipe() const
	{
		return lipe % 100;
	}

	std::istream& operator>>(std::istream& input, money& m)
	{
		int kn, lp;
		input >> kn >> lp;
		m.lipe = (kn * 100) + lp;
		return input;
	}

	std::ostream& operator<<(std::ostream& output, const money& m)
	{
		auto kn = m.lipe / 100;
		auto lp = m.lipe % 100;
		if (kn != 0) {
			output << kn << " kn";
		}
		if (kn != 0 && lp != 0)
		{
			output << ", ";
		}
		if (lp != 0) {
			if (kn <= 0 && lp > 0)
				output << abs(lp) << " lp";
			else if (kn == 0 && lp < 0)
				output << lp << " lp";
			else if (kn < 0 && lp < 0)
				output << abs(lp) << " lp";
			else
				output << lp << " lp";
		}
		if (kn == 0 && lp == 0) {
			output << kn << " kn, " << lp << " lp";
		}
		return output;
	}

	money& money::operator+=(const money& other)
	{
		lipe += other.lipe;
		return *this;
	}

	money& money::operator-=(const money& other)
	{
		lipe -= other.lipe;
		return *this;
	}
}