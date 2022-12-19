#include "money.h"
#include <iostream>
#include <format>

namespace vsite::oop::v7
{
	money::money(int kune, int lipe) :
		lipe(kune * 100 + lipe) { }

	money::money(const money& other) :
		lipe(other.lipe) { }

	int money::get_kune() const
	{
		return lipe / 100;
	}

	int money::get_lipe() const
	{
		return lipe % 100;
	}

	std::istream& operator>>(std::istream& input_stream, money& money)
	{
		int kune;
		int lipe;

		input_stream >> kune;
		input_stream >> lipe;

		money.lipe = kune * 100 + lipe;

		return input_stream;
	}

	std::ostream& operator<<(std::ostream& output_stream, const money& money)
	{
		int out_kune = money.lipe / 100;
		int out_lipe = money.lipe % 100;

		if (out_kune)
			output_stream << out_kune << " kn";

		if (out_kune && out_lipe)
			output_stream << ", ";

		if (out_lipe)
			output_stream << std::format("{:0>2} lp", out_lipe);

		return output_stream;
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